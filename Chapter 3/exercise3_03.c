#include <stdio.h>
#include <string.h>

#define LEN 100 /* strings' maximum length */

void expand(char s1[], char s2[]);


int main()
{   
    char s1[] = "-a-z0-9-"; 
    char s2[LEN];

    expand(s1,s2);
    printf("%s\n",s2);

    return 0;
}

void expand(char s1[], char s2[])
{
    int i, j, k, a, b;

    k = 0;
    for (i = 0; i < (strlen(s1) - 2); ++i){
        for (a = s1[j = i] ; a == '-'; a = s1[++j]){
            ++i;
        }
        for (b = s1[j = j + 1] ; b == '-'; b = s1[j++])
            ;
        if ((((a >= '0') && (a <= '9')) && ((b >= '0') && (b <= '9'))) || (((a >= 'a') && (a <= 'z')) && ((b >= 'a') && (b <= 'z')))){
            while(a <= b){
                if (k == 0 || a != s2[k-1]){
                    s2[k++] = a;
                }
                ++a;
            }
        }
    }
    s2[k] = '\0';
}