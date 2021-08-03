#include <stdio.h>

unsigned setbits (unsigned x, int p, int n, unsigned y);

/* testing setbits function */
int main()
{
    unsigned b1;
    unsigned b2;
    int n;
    int p;

    b1 = 0b011100101001010;
    b2 = 0b01100110100;
    n = 2;
    p = 2;

    printf("%u\n",setbits(b1,p,n,b2));

    return 0;
}

/* setbits: set n bits from position */
unsigned setbits (unsigned x, int p, int n, unsigned y)
{
    return ((((x >> (p+1-n)) & (~0 << n)) | ((y & ~(~0 << n)))) << (p+1-n)) | (x & ~(~0 << (p+1-n)));
}