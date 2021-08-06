#include <stdio.h>
#include <stdlib.h>  /* for atof() */
#include <ctype.h>   /* for isdigit */
#include <math.h>    /* for exp and pow */

#define MAXOP 100    /* max size of operand or operator */
#define NUMBER '0'   /* signal that a number was found */
#define MAXVAL 100   /* maximum depth of val stack */
#define BUFSIZE 100  /* buffer size for ungetch */
#define MAXLEN 100   /* line size for getop */
enum boolean { NO, YES };

/* function declarations */
int getop(char []);
void push(double);
double pop(void);
void clear(void);
void swap (void);
int getch(void);
void ungetch(int);
int get_line(char s[], int lim);

/* external variables */
char line[MAXLEN]; /* line array */
int lp = 0; /* line position */
int defined = NO; /* state of getting new-line */

/* reverse Polish calculator */
int main() 
{
    int type;
    double op2, x, v;
    char s[MAXOP];
    //char line[MAXLEN];

    x = 0.0;
    v = 0.0;
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
                v = pop();
                printf("\t%.8g\n",v);
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
            case 'x':
                push(x);
                break;
            case '=':
                op2 = pop();
                pop();  /* discard old x value */
                x = op2;
                break;
            case 'v':
                push(v);
                break;
            case '\0':
                defined = NO;
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

    if (!defined){
        if (get_line(line, MAXLEN) == 0){ /* getting a newline */
            return EOF;
        }
        lp = 0;
        defined = YES;
    }

    while((s[0] = c = line[lp++]) == ' ' || c == '\t')
        ;
    s[1] = '\0'; /* in case no new char is gotten */
    if (c == '-'){
        d = line[lp]; /* checking for the next char */ 
        if (!isdigit(d))
            return '-'; /* minus operator */       
    }
    else if (!isdigit(c) && c != '.' ){
        return c; /* not a number */
    }    
    i = 0;
    if (isdigit(c) || (c == '-')){ /* collect integer part */
        while (isdigit(s[++i] = c = line[lp++]))
            ;
    }
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = line[lp++]))
            ;
    s[i] = '\0';
    --lp;
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

/* getline: read a line into s, return length */
int get_line(char s[], int lim)
{
    int c, i;

    for (i =0; (i < lim -1) && ((c = getchar()) != EOF) && (c != '\n'); ++i){
        s[i] = c;
    }
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}