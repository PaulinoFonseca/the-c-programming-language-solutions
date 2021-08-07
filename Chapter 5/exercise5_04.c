#include <stdio.h>

int strend(char *s, char *t);

int main()
{   
    char nw[] = "Abrudk";
    char cp[] = "rudk";

    printf("%d\n",strend(nw,cp));

    return 0;
}

int strend(char *s, char *t)
{
    int i,j;

    while(*s){
        ++s;
    }
    --s;
    for(i = 0; *t; ++t, ++i)
        ;
    --t;
    for(j = 0; (*s == *t) && (i > j); --s, --t, ++j)
        ;
    if (i == j){
        return 1;
    }
    else{
        return 0;
    }
}
