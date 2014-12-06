#include "../ptools.h"
#include "vkeysym.h"

char Extended[] = {
                    0x1c,     /* ENTER    */
                    0x1d,     /* CTRL     */
                    0x35,     /* GRAY /   */
                    0x38,     /* ALT      */
                    0x47,     /* HOME     */
                    0x48,     /* UP       */
                    0x49,     /* PGUP     */
                    0x4b,     /* LEFT     */
                    0x4d,     /* RIGHT    */
                    0x4f,     /* END      */
                    0x50,     /* DOWN     */
                    0x51,     /* PGDN     */
                    0x52,     /* INS      */
                    0x53,     /* DEL      */
                    0x37,     /* PrintScreen    */
                    0x45,     /* Pause          */
                    };

                /* ASCII in SCAN order */
byte toVirtualKeyCode[] = { NK_Unknown,     /* Unknown */
                            NK_ESC,     /* ESC */
                            NK_1,     /* 1 */
                            NK_2,     /* 2 */
                            NK_3,     /* 3 */
                            NK_4,     /* 4 */
                            NK_5,     /* 5 */
                            NK_6,     /* 6 */
                            NK_7,     /* 7 */
                            NK_8,     /* 8 */
                            NK_9,     /* 9 */
                            NK_0,     /* 0 */
                            NK_Minus, /* - */
                            NK_Equal,     /* = */
                            NK_BackSpace,
                            NK_Tab,     /* TAB */
                     /*10*/ NK_Q,     /* Q */
                            NK_W,     /* W */
                            NK_E,
                            NK_R,
                            NK_T,
                            NK_Y,
                            NK_U,
                            NK_I,
                            NK_O,
                            NK_P,
                            NK_BracketLeft,
                            NK_BracketRight,
                            NK_Enter,     /* ENTER */
                            NK_LeftCtrl,     /* L_CTRL */
                            NK_A,     /* A */
                            NK_S,     /* S */
                    /*20*/  NK_D,     /* D */
                            NK_F,
                            NK_G,
                            NK_H,
                            NK_J,
                            NK_K,
                            NK_L,
                            NK_SemiColon,
                            NK_Apostrophe,
                            NK_Grave,
                            NK_LeftShift,     /* L_SHIFT */
                            NK_BackSlash,
                            NK_Z,     /* Z */
                            NK_X,     /* X */
                            NK_C,     /* C */
                            NK_V,     /* V */
                    /*30*/  NK_B,     /* B */
                            NK_N,     /* N */
                            NK_M,     /* M */
                            NK_Comma,     /* , */
                            NK_Period,     /* . */
                            NK_Slash,     /* / */
                            NK_RightShift,     /* R_SHIFT */
                            NK_KP_Aster,     /* G-* */
                            NK_LeftAlt,     /* L_ALT */
                            NK_Space,     /* SPACE */
                            NK_CapsLock,     /* CAPS */
                            NK_F1,     /* F1 */
                            NK_F2,     /* F2 */
                            NK_F3,     /* F3 */
                            NK_F4,     /* F4 */
                            NK_F5,     /* F5 */
                     /*40*/ NK_F6,     /* F6 */
                            NK_F7,     /* F7 */
                            NK_F8,     /* F8 */
                            NK_F9,     /* F9 */
                            NK_F10,     /* F10 */
                            NK_NumLock,     /* NUM */
                            NK_ScrollLock,     /* SCRL */
                            NK_KP_7,     /* 7 */
                            NK_KP_8,     /* 8 */
                            NK_KP_9,     /* 9 */
                            NK_KP_Minus,     /* G-- */
                            NK_KP_4,     /* 4 */
                            NK_KP_5,     /* 5 */
                            NK_KP_6,     /* 6 */
                            NK_KP_Plus,     /* G-+ */
                            NK_KP_1,     /* 1 */
                     /*50*/ NK_KP_2,     /* 2 */
                            NK_KP_3,     /* 3 */
                            NK_KP_0,     /* 0 */
                            NK_KP_Period,     /* . */
                            0x00,     /*   */
                            0x00,     /*  */
                            0x00,     /*  */
                            NK_F11,     /* F11 */
                            NK_F12,     /* F12 */
                            NK_KP_Enter,
                            NK_RightCtrl,
                            NK_KP_Slash,
                            NK_RightAlt,
                            NK_Home,
                            NK_Up,
                            NK_PageUp,
                     /*60*/ NK_Left,
                            NK_Right,
                            NK_End,
                            NK_Down,
                            NK_PageDown,
                            NK_Insert,
                            NK_Delete,
                            NK_PrintScreen,
                            NK_Pause,
                            0x00,
                            0x00,
                            0x00,
                            0x00,
                            0x00,
                            0x00,
                            0x00,
                            0x00,
                            NK_Hanja,
                            NK_HanEng,
                     };
