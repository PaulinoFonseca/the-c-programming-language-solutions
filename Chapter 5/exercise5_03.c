#include <stdio.h>

void str_cat(char *s, char *t);

/* test strcat function */
int main()
{
    char line1[] = "oi";
    char line2[] = ", tudo bem?";
    str_cat(line1,line2);

    printf("%s\n",line1);

    return 0;
}

/* copy the string t to the end of s */
void str_cat(char *s, char *t)
{
    while(*s++)
        ;
    --s;
    while(*s++ = *t++)
        ;
}