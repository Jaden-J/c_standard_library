#include "errno.h"
/* test errno macro */
void test_errno()
{
    assert(errno == 0);
    perror("No error reported as");
    errno = ERANGE;
    assert(errno == ERANGE);
    perror("Range error reported as");
    errno = 0;
    assert(errno == 0);
    sqrt(-1.0);
    assert(errno == EDOM);
    perror("Domain error reported as");
    puts("SUCCESS testing error.h");
}
