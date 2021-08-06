#include <stdio.h>

#define MAXLEN 100 /* max length of string */

void itoa(int n, char s[]);

int main()
{
    char line[MAXLEN];

    itoa(-1792,line);
    printf("%s\n",line);

    return 0;
}


/* itoa: convert n in decimal to string */
void itoa(int n, char s[])
{
    static int i = 0;

    if (n < 0){
        s[i++] = '-';
        n = -n;
    }
    if (n / 10)
        itoa(n / 10, s);
    s[i++] = n % 10 + '0';
    s[i] = '\0';
}