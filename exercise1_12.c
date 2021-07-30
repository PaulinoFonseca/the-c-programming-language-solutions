#include <stdio.h>

/* prints one word of the input per line */
int main()
{
    int c, c_last;

    c_last = '\n';
    while ((c = getchar()) != EOF){
        if (c != ' ' && c != '\n' && c != '\t')
            putchar(c);
        else if (c_last != ' ' && c_last != '\n' && c_last != '\t') 
            putchar('\n');
        c_last = c;
    }
    return 0;
}