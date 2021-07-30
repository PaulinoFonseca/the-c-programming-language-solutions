#include <stdio.h>

/* replace string of one or more blank 
    by a single blank */
int main()
{
    int c, c_last;

    c_last = '\n';

    while((c = getchar()) != EOF){
        if(c_last != ' ' || c != ' ')
            putchar(c);
        c_last = c;
    }
    return 0;
}