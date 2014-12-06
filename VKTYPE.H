#ifndef __VKTYPE_H__
#define __VKTYPE_H__

#include "../ptools.h"

typedef union vitual_key_dataObj
{
    struct
    {
        word    dummy      : 8; /* ˆa¬w‹i®A Å¡—a      */
        word    right_shift : 1; /* µ¡Ÿe½¢ ®áÏaËa ’‰Ÿ± */
        word    left_shift  : 1; /* ¶E½¢ ®áÏaËa ’‰Ÿ±   */
        word    right_ctrl  : 1; /* µ¡Ÿe½¢ Å¥Ëa© ’‰Ÿ± */
        word    left_ctrl   : 1; /* ¶E½¢ Å¥Ëa© ’‰Ÿ±   */
        word    right_alt   : 1; /* µ¡Ÿe½¢ ´iËa ’‰Ÿ±   */
        word    left_alt    : 1; /* ¶E½¢ ´iËa ’‰Ÿ±     */
        word    caps_lock   : 1; /* Caps Lock ¸b•·     */
        word    num_lock    : 1; /* Num Lock ¸b•·      */
    } i;
    struct
    {
        byte   vkey_code     ; /* ˆa¬w‹i®A Å¡—a     */
        byte   modifier_state; /* ¤aŽ‘ ‹i®A ¬wÈ    */
    } h;
    word16 vkey_data;
}
virtual_key_dataRec;

typedef struct key_inputObj
{
    word16              input_kind; /* ·³b ¹·ŸA */
    virtual_key_dataRec vkey_data  ; /* ˆa¬w‹i®A ·³b */
    letter              code   ; /* ‹i¸a¦Ñ¡ */
} key_inputRec;

#endif
