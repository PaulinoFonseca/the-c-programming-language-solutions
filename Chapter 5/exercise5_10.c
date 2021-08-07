#include <stdio.h>
#include <stdlib.h>  /* for atof() */
#include <ctype.h>   /* for isdigit */

#define MAXOP 100    /* max size of operand or operator */
#define NUMBER '0'   /* signal that a number was found */
#define MAXVAL 100   /* maximum depth of val stack */
#define BUFSIZE 100  /* buffer size for ungetch */

/* function declarations */
int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void reverse(char s[]);

/* reverse Polish calculator */
int main(int argc, char *argv[]) 
{
    int i;
    double op2;
    char s[MAXOP];

    while (--argc > 0){
        ungetch(' ');
        reverse(*++argv);
        for (i = 0; (*argv)[i] != '\0'; ++i) {
            ungetch((*argv)[i]);
        }
        //ungetch((*++argv)[0]);
        switch (getop(s)){
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case 'x':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0){
                    push(pop()/op2);
                }
                else{
                    printf("error: zero divisor\n");
                }
                break;
            case '\n':
                printf("\t%.8g\n",pop());
                break;
            default:
                printf("error: unknown command %s\n",s);
                break;
        }
    }
    printf("\t%.8g\n",pop());
    return 0;
}

/* external variables for push and pop */
int sp = 0;             /* next free stack position */
double val[MAXVAL];     /* value stack */

/* push: push f onto value stack */
void push(double f) 
{
    if (sp < MAXVAL){
        val[sp++] = f;
    }
    else{
        printf("error: stack full, can't push %g\n",f);
    }
}

/* pop: pop and return top value from stack */
double pop(void) 
{
    if (sp > 0){
        return val[--sp];
    }
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* getop: get next operator or numeric operand */
int getop(char s[]) 
{
    int i,c;

    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0'; /* in case no new char is gotten */
    if (!isdigit(c) && c != '.')
        return c; /* not a number */
    i = 0;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    return NUMBER;
}

/* routines called by getop */

/* external variables for getch and ungetch */

char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in vuf */

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

