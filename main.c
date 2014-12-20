#define NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include "tassert.h"
#include "tctype.h"
#include "terrno.h"
#include "float.h"
//#include "string_ex.h"
#include "pointer.examples.h"
#include "io_ex.h"


int bss_var;
int data_var=1;
int main()
{



   // test_assert();
   // test_ctype();
   // test_errno();
    //io_ex_main();
    pointer_ex_main();
    double radlog;
    int digs;
    static int radix = FLT_RADIX;
//    printf("%d",sizeof(unsigned short)*4);
  //  printf("%d",sizeof(long double));
//    printf("FLT_RADIX = %i\n\n",FLT_RADIX);
  //  printf("DBL_DIG=         %5i        DBL_MANT_DIG=      %6i\n",
 //          DBL_DIG, DBL_MANT_DIG);



    return 0;
}

