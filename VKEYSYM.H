#if !defined( __VKEYSYM_H__ )
#    define   __VKEYSYM_H__

#define NK_Unknown          0x00

/* --------------------------------------------------------------------------
 * Letters
 *
 * --------------------------------------------------------------------------
 * [ ` 1 2 3 4 5 6 7 8 9 0 - = \  ]
 * [   Q W E R T Y U I O P [ ]    ]
 * [    A S D F G H J K L ; '     ]
 * [     Z X C V B N M , . /      ]
 *
 * --------------------------------------------------------------------------
 * [ [' ][„]][„V][„S][†a][‡A][„¡][…][‡][†][ÄA][- ][= ][\ ]   ]
 * [   [„U][„I][…a][„][„á][œA][”A][ A][ÀA][ÌA][[ ][] ]         ]
 * [     [„W][„E][‡¡][„a][‡a][A][´A][ˆA][¸A][¤A][ÈA]           ]
 * [       [„Q][„B][…A][…¡][†][¬A][ÐA][, ][. ][…¡]             ]
 *
 * --------------------------------------------------------------------------
 */

#define NK_Grave            0x08      /* ` NK_Grave         [` ]      */
#define NK_1                0x09      /* 1 NK_1             [„]] ¹·¬÷ */
#define NK_2                0x0A      /* 2 NK_2             [„V] ¹·¬÷ */
#define NK_3                0x0B      /* 3 NK_3             [„S] ¹·¬÷ */
#define NK_4                0x0C      /* 4 NK_4             [†a] º—¬÷ */
#define NK_5                0x0D      /* 5 NK_5             [‡A] º—¬÷ */
#define NK_6                0x0E      /* 6 NK_6             [„¡] º—¬÷ */
#define NK_7                0x0F      /* 7 NK_7             […] º—¬÷ */
#define NK_8                0x10      /* 8 NK_8             [‡] º—¬÷ */
#define NK_9                0x11      /* 9 NK_9             [†]*º—¬÷ */
#define NK_0                0x12      /* 0 NK_0             [ÄA] Á¡¬÷ */
#define NK_Minus            0x13      /* - NK_Minus         [- ]      */
#define NK_Equal            0x14      /* = NK_Equal         [= ]      */
#define NK_BackSlash        0x15      /* \ NK_BackSlash     [\ ]      */

#define NK_Q                0x16      /* Q NK_Q             [„U] ¹·¬÷ */
#define NK_W                0x17      /* W NK_W             [„I] ¹·¬÷ */
#define NK_E                0x18      /* E NK_E             […a] º—¬÷ */
#define NK_R                0x19      /* R NK_R             [„] º—¬÷ */
#define NK_T                0x1A      /* T NK_T             [„á] º—¬÷ */
#define NK_Y                0x1B      /* Y NK_Y             [œA] Á¡¬÷ */
#define NK_U                0x1C      /* U NK_U             [”A] Á¡¬÷ */
#define NK_I                0x1D      /* I NK_I             [ A] Á¡¬÷ */
#define NK_O                0x1E      /* O NK_O             [ÀA] Á¡¬÷ */
#define NK_P                0x1F      /* P NK_P             [ÌA] Á¡¬÷ */
#define NK_BracketLeft      0x20      /* [ NK_BracketLeft   [[ ]      */
#define NK_BracketRight     0x21      /* ] NK_BracketRight  [] ]      */

#define NK_A                0x22      /* A NK_A             [„W] ¹·¬÷ */
#define NK_S                0x23      /* S NK_S             [„E] ¹·¬÷ */
#define NK_D                0x24      /* D NK_D             [‡¡] º—¬÷ */
#define NK_F                0x25      /* F NK_F             [„a] º—¬÷ */
#define NK_G                0x26      /* G NK_G             [‡a] º—¬÷ */
#define NK_H                0x27      /* H NK_H             [A] Á¡¬÷ */
#define NK_J                0x28      /* J NK_J             [´A] Á¡¬÷ */
#define NK_K                0x29      /* K NK_K             [ˆA] Á¡¬÷ */
#define NK_L                0x2A      /* L NK_L             [¸A] Á¡¬÷ */
#define NK_SemiColon        0x2B      /* ; NK_SemiColon     [¤A] Á¡¬÷ */
#define NK_Apostrophe       0x2C      /* ' NK_Apostrophe    [ÈA] Á¡¬÷ */

#define NK_Z                0x2D      /* Z NK_Z             [„Q] ¹·¬÷ */
#define NK_X                0x2E      /* X NK_X             [„B] ¹·¬÷ */
#define NK_C                0x2F      /* C NK_C             […A] ¹·¬÷ */
#define NK_V                0x30      /* V NK_V             […¡] º—¬÷ */
#define NK_B                0x31      /* B NK_B             [†] º—¬÷ */
#define NK_N                0x32      /* N NK_N             [¬A] Á¡¬÷ */
#define NK_M                0x33      /* M NK_M             [ÐA] Á¡¬÷ */
#define NK_Comma            0x34      /* , NK_Comma         [, ]      */
#define NK_Period           0x35      /* . NK_Period        [. ]      */
#define NK_Slash            0x36      /* / NK_Slash         […¡]*º—¬÷ */
#define NK_Space            0x37      /*   NK_Space         [  ]      */

/* --------------------------------------------------------------------------
 * TTY funcitons
 */
#define NK_BackSpace        0x3C  /* back space, back char */
#define NK_Tab              0x3D
#define NK_Enter            0x3E  /* Return, enter */
#define NK_ESC              0x3F

/* --------------------------------------------------------------------------
 * Modifiers
 */
#define NK_CapsLock         0x40  /* Caps lock      */
#define NK_NumLock          0x41

#define NK_LeftShift        0x42  /* Left shift     */
#define NK_RightShift       0x43  /* Right shift    */
#define NK_LeftCtrl         0x44  /* Left ctrl      */
#define NK_RightCtrl        0x45  /* Right ctrl     */
#define NK_LeftAlt          0x46  /* Left alt       */
#define NK_RightAlt         0x47  /* Right alt      */

#define NK_Hanja            0x4A
#define NK_HanEng           0x4B

/* --------------------------------------------------------------------------
 * Misc Functions
 */

#define NK_PrintScreen      0x50  /* Print screen */
#define NK_ScrollLock       0x51
#define NK_Pause            0x52  /* Pause, hold */

#define NK_Insert           0x5A  /* Insert, insert here */
#define NK_Delete           0x5B  /* Delete, rubout */
#define NK_Home             0x5C
#define NK_End              0x5D  /* EOL */
#define NK_PageUp           0x5E
#define NK_PageDown         0x5F

/* --------------------------------------------------------------------------
 * Cusor Moiton
 */
#define NK_Up               0x60  /* Move up, up arrow */
#define NK_Down             0x61  /* Move down, down arrow */
#define NK_Left             0x62  /* Move left, left arrow */
#define NK_Right            0x63  /* Move right, right arrow */

/* --------------------------------------------------------------------------
 * Keypad Functions
 */
#define NK_KP_0             0x70
#define NK_KP_1             0x71
#define NK_KP_2             0x72
#define NK_KP_3             0x73
#define NK_KP_4             0x74
#define NK_KP_5             0x75
#define NK_KP_6             0x76
#define NK_KP_7             0x77
#define NK_KP_8             0x78
#define NK_KP_9             0x79
#define NK_KP_Aster         0x7A  /* * Aster  */
#define NK_KP_Plus          0x7B  /* + Plus   */
#define NK_KP_Minus         0x7D  /* - Minus  */
#define NK_KP_Slash         0x7E  /* / Slash  */
#define NK_KP_Period        0x7F
#define NK_KP_Enter         0x80

/* --------------------------------------------------------------------------
 * Auxilliary Functions
 */
#define NK_F1               0x90
#define NK_F2               0x91
#define NK_F3               0x92
#define NK_F4               0x93
#define NK_F5               0x94
#define NK_F6               0x95
#define NK_F7               0x96
#define NK_F8               0x97
#define NK_F9               0x98
#define NK_F10              0x99
#define NK_F11              0x9A
#define NK_F12              0x9B

#endif /* #if !defined( __VKEYSYM_H__ ) */
