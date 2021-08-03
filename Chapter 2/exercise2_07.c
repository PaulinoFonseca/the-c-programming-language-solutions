#include <stdio.h>

unsigned invert (unsigned x, int p, int n);

/* testing setbits function */
int main()
{
    unsigned b;
    int n;
    int p;

    b = 0b101101;
    n = 2;
    p = 2;

    printf("%u\n",invert(b,p,n));

    return 0;
}

/* setbits: set n bits from position */
unsigned invert (unsigned x, int p, int n)
{
    return x ^ (~(~0 << n) << (p+1-n));
}