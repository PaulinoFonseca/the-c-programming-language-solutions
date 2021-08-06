#include <stdio.h>
#include <string.h>

int strrindex(char s[], char t[]);


/* test strrindex function */
int main()
{
    char s[] = "fast as shark";
    char t[] = "fast";

    printf("%d\n",strrindex(s,t));

    return 0;
}

/* return the position of the rightmost
    occurrence of t in s, or -1 if there is none */
int strrindex(char s[], char t[])
{
    int i, j, k;

    for (i = strlen(s) - 1; i != 0; --i){
        for (j = i, k = strlen(t) - 1; k != 0 && s[j] == t[k]; --j, --k)
            ;
        if (k == 0){
            return i;
        }
    }
    return -1;
}