#include <stdio.h>

#define IN 1    /* inside a word */
#define OUT 0   /* outside a word */

/* print a histogram of lengths of input words */
int main()
{
    int c, state, nmax, nc; 

    int nwords[10];
    for (int i = 0; i < 10; i++)
        nwords[i] = 0;
    nc = 0;
    state = IN;
    while((c = getchar()) != EOF){
        if (c == ' ' || c == '\n' || c == '\t'){
            state = OUT;
        }
        else if (state == OUT) {
            state = IN;
            if (nc >= 1 && nc <= 9){
                ++nwords[nc-1];
            }
            else{
                ++nwords[9];
            }
            nc = 0;
        }
        if (c != ' ' && c != '\n' && c != '\t'){
            ++nc;
        }
    }
    if (nc >= 1 && nc <= 9){
        ++nwords[nc-1];
    }
    else{
        ++nwords[9];
    }
    
    /* finds the maximum number of appearances
         among all words */
    nmax = nwords[0];
    for (int j = 1; j < 10; j++){
        if (nmax < nwords[j])
            nmax = nwords[j];
    }
    
    /* plots the histogram, giving a "#" for each word
         that appears more or equal than k
         with k starting at the maximum number of appearance
         and then decreasing until it reaches 1 */
    for (int k = nmax; k > 0; k--){
        for (int m = 0; m < 10; m++){
            if (nwords[m] >= k){
                printf("#");
                printf(" ");
            }
            else {
                printf("  ");
            }
        }
        printf("\n");    
    }
    printf("1 2 3 4 5 6 7 8 9 9+\n");
    return 0;
}