#include <stdio.h>

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300; floating-point version */

float fahr2cel (int fahr);

int main()
{   
    int fahr;

    for (fahr = 0; fahr <= 300; fahr = fahr + 20){
        printf("%3d %6.1f\n", fahr, fahr2cel(fahr));
    }
    return 0;
}

float fahr2cel (int fahr)
{
    return (5.0)/(9.0) * (fahr-32.0);
}