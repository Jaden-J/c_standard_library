#ifndef ASSERT_H_INCLUDED
#define ASSERT_H_INCLUDED

#undef assert

#ifndef  NDEBUG
#define assert(test)  ((void)0)
#else
    void _ASSERT(char *);
    #define _STR(x) _VAL(x)
    #define _VAL(x) #x
    #define assert(test)    ((test) ? (void)0 : _ASSERT(__FILE__ ":" __STR(__LINE__) " " #test))
#endif // NDEBUG



#endif // ASSERT_H_INCLUDED
