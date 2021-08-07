#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "calc.h"

#define MAXLINE 20      /* maximum input line size */

/* function prototypes */
int get_line(char *s, int lim);
void reverse(char s[]);
int strrindex(char *s, char *t);
int getop(char s[]);


/* test getline, reverse, strrindex, getop function */
int main()
{
    /* test getline */
    char input[MAXLINE];

    get_line (input, MAXLINE);
    printf("%s",input);

    /* test reverse */
    char line[] = "julia";
    
    reverse(line);
    printf("%s\n",line);

    /* test strrindex */
    char s[] = "fast as shark";
    char t[] = "fast";

    printf("%d\n",strrindex(s,t));

    /* test getop */
    char test[20];
    
    getop(test);
    printf("%s\n",test);

    return 0;
}

/* read a line into s, return length */
int get_line(char *s, int lim)
{
    int c;
    char *t = s;        /* first string elem, used to calculate length */

    while ((--lim > 0) && ((c = getchar()) != EOF) && (c != '\n'))
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - t;
}

/* reverse the string s in place */
void reverse(char s[])
{
    char *i;
    int temp;

    i = s;                          /* saving the address of the beginning of the array */
    while(*s){                      /* increment s until the end of the string '\0' is reached */
        ++s;
    }
    --s;                            /* throwing away '\0' from reversing, since it will still save the end of the string */

    for ( ; i <= s; ++i, --s){      /* swapping string members, until all of them have been swapped (unless the '\0' terminator) */
        temp = *s, *s = *i, *i = temp;
    }
    return;
}

/* return the position of the rightmost
    occurrence of t in s, or -1 if there is none */
int strrindex(char *s, char *t)
{
    char *t_last, *s_init, *t_init, *p;

    s_init = s;                               /* original s address */
    t_init = t;                               /* original t address */

    while(*s){
        ++s;
    }
    --s;                                      /* discarding string terminator from comparison */
    while(*t){
        ++t;
    }
    --t;                                      /* discarding string terminator from comparison */
    t_last = t;
    for ( ; s != s_init; --s){
        for (t = t_last, p = s;(p != s_init) && (t != t_init) && (*p == *t); --t, --p)
            ;
        if (t == t_init){
            return s - s_init;
        }
    }
    return -1;
}

/* getop: get next operator or numeric operand */
int getop(char s[]) 
{
    int c;

    while((*s = c = getch()) == ' ' || c == '\t')
        ;
    *(s+1) = '\0'; /* in case no new char is gotten */
    if (!isdigit(c) && c != '.')
        return c; /* not a number */
    if (isdigit(c)) /* collect integer part */
        while (isdigit(*++s = c = getch()))
            ;
    if (c == '.') /* collect fraction part */
        while (isdigit(*++s = c = getch()))
            ;
    *s = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}