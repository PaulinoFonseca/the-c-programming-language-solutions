#include <stdio.h>

unsigned rightrot(unsigned x, int n);
int word_len(int num);

/* testing setbits function */
int main()
{
    unsigned b;
    int n;

    b = 0b110101;
    n = 2;

    printf("%u\n",rightrot(b,n));

    return 0;
}

/* setbits: set n bits from position */
unsigned rightrot (unsigned x, int n)
{
    return (x >> n) | ((x & ~(~0 << n)) << (word_len(x) - n));
}

int word_len (int num)
{
    int i,c;
    c = 1;
    for (i = 0; num >= c; ++i){
        c = 2*c;
    }
    return i;
}