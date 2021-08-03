#include <stdio.h>

#define MAX 11


/* print the first (MAX-1) number of char of input */
int main()
{
    char i, c, s[MAX];

    for (i=0; (i < MAX-1)*((c = getchar()) != '\n')*(c!= EOF); ++i){
        s[i] = c;

    }
    s[MAX-1] = '\0';
    printf("%s\n",s);
    return 0;
}