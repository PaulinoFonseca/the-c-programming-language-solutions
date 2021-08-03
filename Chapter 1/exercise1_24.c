#include <stdio.h>

#define IN 0
#define OUT 1

int main() /* */
{
    char c, c_last, state, state2,num_par,num_brk,num_bra;

    c_last = '/';
    state = OUT;
    state2 = OUT;
    num_par = num_brk = num_bra = 0;
    while ((c = getchar()) != EOF){
        if ((c_last == '\n') && (state2 == IN)){
            state2 = OUT;
        }
        else if ((c_last == '/') && (c == '*')){
            state = IN;
        }
        else if ((c_last == '/') && (c == '/')){
            state2 = IN;
        }
        else if ((c_last == '*') && (c == '/')){
            state = OUT;
        }
        else if ((state) && (state2)){
            if (c == '('){
                ++num_par;
            }
            else if (c == ')'){
                --num_par;
            }
            else if (c == '['){
                ++num_brk;
            }
            else if (c == ']'){
                --num_brk;
            }
            else if (c == '{'){
                ++num_bra;
            }
            else if (c == '}'){
                --num_bra;
            }
        }
        c_last = c;
    }
    if (num_par != 0){
        printf("Unbalanced parentheses\n");
    }
    if (num_brk != 0){
        printf("Unbalanced brackets\n");
    }
    if (num_bra != 0){
        printf("Unbalanced braces\n");
    }
    return 0;
}
