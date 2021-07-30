#include <stdio.h>

/* print frequencies
    of different input characters */
int main()
{
    int c, n, nmax;
    n = 'z' - 'a' + 1;
    int nchar[n];

    for (int i = 0; i < n; i++){
        nchar[i] = 0;
    }
    while ((c = getchar()) != EOF){
        if (c >= 'a' && c <= 'z'){
            ++nchar[c-'a'];
        }
    }

    /* finds the maximum number of appearances
         among all letters from a-z */
    nmax = nchar[0];
    for (int j = 1; j < 10; j++){
        if (nmax < nchar[j])
            nmax = nchar[j];
    }

    /* plots the histogram, giving a "#" for each letter
         that appears more or equal than k
         with k starting at the maximum number of appearance
         and then decreasing until it reaches 1 */
    for (int k = nmax; k > 0; k--){
        for (int m = 0; m < n; m++){
            if (nchar[m] >= k){
                printf("#");
                printf(" ");
            }
            else {
                printf("  ");
            }
        }
        printf("\n");    
    }
    
    /* creates the last row of the histogram
         made of the characters a-z divided by a blank between them */
    for (char k = 'a'; k <= 'z'; k++){
        putchar(k);
        printf(" ");
    }
    printf("\n");
    return 0;
}