#include <stdio.h>
#include <string.h>

void reverse(char s[],int init, int lim);

int main()
{
    char line[] = "julia";
    reverse(line,0,strlen(line) - 1);
    printf("%s\n",line);

    return 0;
}

/* reverse the string s in place */
void reverse(char s[],int init, int lim)
{
    int i, j, temp;

    if (init <= lim){
        temp = s[lim], s[lim] = s[init], s[init] = temp;
        reverse(s,++init,--lim);
    }
    return;
}