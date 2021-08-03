#include <stdio.h>

#define MAX 10
#define TAB 8

int main(){
    char c, i, j;
    char line[MAX];
    char line_aux[MAX];

    i = 0;
    while ((c = getchar()) != EOF){
        if (c == '\n'){
            i = 0;
        }
        if (i<10){
            if (c == '\t'){
                for ( ; (i%TAB != 0) && (i<10); ++i){
                    putchar(' ');
                }
            }
            else {
                putchar(c);
            }
        }
        else {
            if (c != ' '){
                putchar('-');
            }
            putchar('\n');
            putchar(c);
            i = 0;
        }
        ++i;
    }
    
    return 0;
}