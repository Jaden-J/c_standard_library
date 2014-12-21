#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//#define make_ptr(c,counter) char *counter##=&c
//#define make_ptr(c) printf( #c)

void address_of_a_pointer(void)
{
    int  iVar = 77,*iPtr=&iVar;
    printf("value of iPtr(i.e the address of iVar): %p\n"
           "Address of iPtr:                                 %p\n",iPtr,&iPtr);
}
void cast_char_pointer()
{
    double x=1.5;
    //char *cPtr= &x; //error: type mismatch; no implicit conversion
    char *cPtr=(char*)&x;
}
void declare_pointer_to_pointer()
{
    char c='A',*cPtr=&c, **cPtrPtr=&cPtr;
}
////////////////////////////////
typedef struct {long key;} Record;
_Bool newRecord(Record **ppRecord)
{
    *ppRecord = malloc(sizeof(Record));
    if(*ppRecord!=NULL)
    {
        //initialize the new record's members
        return 1;
    }
    else
        return 0;
}
void pointer_to_pointer_as_function_parameter()
{
    Record *pRecord = NULL;
    if(newRecord(&pRecord)){
        //do initializations
    }
}
/////////////////////////////////////////////
// selectin sort pointer format
inline void swap(float *p1,float *p2)
{
    float temp = *p1;
    *p1=*p2;
    *p2=temp;
}
void selection_sortf(float a[],int n)
{
    if(n<=1) return;
    register float *last = a + n -1,        // a pointer to the last element
                          *p,               // a pointer to a selected element
                          *minPtr;          // a pointer to the current minimum
    for(;a<last;++a)
    {
        minPtr=a;                           //find the smallest element
        for(p=a+1;p<= last; ++p)
            if( *p < *minPtr)
                minPtr = p;
        swap(a,minPtr);                     //swap the smallest element with the element at a
    }
}
void selection_sort_using_pointers()
{
    float f[]={1.0, 4.1, 2.1, 2.2, 3.9, 4.0};
    int length = sizeof(f)/sizeof(f[0]);
    selection_sortf(f,length);
    int i=0;
    for(i=0;i<length;++i)
    {
        printf("a[%d]=%f\n",i,f[i]);
    }
}
/////////////////////////////////////////////
void declaring_constant_pointer()
{
    int var;
    int *const c_ptr = &var;   //a constant pointer to an int
    *c_ptr = 123;               //ok: we can modify the object referenced,but..
 //   ++c_ptr;                    //error: we can't modify the pointer
}
void declaring_pointer_to_constant()
{
    int var;
    const int c_var = 100, *ptr_to_const;
    ptr_to_const = &c_var;
    var = 2 * *ptr_to_const;                //ok equals to var= 2 * c_var;
    ptr_to_const = &var;
  //  if(c_var < *ptr_to_const)
//        *ptr_to_const = 77;                  //error: we can't modify var using
                                            //ptr_to_const
}
void copy_first_half_array_to_second_half()
{
    int arr[200];
    memcpy(arr+100,arr,100);
}
////////////////////////////////////////////
/*
double scalar_product(const double * restrict p1,const double * restrict p2,int n)
{
    double result= 0.0;
    for(int i=0;i<n;++i)
        result+=p1[i] * p2[i];
    return 1.0;
}
*/
void scalar_product_using_restrict()
{
    //call scalar_product
}
////////////////////////////////////////////
void address_of_a_function()
{
    void* stack_var;
    stack_var = (void *)address_of_a_function;
    printf("main is executing at %p\n",stack_var);
    printf("the address (%p) is in our stack frame\n",&stack_var);
}
///////////////////////////////////////////////
declare_array_pointer()
{
    // a pointer to an array of ten elements with type int.
        int(* arrptr)[10]= NULL;
}
/////////////////////////////////////////////////
void declare_pointer_arrays()
{
    #define ARRAY_LEN 100
    #define STRLEN_MAX 256
    char myStrings[ARRAY_LEN][STRLEN_MAX] =
    { // Several corollaries of Murphy's Law:
        "If anything can go wrong, it will.",
        "Nothing is foolproof, because fools are so ingenious.",
        "Every solution breeds new problems."
    };

    char *myStrPtr[ARRAY_LEN] =    // Array of pointers to char
        { // Several corollaries of Murphy's Law:
            "If anything can go wrong, it will.",
            "Nothing is foolproof, because fools are so ingenious.",
            "Every solution breeds new problems."
        };

}
////////////////////////////////////////////////////////////
#define NLINES_MAX 10          // Maximum number of text lines.
char *linePtr[NLINES_MAX];       // Array of pointers to char.
// Reads a line of text from stdin; drops the terminating newline character.
// Return value: A pointer to the string read, or
//               NULL at end-of-file, or if an error occurred.
#define LEN_MAX 512                           // Maximum length of a line.

char *getline( )
{
  char buffer[LEN_MAX], *linePtr = NULL;
  if ( fgets( buffer, LEN_MAX, stdin ) != NULL )
  {
    size_t len = strlen( buffer );

    if ( buffer[len-1] == '\n' )              // Trim the newline character.
      buffer[len-1] = '\0';
    else
      ++len;

    if ( (linePtr = malloc( len )) != NULL )  // Get enough memory for the line.
      strcpy( linePtr, buffer );        // Copy the line to the allocated block.
  }
  return linePtr;
}

// Comparison function for use by qsort( ).
// Arguments: Pointers to two elements in the array being sorted:
//            here, two pointers to pointers to char (char **).
int str_compare( const void *p1, const void *p2 )
{
  return strcmp( *(char **)p1, *(char **)p2 );
}

void sort_lines_of_text()
{
    // Read lines:
  int n = 0;                     // Number of lines read.
  for (  ; n < NLINES_MAX && (linePtr[n] = getline( )) != NULL; ++n );
    //printf("%d\n",n);

  if ( !feof(stdin) )            // Handle errors.
  {
    if ( n == NLINES_MAX )
      fputs( "sorttext: too many lines.\n", stderr );
    else
      fputs( "sorttext: error reading from stdin.\n", stderr );
  }
  else                           // Sort and print.
  {
    char **p=NULL;
    qsort( linePtr, n, sizeof(char*), str_compare );     // Sort.
    for (**p = linePtr; p < linePtr+n; ++p )       // Print.
      puts(*p);
  }
}
////////////////////////////////////////////////////////////
void declaring_function_pointers(void)
{
    double (*funcPtr)(double, double);

    double result;
    funcPtr = pow;                  // Let funcPtr point to the function pow( ).
                                // The expression *funcPtr now yields the
                                // function pow( ).

    result = (*funcPtr)( 1.5, 2.0 );  // Call the function referenced by
                                  // funcPtr.
    result = funcPtr( 1.5, 2.0 );     // The same function call.

}
/////////////////////////////////////////////
double Add( double x, double y ) { return x + y; }
double Sub( double x, double y ) { return x - y; }
double Mul( double x, double y ) { return x * y; }
double Div( double x, double y ) { return x / y; }

// Array of 5 pointers to functions that take two double parameters
// and return a double:
double (*funcTable[5])(double, double)
          = { Add, Sub, Mul, Div, pow }; // Initializer list.

// An array of pointers to strings for output:
char *msgTable[5] = { "Sum", "Difference", "Product", "Quotient", "Power" };
void function_pointer_table()
{
    int i;                  // An index variable.
  double x = 0, y = 0;

  printf( "Enter two operands for some arithmetic:\n" );
  if ( scanf( "%lf %lf", &x, &y ) != 2 )
    printf( "Invalid input.\n" );

  for ( i = 0; i < 5; ++i )
    printf( "%10s: %6.2f\n", msgTable[i], funcTable[i](x, y) );

}
void pointer_ex_main(void)
{
    //address_of_a_pointer();
    //cast_char_pointer();
    //declare_pointer_to_pointer();
    //pointer_to_pointer_as_function_parameter();
    //selection_sort_using_pointers();
    //declaring_constant_pointer();
    //copy_first_half_array_to_second_half();
    //scalar_product_using_restrict();
    //address_of_a_function();
    //declare_array_pointer();
    //declare_pointer_arrays();
    //sort_lines_of_text();
    //declaring_function_pointers();
    function_pointer_table();
      // printf("%p\n",&bss_var);
    //printf("%p\n",&data_var);

}
