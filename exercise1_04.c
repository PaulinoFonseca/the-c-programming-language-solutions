# include <stdio.h>

/* print Celsius-Fahrenheit table
    for celsius = 0, 20, ..., 300; floating-point version */
int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;       /* lower limit of temperature table */
    upper = 300;     /* upper limit */
    step = 20;       /* step size */

    printf("\nCelsius-Fahrenheit table\n\n");

    celsius = lower;
    while (celsius <= upper) {
        fahr = (1.8 * celsius ) + 32;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
    return 0;
}