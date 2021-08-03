#include <stdio.h>

#define MAXLINE 1000
/* number of blanks in a row that make a tab */
#define N 8

int get_line(char s[], int max);

/* replace tabs in the input
    with the proper number of blanks */
int main()
{
    int i, c, n_tab, n_b;

    for (i = 1; (c = getchar()) != EOF; ++i){
        if ( c == ' '){
            if (i%N == 0){
                n_b = 0;
                ++n_tab;
            }
            else{
                ++n_b;
            }
        }
        else{
            for ( ; n_tab > 0; --n_tab){
                putchar('\t');
            }
            if (c == '\t'){
                n_b = 0;
            }
            else {
                for ( ; n_b > 0; --n_b){
                    putchar(' ');
                }
            }
            putchar(c);
            if (c == '\n'){
                i = 0;
            }
            else if (c == '\t'){
                i = i + (N - (i-1) % N) -1;
            }

        }

    }

    
    return 0;
}

