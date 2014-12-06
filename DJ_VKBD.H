#ifndef __LL_KBD_H__
#define __LL_KBD_H__

#include "../ptools.h"
#include "vktype.h"
#include "vkeysym.h"

extern char    *kbdFLAGS;

#ifdef  __cplusplus
extern "C" {
#endif

void    kbdInit();
void    kbdReset();
int     kbdGetMode();
void    kbdSetMode(int);
int     kbdKeyHit();
void    kbdClearKeys();
int     kbdPutKey(virtual_key_dataRec);
virtual_key_dataRec    kbdGetKey();
void    kbdSetScrlLight(int);
void    kbdSetNumLight(int);
void    kbdSetCapLight(int);
void    kbdSetRate(int , int);

#ifdef __cplusplus
}
#endif

#define kbdKeyIs(key)       (kbdFLAGS[key] & 0x01)
#define kbdKeyWas(key)      (kbdFLAGS[key] & 0x02)
#define kbdKeySet(key)      (kbdFLAGS[key] |=  0x02)
#define kbdKeyClr(key)      (kbdFLAGS[key] &= ~0x02)
#define kbdKeyReset(key)    {                   \
                            if (kbdKeyIs(key))  \
                                kbdKeySet(key); \
                            else                \
                                kbdKeyClr(key); \
                            }

#define ABSOLUTE    0x00    /* 0000 0000 */
#define NOSYSTEM    0x01    /* 0000 0010 */

/*
** Typematic Rates
*/
                                /* 0xx0 0000 */
#define DEL_14          0x00    /* 0000 0000 */
#define DEL_24          0x20    /* 0010 0000 */
#define DEL_34          0x40    /* 0100 0000 */
#define DEL_44          0x60    /* 0110 0000 */

                                /* 000x xxxx */
#define CPS_30          0x00    /* 0000 0000 */
#define CPS_24          0x02    /* 0000 0010 */
#define CPS_20          0x04    /* 0000 0100 */
#define CPS_16          0x07    /* 0000 0111 */
#define CPS_15          0x08    /* 0000 1000 */
#define CPS_12          0x0A    /* 0000 1010 */
#define CPS_10          0x0C    /* 0000 1100 */
#define CPS_08          0x0F    /* 0000 1111 */
#define CPS_06          0x12    /* 0001 0010 */
#define CPS_05          0x14    /* 0001 0100 */
#define CPS_04          0x17    /* 0001 1110 */
#define CPS_03          0x1A    /* 0001 1010 */
#define CPS_02          0x1F    /* 0001 1111 */

#ifndef ON
#define ON 1
#define OFF 0
#endif

#endif

