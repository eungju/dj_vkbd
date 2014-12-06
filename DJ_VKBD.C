#include <pc.h>
#include <dpmi.h>
#include "../ptools.h"
#include "keycodes.h"
#include "dj_vkbd.h"
#include "vktype.h"

/* Typical EQUates for easier to read code */

#define ON          1                   /* Boolean EQUates for easier to */
#define OFF         0                   /* : follow code */
#define TRUE        1
#define FALSE       0
#define true        1
#define false       0

/* Keyboard SCAN Code & Table OFFSET EQUates */

typedef union modifier_stateObj {
    struct {
        word    right_shift : 1; /* µ¡Ÿe½¢ ®áÏaËa ’‰Ÿ± */
        word    left_shift  : 1; /* ¶E½¢ ®áÏaËa ’‰Ÿ±   */
        word    right_ctrl  : 1; /* µ¡Ÿe½¢ Å¥Ëa© ’‰Ÿ± */
        word    left_ctrl   : 1; /* ¶E½¢ Å¥Ëa© ’‰Ÿ±   */
        word    right_alt   : 1; /* µ¡Ÿe½¢ ´iËa ’‰Ÿ±   */
        word    left_alt    : 1; /* ¶E½¢ ´iËa ’‰Ÿ±     */
        word    caps_lock   : 1; /* Caps Lock ¸b•·     */
        word    num_lock    : 1; /* Num Lock ¸b•·      */
    } i;
    byte modifier_state;
} modifier_stateRec;

/* Keyboard Tables & Buffers */

    /* Miscellaneous Toggles & Data Variables */
    modifier_stateRec kbdMS;
    char kbdLights = OFF;           /*
                                    Keyboard Lights Bitfield:
                                    0000 000x Scroll Lock Light
                                    0000 00x0 Number Lock Light
                                    0000 0x00 Caps Lock Light
                                    xxxx x000 RESERVED
                                    */

    char kbdDelay = 0;              /* Typematic Delay */
    char kbdRate = 0;               /* Typematic Rate */

    /* Buffer and Flag Variables & Tables */

    char KeyFlags[256];             /* Doesn't need to be this big, but . . . */
    char *kbdFLAGS = KeyFlags;

    byte KeyTail = 0;               /* Keyboard buffer Tail (duh!) */
    byte KeyHead = 0;               /* Keyboard buffer Head (really?) */
    virtual_key_dataRec KeyBuffer[256]; /* Keyboard buffer (shock to the system) */

    int KeyMode = 0x00;            /* Keystroke Conversion
                                    */

    int KeyExtFlag = OFF;          /* Extended Keystroke Flag */
    /* Variables set by kbdInit() */

    int KeyboardInstalled = false; /* Keyboard ISR Installed Flag */
    _go32_dpmi_seginfo ISR_Old;     /* Old Vector Address */
    _go32_dpmi_seginfo ISR_New;
    _go32_dpmi_registers regs;

    _go32_dpmi_seginfo pm_ISR_Old;
    _go32_dpmi_seginfo pm_ISR_New;
    int count;

/* =========================================================================
    PUBLIC  kbdInit_, kbdReset_             ;; Init/Reset Keyboard handler
    PUBLIC  kbdKeyHit_                      ;; Get Buffer Info
    PUBLIC  kbdClearKeys_                   ;; Flush the I/O Buffer
    PUBLIC  kbdGetKey_, kbdPutKey_          ;; I/O with Buffer
    PUBLIC  kbdGetMode_, kbdSetMode_        ;; Buffer Mode [CONVERT/ABSOLUTE]
    PUBLIC  kbdSetNumLight_;, kbdSetNumMode  ;; Set up NUM LOCK status
    PUBLIC  kbdSetCapLight_;, kbdSetCapMode  ;; Set up CAP LOCK status
    PUBLIC  kbdSetScrlLight_;, kbdSetScrlMode;; Set up SCROLL LOCK status
    PUBLIC  kbdSetRate_                     ;; Set Typematic Rate
   ========================================================================= */

/* *************************************************************************
   kbdSetRate(char DELAY, char RATE)
   Pass:    DELAY   : (DELAY+1)*250 in milliseconds
            RATE    : (8+RATE&0x07)*(2^RATE&0x18)*4.17 in milliseconds
   ************************************************************************* */

void kbdSetRate(int DELAY, int RATE)
{
    outportb (0x60, 0xf3);          /* Send Set Typematic Rate/Delay Command
                                       to the 8042 */
    kbdDelay = (char)(DELAY & 0x03);        /* Clear all but the DELAY bits */
    kbdRate = (char)(RATE & 0x1f);          /* Clear all but the DELAY bits */

    while (inportb(0x60) != 0xfa) ; /* Wait for ACK from 8042 */
    outportb(0x60, kbdDelay | kbdRate);  /* Send the new Typematic Rate */

    while (inportb(0x60) != 0xfa) ; /* Wait for ACK from 8042 */
}

/* *************************************************************************
   ¬ Ç¡¥¡—a ˆa¡À‹¡ Ðq®
   It reads the scan code from the Keyboard and modifies the flags table.

   The flag table is set as follows:
    0000 000x   Current status.  1==Pressed, 0==Released.
    0000 00x0   Prior status.  1==Pressed.  Unchanged when released.
    xxxx xx00   RESERVED
   ************************************************************************* */

void Keyboard_PM()
{
    int i;
    byte sys_scan, key_scan;
    byte vksc;
    virtual_key_dataRec vk;

    sys_scan = inportb(0x60);
    key_scan = sys_scan & 0x7f;

    switch (sys_scan) {
        case 0xe1 :
                        count = 2;
                        KeyExtFlag = TRUE;
                        break;
        case 0x2a :
                        if (KeyExtFlag == TRUE) {
                            count = 1;
                        }
                        break;
    }

    if (!count) {
        if (sys_scan == 0xe0) {
            KeyExtFlag = TRUE;
            outportb(0x20, 0x20);
            return;
        } else {
            if (KeyExtFlag) {
                for (i = 1; i <= 16; i++) if (key_scan == Extended[i-1]) break;
                vksc = toVirtualKeyCode[0x58 + i];
                KeyExtFlag = FALSE;
            } else {
                vksc = toVirtualKeyCode[key_scan];
            }
            if (((sys_scan & 0x80) == 0) || (sys_scan == 0xf1) || (sys_scan == 0xf2)) {
                KeyFlags[vksc] |= 0x03;
            } else {
                KeyFlags[vksc] &= 0xfe;
                outportb(0x20, 0x20);
                return;
            }
            if ((KeyHead + 1) == KeyTail) {
                outportb(0x20, 0x20);
                return;
            }
            switch (vksc) {
                case NK_NumLock :
                                    kbdMS.i.num_lock = ~kbdMS.i.num_lock;
                                    kbdSetNumLight(kbdMS.i.num_lock);
                                    break;
                case NK_CapsLock :
                                    kbdMS.i.caps_lock = ~kbdMS.i.caps_lock;
                                    kbdSetCapLight(kbdMS.i.caps_lock);
                                    break;
                case NK_ScrollLock :
                                    kbdSetScrlLight(~(kbdLights & 0x01));
                                    break;
            }
            if (vksc == NULL) {
                outportb(0x20, 0x20);
                return;
            }
            kbdMS.i.left_alt = kbdKeyIs(NK_LeftAlt);
            kbdMS.i.right_alt = kbdKeyIs(NK_RightAlt);
            kbdMS.i.left_ctrl = kbdKeyIs(NK_LeftCtrl);
            kbdMS.i.right_ctrl = kbdKeyIs(NK_RightCtrl);
            kbdMS.i.left_shift = kbdKeyIs(NK_LeftShift);
            kbdMS.i.right_shift = kbdKeyIs(NK_RightShift);
            if (!(KeyMode & 0x01)) {
                switch(vksc) {
                    case NK_LeftAlt :
                    case NK_LeftCtrl :
                    case NK_LeftShift :
                    case NK_RightAlt :
                    case NK_RightCtrl :
                    case NK_RightShift :
                    case NK_PrintScreen :
                    case NK_ScrollLock :
                    case NK_CapsLock :
                    case NK_NumLock :   outportb(0x20, 0x20);
                                        return;
                }
            }
            KeyBuffer[KeyHead].h.modifier_state = kbdMS.modifier_state;
            KeyBuffer[KeyHead].h.vkey_code = vksc;
            KeyHead++;
        }
    } else {
        count--;
    }
    outportb(0x20, 0x20);
    return;
}

void kbdInit()
{
    /* Check to make sure new handler IS NOT installed */
    if (KeyboardInstalled == true) return;

    /* Set KeyboardInstalled flag appropriately */
    KeyboardInstalled = true;

    /* Get OLD INT 09h Vector */
    _go32_dpmi_get_real_mode_interrupt_vector(9, &ISR_Old);

    /* Set NEW INT 09h Vector */
    ISR_New.pm_offset = (int) Keyboard_PM;
    _go32_dpmi_allocate_real_mode_callback_iret(&ISR_New, &regs);
    _go32_dpmi_set_real_mode_interrupt_vector(9, &ISR_New);

    kbdLights = *((char *)0xE0000497) & 0x07;
    kbdMS.i.num_lock = (kbdLights & 0x02) >> 1 ? 1 : 0;
    kbdMS.i.caps_lock = (kbdLights & 0x04) >> 2 ? 1: 0;
    count = 0;
}

void kbdReset()
{
    /* Check to make sure new handler IS installed */
    if (KeyboardInstalled = false) return;

    /* Set KeyboardInstalled flag appropriately */
    KeyboardInstalled = false;

    /* Restore OLD INT 09h Vector */
    _go32_dpmi_set_real_mode_interrupt_vector(9, &ISR_Old);
    _go32_dpmi_free_real_mode_callback(&ISR_New);

    outportb(0x60, 0xed);
    while (inportb(0x60) != 0xfa) ;
    outportb(0x60, *((char *)0xE0000497) & 0x07);
    while (inportb(0x60) != 0xfa) ;
}

int kbdGetMode()
{
    return KeyMode;
}

void kbdSetMode(int mode)
{
    KeyMode = mode & 0x01;
}

/* *********************************************
   int      kbdKeyHit()
   RETURN:  0 if KeyBuffer is empty
            # Number of keys in buffer
   ********************************************* */
int
kbdKeyHit()
{
    /* Check to see if buffer is EMPTY */
    if (KeyHead - KeyTail) return TRUE;
    else return FALSE;
}

void
kbdClearKeys()
{
    /* Clear the buffer by setting TAIL on HEAD */
    KeyTail = KeyHead;
}

int
kbdPutKey(virtual_key_dataRec key)
{
    if ((KeyHead + 1) == KeyTail) return ERROR;     /* ¤áÌáˆa ”a Àq */
    KeyBuffer[KeyHead] = key;             /* Save the ASCII Code */
    KeyHead++;                           /* Increment the KeyHead */
    return SUCCEED;
}

virtual_key_dataRec
kbdGetKey()
{
    virtual_key_dataRec code;

    /* Check to see if buffer is EMPTY */
    while (KeyHead == KeyTail) ; /* : then the buffer is empty, so wait. */

    /* Get next key from KEYBOARD BUFFER */
    code = KeyBuffer[KeyTail];      /* Fetch the ASCII Code */
    KeyTail++;
    return code;
}

void
kbdSetNumLight(int mode)
{
    outportb(0x60, 0xed);
    kbdLights = (kbdLights & 0xfd) | ((mode << 1) & 0x02);
    while (inportb(0x60) != 0xfa) ;
    outportb(0x60, kbdLights);
    while (inportb(0x60) != 0xfa) ;
}

void
kbdSetCapLight(int mode)
{
    outportb(0x60, 0xed);
    kbdLights = (kbdLights & 0xfb) | ((mode << 2) & 0x04);
    while (inportb(0x60) != 0xfa) ;
    outportb(0x60, kbdLights);
    while (inportb(0x60) != 0xfa) ;
}

void
kbdSetScrlLight(int mode)
{
    outportb(0x60, 0xed);
    kbdLights = (kbdLights & 0xfe) | (mode & 0x01);
    while (inportb(0x60) != 0xfa) ;
    outportb(0x60, kbdLights);
    while (inportb(0x60) != 0xfa) ;
}

