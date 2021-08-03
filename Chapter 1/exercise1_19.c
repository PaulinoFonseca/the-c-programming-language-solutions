#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int get_line(char line[], int maxline);
void reverse(char s[], int len);

/* print reversed input lines */
int main()
{
    int len;                /* current line length */
    char line[MAXLINE];     /* current input line */
    
    while ((len = get_line(line, MAXLINE)) > 0){
            reverse(line,len);
            printf("%s",line);
    }
    return 0;
}

/* getline: read a line into s, return length */
int get_line(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c = getchar()) != EOF && c != '\n'; ++i){
        s[i] = c;
    }
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* reverses the character string s */
void reverse(char s[], int len)
{
    int i, temp;

    for (i = 0; i < (len-1)/2; ++i){
        temp = s[i];
        s[i] = s[(len - 2) - i];
        s[(len - 2) - i] = temp;
    }
}