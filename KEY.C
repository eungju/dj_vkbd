
#include <stdio.h>
#include <conio.h>
#include "DJ_VKBD.H"
#include "../ptools.h"
#include "vktype.h"

#define VER_ID  "0003.512"

main()
{
    virtual_key_dataRec vk;
    char *Scrn;
    int tmp = 0;

    kbdInit();
    printf("********************************** *****  ***   ***   **    *\n");
    printf("Multi-keypress demonstration:\n");
    printf("    This demonstrates the ability to track multiple keys being\n");
    printf("    pressed at the same time.  Occasionally a key might stick\n");
    printf("    on the top of the screen.  This occurs when the keyboard\n");
    printf("    ISR does not receive the keyrelease code from the I/O port.\n\n");
    printf("Press several keys at once . . .\n\n");
    printf("NOTE:  LEFT_SHIFT-ALT-CTRL will go to next section.\n");
        Scrn=(char *)0xE00B8000;
        while (!(kbdKeyIs(NK_LeftShift) &&
                (kbdKeyIs(NK_LeftAlt) || kbdKeyIs(NK_RightAlt)) &&
                (kbdKeyIs(NK_LeftCtrl) || kbdKeyIs(NK_RightCtrl)))
                )
        {
            for (tmp=0; tmp<=0xd3; tmp++)
            {
                Scrn[tmp*2]=tmp;
                Scrn[tmp*2+1]=kbdFLAGS[tmp];
                kbdKeyClr(tmp);
            }
        }
    kbdClearKeys();
    kbdSetMode(00);
        kbdKeyClr(NK_ESC);
        while (!kbdKeyWas(NK_ESC))
        {
            while (!kbdKeyHit());
            vk = kbdGetKey();
            printf("%x\t %x\n",vk.h.modifier_state, vk.h.vkey_code); fflush(stdout);
        }
    kbdReset();
    return  0;
}
