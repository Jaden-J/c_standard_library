/* isalnum function */
#include <ctype.h>
int (isalnum)(int c)
{
    return (_Ctype[c] & (_DI|_LO|_UP|_XA));
}
