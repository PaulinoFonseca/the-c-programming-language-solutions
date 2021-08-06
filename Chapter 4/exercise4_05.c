#include <stdio.h>
#include <stdlib.h>  /* for atof() */
#include <ctype.h>   /* for isdigit */
#include <math.h>    /* for exp and pow */

#define MAXOP 100    /* max size of operand or operator */
#define NUMBER '0'   /* signal that a number was found */
#define MAXVAL 100   /* maximum depth of val stack */
#define BUFSIZE 100  /* buffer size for ungetch */

/* function declarations */
int getop(char []);
void push(double);
double pop(void);
void clear(void);
void swap (void);
int getch(void);
void ungetch(int);


/* reverse Polish calculator */
int main() 
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF){
        switch (type){
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
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
            case '%':
                op2 = pop();
                if (op2 != 0.0){
                    push(fmod(pop(),op2));
                }
                else{
                    printf("error: zero divisor\n");
                }
                break;
            case '\n':
                printf("\t%.8g\n",pop());
                break;
            case 't': /* print top element of stack */
                op2 = pop();
                printf("top element of stack:%g\n",op2);
                push(op2);
                break;
            case 'c': /* clear the stack */
                clear();
                break;
            case 's': /* swap the top two elements of stack */
                swap();
                break;
            case 'd': /* duplicate top element of stack */
                op2 = pop();
                push(op2);
                push(op2);
                break;
            case 'e': /* exponential */
                push(exp(pop()));
                break;
            case 'p': /* power */
                op2 = pop();
                op2 = pow(pop(),op2); 
                push(op2);
                break;
            case 'S': /* sine */
                op2 = sin(pop());
                push(op2);
                break;
            case 'C': /* cosine */
                op2 = cos(pop());
                push(op2);
                break;
            default:
                printf("error: unknown command %s\n",s);
                break;
        }
    }
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

/* clear: clear the stack */
void clear(void)
{
    sp = 0;
}

void swap(void)
{
    double temp;

    if (sp > 1){
        temp = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = temp;
    }
    else{
        printf("error: stack length is less than two");
    }
}

/* getop: get next operator or numeric operand */
int getop(char s[]) 
{
    int i,c,d;

    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0'; /* in case no new char is gotten */
    if (c == '-'){
        d = getch(), ungetch(d); /* checking for the next char */ 
        if (!isdigit(d))
            return '-'; /* minus operator */       
    }
    else if (!isdigit(c) && c != '.' ){
        return c; /* not a number */
    }    
    i = 0;
    if (isdigit(c) || (c == '-')){ /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
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

