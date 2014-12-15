#define NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include "tassert.h"
#include "tctype.h"
#include "terrno.h"
void convert_to_lower();
void reads_a_line_store_it_in_a_buffer_and_prints_its_length();
void strcpy_ex()
{
    char source[]="The source string.";
    char dest1[80];
    char *dest2, *dest3;
    printf("\nsource:%s",source);

    strcpy(dest1,source);
    printf("\ndest1:%s",dest1);

    dest2=(char*)malloc(strlen(source)+1);
    strcpy(dest2,source);
    printf("\ndest2:%s",dest2);
}
void strncpy_ex()
{
    char dest[]=  "..........................";
    char source[]="abcdefghijklmnopqrstuvwxyz";
    size_t n;
    while(1)
    {
        puts("Enter the number of characters to copy(1-26)");
        scanf("%d",&n);
        if(n>0 && n< 27)
            break;
    }
    printf("\nBefore strncpy destination=%s",dest);
    //n is the number of characters to copy
    strncpy(dest,source,n);
    printf("\nAfter strncpy destination=%s\n",dest);
}
void strdup_ex()
{
    //strdup manages memory allocation
    char source[]="The source string.";
    char *dest;
    if( (dest =strdup(source)) == NULL)
    {
        fprintf(stderr,"Error allocating memory");
        exit(1);
    }
    printf("The destination = %s\n",dest);
}
void strcmp_ex()
{
    char str1[80],str2[80];
    int x;
    while(1)
    {
        // input two strings
        printf("\n\nInput the first string, a blank exit: ");
        gets(str1);
        if(strlen(str1)==0)
            break;
        printf("\n Input the second line:");
        gets(str2);

        //compare them and display the result.
        x = strcmp(str1,str2);
        printf("\nstrcmp(%s,%s) returns %d",str1,str2,x);
    }
}
void strncmp_ex()
{
    char str1[]="the first string.";
    char str2[] = "the second string";
    size_t n,x;
    puts(str1);
    puts(str2);
    while(1)
    {
        puts("\n\nEnter the number of characters to compare?");
        scanf("%d",&n);;
        if(n<=0)
            break;
        x=strncmp(str1,str2,n);
        printf("\nComparing %d characters, strncmp() returns %d",n,x);
    }
}
void strcat_ex()
{
    char str1[27]="a";
    char str2[2];
    int n;
    str2[1]='\0';
    for(n=98;n<123;n++)
    {
        str2[0] = n;
        strcat(str1,str2);
        puts(str1);
    }
}
int main()
{
   // test_assert();
   // test_ctype();
   // test_errno();

    //convert_to_lower();

    //reads_a_line_store_it_in_a_buffer_and_prints_its_length();
    //read_lines_and_count_of_all_and_store_the_first_100_characters_of_each();
    //strcpy_ex();
    //strncpy_ex();
    //strdup_ex();
    //strcat_ex();
    //strcmp_ex();
    //strncmp_ex();

    return 0;
}
void convert_to_lower()
{
    char c;
    while( (c=getchar()) != '\0')
        if( 'A'<=c && c<='Z')
            putchar(c + 'a'-'A');
        else
            putchar(c);
}
void read_lines_and_count_of_all_and_store_the_first_100_characters_of_each()
{
    int n,c; char line[100];
    n=0;
    while( (c=getchar()) != '\0')
    if( c== '\n'){
        printf("%d",n);
        n = 0;
    }
    else
    {
        if(n < 100) line[n]=c;
        n++;
    }
}
void reads_a_line_store_it_in_a_buffer_and_prints_its_length()
{
    int n,c;
    char line[100];
    n=0;
    while( (c=getchar()) != '\n'){
        if(n<100)
            line[n] = c;
        n++;
    }
    printf("length=%d\n",n);
}

