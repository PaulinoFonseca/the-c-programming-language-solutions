#include <stdio.h>
#include <ctype.h>

#define SIZE 100 /* size of array */
#define BUFSIZE 100

int getint(int *);
int getch(void);
void ungetch(int);

/* test getint function */
int main()
{
    int n, array[SIZE];

    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
        printf("array[%d]: %d\n",n,array[n]); 
}

char buf[BUFSIZE];
int bufp = 0;

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign;

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
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
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