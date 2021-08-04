#include <stdio.h>

#define LEN 10
enum boolean { NO, YES };

/* Answer to theorical question: The two complement
     notation for word_len bits, covers a range of numbers
     from -2^word_len to +2^word_len -1, thus the expression n = -n
     would result in an overflow, if n = -2^word_len */

void itoa(int n, char s[]);
void reverse(char s[]);
int str_len(char s[]);
int abs (int n);

int main()
{
    char s[LEN];

    itoa(-1764,s);
    printf("%s\n",s);
    return 0;
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
    int i, sign;

    if (n < 0) /* record sign */
        //n = -n
        sign = YES;
    else
        sign = NO;
    i = 0;
    do{
        s[i++] = abs(n % 10) + '0';
    } while (abs(n /= 10) > 0);
    if (sign)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s); 
}

/* reverse a string */
void reverse(char s[])
{
    int i, j, temp;

    for (i = 0, j = str_len(s) -1; i < j; i++, j--){
        temp = s[i], s[i] = s[j], s[j] = temp;
    }
}

/* give lenght of string */
int str_len(char s[])
{
    int i;

    for (i = 0; s[i] != '\0'; ++i)
        ;
    return i;
}

/* get abosulte value of n */
int abs (int n)
{
    if (n < 0){
        return -n;
    }
    else{
        return n;
    }
}