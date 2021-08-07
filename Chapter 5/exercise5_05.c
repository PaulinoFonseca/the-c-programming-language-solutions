#include <stdio.h>

#define N 3

void str_cat(char *s, char *t, int n);
void str_cpy(char *s, char *t, int n);
int str_cmp(char *s, char *t);

/* test str_cat and str_cpy function */
int main()
{
    char line1[20] = "hi";
    char line2[] = ", how you doing?";
    char line3[20];
    printf("%s\n",line2);
    str_cat(line1, line2, N);
    printf("%s\n",line2);
    printf("%s\n",line1);
    str_cpy(line3,line2,N);
    printf("%s\n",line3);
    printf("%d\n",str_cmp(line1, line2));

    return 0;
}

/* copy the string t to the end of s */
void str_cat(char *s, char *t, int n)
{
    int i;

    while(*s)
        ++s;
    for(i = 0; (i < n) && (*s++ = *t++); ++i)
        ;
    if (i == n){
        *s = '\0';
    }
}

/* copy t to s; pointer version 3 */
void str_cpy(char *s, char *t, int n)
{
    int i;

    for(i = 0; (i < n) && (*s++ = *t++); ++i)
        ;
    if (i == n){
        *s = '\0';
    }
}

/* return < 0 if s < t, 0 if s == t, >0  if s > t */
int str_cmp(char *s, char *t)
{
    int i;

    for( ; (*s == *t) && (*s) && (*t); s++, t++)
        ;
    return *s - *t;
}