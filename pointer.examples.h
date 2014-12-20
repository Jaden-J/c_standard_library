#include <stdio.h>
#include <stdlib.h>
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
    address_of_a_function();

      // printf("%p\n",&bss_var);
    //printf("%p\n",&data_var);

}
