#include <stdio.h>

#define LENGTH 20

void squeeze(char s1[], char s2[]);

/* testing the squeeze function */
int main()
{
    char line1[LENGTH] = "banana";
    char line2[LENGTH] = "pijamas";

    squeeze(line1,line2);
    printf("%s\n",line1);

    return 0;
}

/* squeeze: delete all s2 chars from s1 */
void squeeze(char s1[], char s2[])
{
    int i, j, k;

    for (k = 0; s2[k] != '\0'; ++k){
        for (i = j = 0; s1[i] != '\0'; ++i){
            if (s1[i] != s2[k]){
                s1[j++] = s1[i];
            }
        }
        s1[j] = '\0';
    }
}