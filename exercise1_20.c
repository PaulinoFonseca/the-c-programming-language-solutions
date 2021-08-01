#include <stdio.h>

/* possible values for state: IN or OUT of a sequence of tabs */
#define IN 1
#define OUT 0
#define MAXLINE 1000
/* number of blanks in a row that make a tab */
#define N 8

int get_line(char s[], int max);

/* replace tabs in the input
    with the proper number of blanks */
int main()
{
    char line[MAXLINE];
    int len;

    while ( (len = get_line(line, MAXLINE)) > 0){
        printf("%s",line);
    }
    return 0;
}

/* pass input characters to string
    if the char is a tab, add seven blank in a row */
int get_line(char s[], int max)
{
    char c, i, j, state;

    i = 0;
    while(( (i < max -1) && (c = getchar()) != EOF) && (c != '\n') ){
        if (c != '\t'){
            s[i] = c;
            state = OUT;
            ++i;

        }
        /* adding tabs in a row
            if it's a sequence of tabs, adds one more blank */
        else{
            if (state){
                s[i] = ' ';
                ++i;
            }
            for (j = 0; (i + j)%N != 0; ++j){
                s[i+j] = ' ';
            }
            state = IN;
            i = i + j;
        }
    }
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}