/*============================= Ptools.h =================================
==========================================================================*/
#ifndef __PTOOLS_H
#define __PTOOLS_H
#include "letter.h"
#define ON         1
#define OFF        0
#define SUCCEED    0
#define ERROR     -1
#define FAIL	  -1
#define OK         0
#define PI 3.141592653
#define MAX_STRING 255

#define video_service 0x10

#define print_character(x) putch(x)
#define get_character(x) getch(x)

/* enum bool {false, true};*/
typedef unsigned char byte;
typedef unsigned int  word;
typedef unsigned long ulong;
typedef unsigned int  word32;
typedef unsigned short int word16;

/*===========================Macro Function==========================*/

#define percent(x, y) (100.0 * x / y)
#define abs_val(x) ((x >= 0) ? x : 0 - x)      /* ¸é”ˆt ŠÐa‹¡ */
#define max(x, y) ((x > y) ? x : y)            /* Çe ˆt·i •©aº‘ */
#define min(x, y) ((x < y) ? x : y)            /* ¸b·e "    "    */
#define is_odd(x) ((x % 2 == 1) ? 1 : 0)       /* ¼b®·¡¡e 0 Ñ©®·¡¡e 1 */
#define is_even(x) ((x % 2 == 0) ? 1 : 0)      /*    "     1    "     0 */
#define round_off(x) ((int)(x + 0.5))          /* ­¡®¸ñ·¡ÐaŸi ¤eµ¡Ÿ± */
#define _truncate(x) ((int)(x))                 /*      "       Ÿ± */
#define remainder(x, y) (x % y)                /* a á»¡Ÿi •©aº‘ */
#define square(x) x*x
#define cube(x) x*x*x
#define XOR(x, y) ((x & ~y) | (~x & y))
#define NOT(x) ((x != 0) ? 0 : 1)
#define bit_mask(x, y) (x & y)
#define is_digit(x) ((x >= '0' && x <= '9') ? 1: 0)  /* ®•¸a¡e 1 ´a“¡¡e 2 */
#define is_uppercase(x) ((x >= 'A' && x <= 'Z') ? 1 : 0)  /* ”¢…¸a¡e 1 ´a“¡¡e 0 */
#define is_lowercase(x) ((x >= 'a' && x <= 'z') ? 1 : 0)  /* ­¡¢…¸a¡e 1 ´a“¡¡e 0 */
#define is_blank(x) ((x == ' ') ? 1 : 0)  /* ‰·¤‚¢…¸a¡e 1 ´a“¡¡e 0 */
#define BELL() putchar(7)
#define to_uppercase(x) ((is_lowercase(x)) ? x - 'a' + 'A' : x)
#define to_lowercase(x) ((is_uppercase(x)) ? x + 'a' - 'A' : x)
#define to_decimal(x) (x - '0')
#define is_control(x) ((x > 0 && x < 32) ? 1 : 0)  /* ÄåËa© ¢…¸a¡e 1 ´a“¡¡e 0 */
#define is_printable_ascii(x) ((x > 32 && x < 127) ? 1 : 0)
#define to_ascii(x) ((x >= 0 && x <= 9) ? x + '0' : -1)
#define is_binary(x) ((x == '0' || x == '1') ? 1 : 0)
#define is_hexadecimal(x) ((is_digit(x) || (x >= 'A' && x <= 'F')) ? 1 : 0)
#define is_octal(x) ((x >= '0' && x <= '7') ? 1 : 0)
#endif
