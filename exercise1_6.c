#include <stdio.h>

/* print the integer value 
    of the getchar() != EOF expression.
    If the expression is True, meaning that getchar()
    is indeed not EOF, the printed value will be 1.
    
    If the expression is False, meaning that getchar()
    is EOF, the printed value will be 0.
    
    Hence, the expression can only return either 0 or 1 */

int main()
{   
    printf("%d\n",getchar() != EOF);
    return 0;
}

/* Note: Press Cntrl + D 
    in order to use EOF as the input
    in UNIX-like systems */