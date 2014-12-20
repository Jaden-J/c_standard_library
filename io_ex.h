#include <stdio.h>
void read_multiple_numbers_with_scanf()
{
    int N;
    while(scanf("%d",&N==1))
    {

    }
}
void read_multiple_lines_with_lines_terminated_by_three_dots(void)
{
    char digits[100];
    int N;
    scanf("%d",&N);
    int i=0;
    for(i=0;i<N;++i){
        scanf("0.%[0-9]...",&digits);
    }
    printf("the digits are 0.%s\n",digits);
}
void scanf_only_taking_uppercase()
{
    //char line[100];
    char *line=malloc(sizeof(char) * 100);

    scanf("%[ABCDEFGHIJKLMNOPQRSTUVWXYZ]",line);
    int i=0;
    for(i=0;line[i]!='\0';++i)
        putchar(line[i]);
}
void scanf_that_behave_like_gets()
{
    char line[100];
    scanf("%[^\n]",line);
    printf("%s",line);
}
void take_input_from_file()
{
    char input[100],ch;

    freopen("input.txt","rb",stdin);
    scanf("%s\n",&input);
    scanf("%c",&ch);  //the value of ch will be \n


}
void io_ex_main(){
    //read_multiple_numbers_with_scanf();
    //read_multiple_lines_with_lines_terminated_by_three_dots();
    //scanf_only_taking_uppercase();
    //scanf_that_behave_like_gets();
    take_input_from_file();
}
