#include <stdio.h>

void lower(void);

/* test lower function */
int main()
{
    lower();
    return 0;
}

/* convert upper case chars to lower case */
void lower(void)
{
    char c;

    while((c = getchar()) != EOF){
        (c >= 'A' && c <= 'Z') ? putchar(c - 'A' + 'a') : putchar(c);
    }
}