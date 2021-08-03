#include <stdio.h>

int bitcount(unsigned x);

/* test bitcount function */
int main()
{
    unsigned word;

    word = 0b0110;
    printf("%d\n", bitcount(word));

    return 0;
}

/* bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
    int b;

    for (b = 0; x; ++b){
        x &= x - 1;
    }
    return b;
}