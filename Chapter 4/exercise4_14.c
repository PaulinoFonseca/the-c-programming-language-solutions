#include <stdio.h>

/* interchange two arguments of type t */
#define swap(t,x,y) {   t temp;     \
                        temp = y;   \
                        y = x;      \
                        x = temp; }

/* test swap macro */
int main()
{
    int a = 0;
    int b = 1;

    swap(int,a,b);
    printf("a: %d, b: %d\n",a,b);
    return 0;
}