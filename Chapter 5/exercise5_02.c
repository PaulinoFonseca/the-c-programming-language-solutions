#include <stdio.h>
#include <ctype.h>

#define SIZE 100 /* size of array */
#define BUFSIZE 100

int getint(double *);
int getch(void);
void ungetch(int);

/* test getint function */
int main()
{
    int n;
    double array[SIZE];

    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
        printf("array[%d]: %g\n",n,array[n]); 
}

char buf[BUFSIZE];
int bufp = 0;

/* getint: get next integer from input into *pn */
int getint(double *pn)
{
    int c, sign;
    double power;    

    while(isspace(c = getch())) /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-'){
        ungetch(c); /* it's not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if((c == '+' || c == '-') && (!isdigit(c = getch()))){
        ungetch(c); /* it's not a number */
        return 0;
    }
    for(*pn = 0; isdigit(c); c = getch())
        *pn = 10.0 * *pn + (c - '0');
    if (c == '.')
        c = getch(); /* skip the decimal point */
    for (power = 1.0; isdigit(c); c = getch(), power *= 10.0){
        *pn = 10.0 * *pn + (c - '0');
    }

    *pn *= (sign / power);
    if(c != EOF)
        ungetch(c);
    return c;
}

int getch(void)     /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}