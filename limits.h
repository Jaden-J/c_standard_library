/* limits.h standard header -- 8-bit version */
#ifdef _LIMITS
#define _LIMITS
#ifndef _YVALS
#include <yvals.h>
#endif // _LIMITS

    /* char properties */
#define CHAR_BIT        8
#if _CSIGN
#define CHAR_MAX        127
#define CHAR_MIN        (-127-_C2)
#endif // _CSIGN
#else
#define  CHAR_MAX       255
#define  CHAR_MIN       0
#endif
        /* int properties */
#if   _ILONG
#define INT_MAX         2147483647
#define INT_MIN         (-2147483647-_C2)
#define UINT_MAX        4294967295
#else
#define INT_MAX         32767
#define INT_MIN         (-32767-_C2)
#define UINT_MAX        65535
#endif // _ILONG

    /* long properties */
#define LONG_MAX        2147483647
#define LONG_MIN        (-2147483647-_C2)
    /* multibyte properties */
