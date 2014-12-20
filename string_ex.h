#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
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
void strchr_ex()
{
    char *loc,buf[80];
    int ch;
    /* input the string and the character */
    printf("enter the string to be searched: ");
    gets(buf);
    printf("Enter the character to search for: ");
    ch = getchar();

    /* perform search */
    loc = strchr(buf,ch);

    if(loc == NULL)
        printf("The characters %c was not found.",ch);
    else
        printf("Te characters %c was found at position %d.\n",ch,loc-buf);
}
void strcspn_ex()
{
    //the function strcspn start searching at the first character of str1, looking for
    // any of the individual characters contained in str2.
    char buf1[80],buf2[80];
    size_t loc;

    /* input the strings */
    printf("Enter  the string to be searched");
    gets(buf1);
    printf("Enter the string containing the target chracacters:");
    gets(buf2);

    /* perform search */
    loc = strcspn(buf1,buf2);
    if(loc == strlen(buf1))
        printf("No match was found");
    else
        printf("The first match was found at  position %d.\n",loc);
}
void strpbrk_ex()
{
    //is similar to strcspn(), searching one string for the first occurrence
    // of any character in another string.It differs in that it doesn't include
    // the terminating null characters in the search.the function prototype
    // char *strpbrk(char *str1,char *str2);

}
void strstr_ex()
{
    // searches for the first occurrence of one string within another, & it searches
    // for the entire string
    // char *strstr(char *str1,char *str2);
    char *loc, buf1[80], buf2[80];
    // input the strings
    printf("Enter the string to be searched:");
    gets(buf1);
    printf("Enter the target string");
    gets(buf2);

    //perform the search
    loc = strstr(buf1,buf2);
    if(loc == NULL)
        printf("No match was found.\n");
    else
        printf("%s was found at position %d.\n",buf2,loc-buf1);
}
void strrev_ex()
{
    char s[] = "the quick brown fox jumps over the lazy dog";
     char *t=strrev(s);
    printf("%s",t);

}
void atoi_ex()
{
    //converts  a string to an integer
    char* a="157";
    char* b = "-1.6";

    printf("%d",atoi(a));
    printf("\n%d",atoi(b));
    printf("\n%d",atoi("+50x"));
    printf("\n%d",atoi("twelve"));
}
void atl_ex()
{
    //works exactly like atoi ,except that it returns a long
}
void atof_ex()
{
    //double atof(char *str);
    //converts a string to double
}
int isxxx_ex()
{
    int ch,i,sign=1;
    int res;
    while(isspace(ch=getchar()));
    if(ch!='-' && ch!='+' && !isdigit(ch) && ch!=EOF)
    {
        ungetc(ch,stdin);
        res=0;
    }
    // if the first character is a minus sign, set sign accordingly
    if(ch=='-')
        sign = -1;
    // if the first character was  a plus or minus sign, get the next character
    if(ch=='+' || ch=='-')
        ch = getchar();
    //Read the characters until a nondigit is input.assign
    // values,multiplied by proper power of 10, to i.
    for(i=0;isdigit(ch);ch=getchar())
        i = 10 * i + (ch - '0');
    //make result negative if sign is negative
    i *=sign;
    //if EOF encountered ,  a nondigit character must have been read in, so unget it
    if(ch!=EOF)
        ungetc(ch,stdin);
    res=i;
    printf("You entered %d.\n",res);

}
void read_using_fgets()
{
        char line[100];
        printf("Enter a line: ");
        fgets(line,sizeof(line),stdin);
        printf("The length of the line is %d\n.",strlen(line));
}
void trim_end_of_line_character()
{
    char first[100];
    char last[100];
    char full[200];
    printf("Enter your first name:");
    fgets(first,sizeof(first),stdin);
    //to trim the \n from the last character position
    first[strlen(first)-1]='\0';
    printf("\nEnter your last name:");
    fgets(last,sizeof(last),stdin);
    //to trim the \n from the last character position
    last[strlen(last)-1] = '\0';
    strcpy(full,first);
    strcat(full, " ");
    strcat(full, last);


    printf("The name is %s\n",full);

}
void read_number()
{
    char line[100];
    int value;
    printf("Enter  a number: ");
    fgets(line,sizeof(line),stdin);
    sscanf(line,"%d",&value);
    printf("Twice %d is %d\n",value, value * 2);

}
void read_multiple_numbers()
{
    //computes the area of a triangle
    char line[100];
    int height;
    int width;
    int area;
    printf("Enter width and height?");
    fgets(line,sizeof(line),stdin);
    sscanf(line,"%d %d",&width,&height);
    area=(width*height) / 2;
    printf("The area is %d\n",area);
}
void read_short_int()
{
    //shorts can not be directly read from input, you should use an int to get the input
    signed char very_short;
    char line[100];
    int temp;
    fgets(line,sizeof(line),stdin);
    sscanf(line,"%d",&temp);
    very_short=(signed char)temp;
}
void read_number_compute_total()
{

    int total;
    int current;
    int counter;
    char line[80];
    total=0;
    counter=0;
    while(counter < 5)
    {
        printf("Number?");
        fgets(line,sizeof(line),stdin);
        sscanf(line,"%d",&current);
        total+=current;

        ++counter;
    }
    printf("The grand total is %d\n",total);
}
void calculate_string_length()
{
    char _string[]="some string";

    int index;
    for(index=0;_string[index]!='\0';index++);
    printf("The length of string %s is %d",_string,index);
}
void count_num_words_in_string()
{
    char _str[]="the quick brown fox jumps over the lazy dog";
    int counter=1;
    int index=0;
    while(_str[index]!='\0')
    {
        if(isspace(_str[index]) && index!=0 )
        {
            if(!isspace((_str[index-1])))
                counter++;
        }
        ++index;
    }
    printf("The number of words is %d",counter);
}
void startsWith(char *str1,char *str2)
{
    //tests to see if str1 starts with str2
    int starts_with=1;
    if(strlen(str1) >= strlen(str2))
    {
        int i=0;
        for(i=0;str2[i]!='\0';++i)
        {
            if(str2[i]!=str1[i])
            {
                starts_with=0;
                break;
            }
        }
    }
    else
    {
        int i=0;
        for(i=0;str1[i]!='\0';++i)
        {
            if(str1[i]!=str2[i])
            {
                starts_with=0;
                break;
            }
        }
    }
    printf("starts with:%s",starts_with==1 ? "true":"false");

}
void printf_formats()
{
    char c = 'X';
    char s[] ="abcdefghijklmnopqrstuvwxyz";
    int i = 425;
    int j = 17;
    short int  u = 0xf179U;
    long int l = 75000L;
    long long int L = 0x1234567812345678LL;
    float   f = 12.978f;
    double d = -97.453;
    char   *cp = &c;
    int *ip = &i;
    int c1,c2;

    printf("Integers:\n");
    printf ("%i %o %x %u\n", i, i, i, i);
    printf ("%x %X %#x %#X\n", i, i, i, i);
    printf ("%+i % i %07i %.7i\n", i, i, i, i);
    printf ("%i %o %x %u\n", j, j, j, j);
    printf ("%i %o %x %u\n", u, u, u, u);
    printf ("%ld %lo %lx %lu\n", l, l, l, l);
    printf ("%lli %llo %llx %llu\n", L, L, L, L);

    printf ("\nFloats and Doubles:\n");
    printf ("%f %e %g\n", f, f, f);
    printf ("%.2f %.2e\n", f, f);
    printf ("%.0f %.0e\n", f, f);
    printf ("%7.2f %7.2e\n", f, f);
    printf ("%f %e %g\n", d, d, d);
    printf ("%.*f\n", 3, d);
    printf ("%*.*f\n", 8, 2, d);

    printf ("\nCharacters:\n");
    printf ("%c\n", c);
    printf ("%3c%3c\n", c, c);
    printf ("%x\n", c);
    printf ("\nStrings:\n");
    printf ("%s\n", s);
    printf ("%.5s\n", s);
    printf ("%30s\n", s);
    printf ("%20.5s\n", s);
    printf ("%-20.5s\n", s);

    printf ("\nPointers:\n");
    printf ("%p %p\n\n", ip, cp);
    printf ("This%n is fun.%n\n", &c1, &c2);
    printf ("c1 = %i, c2 = %i\n", c1, c2);
}
void standardInts()
{
    int8_t i=0;

}
void using_type_void()
{
    enum {ARR_LEN=100};
    int i, *pNumbers  = malloc(ARR_LEN * sizeof(int));
    if(pNumbers==NULL)
    {
        fprintf(stderr,"Not enough memory");
        exit(1);
    }
    srand((unsigned)time(NULL));        //initialize the randomnumber genratro
    for(i=0;i<ARR_LEN;++i)
    {
            pNumbers[i] = rand() % 10000;
    }
    printf("\n%d random numbers between 0 to 9999:\n",ARR_LEN);
    for(i=0;i<ARR_LEN;++i)
    {
        printf("%6d",pNumbers[i]);
        if(i%10==9) putchar('\n');
    }
    free(pNumbers);

}
void allocateMemory(char* pString,int length)
{
    pString=(char*)malloc(length);
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

void string_ex_main()
{
    char *pString=NULL;
    //allocateMemory(pString,20);
    //strcpy(pString,"Hllo wo");
     //convert_to_lower();

    //reads_a_line_store_it_in_a_buffer_and_prints_its_length();
    //read_lines_and_count_of_all_and_store_the_first_100_characters_of_each();
    //strcpy_ex();
    //strncpy_ex();
    //strdup_ex();
    //strcat_ex();
    //strcmp_ex();
    //strncmp_ex();
    //strchr_ex();
    //strcspn_ex();
    //strstr_ex();
    //strrev_ex();
    //atoi_ex();
    //isxxx_ex();
    //read_using_fgets();
    //trim_end_of_line_character();
    //read_number();
    //read_multiple_numbers();

    //read_short_int();
    //read_number_compute_total();
    //calculate_string_length();
    //count_num_words_in_string();
    //startsWith("ali","a");
    //printf_formats();
     //using_type_void();
    char msg[80]="abc";
    printf("length:%d  size:%d",strlen(msg),sizeof(msg));



}
