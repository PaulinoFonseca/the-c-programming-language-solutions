#include <stdio.h>

#define IN 0
#define OUT 1

int main() /* */
{
    char c, d, c_last, state, state2;

    c_last = '/';
    state = OUT;
    state2 = OUT;
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
            if (c == '/'){
                c_last = c;
                c = getchar();
                if (c == '/'){
                    state2 = IN;
                }
                else if (c == '*'){
                    state = IN;
                }
                else{
                    putchar(c_last);
                    putchar(c);
                }
            }
            else{
                putchar(c);
            }
        }
        c_last = c;
    }
}
