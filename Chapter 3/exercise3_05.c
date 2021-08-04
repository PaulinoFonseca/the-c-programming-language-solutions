#include <stdio.h>

#define LEN 100 /* length of string */
enum boolean { NO, YES };

void itob(int n, char s[], int b);
void reverse(char s[]);
int str_len(char s[]);
int abs (int n);

int main()
{
    char s[LEN];

    itob(-1764,s, 16);
    printf("%s\n",s);
    return 0;
}

/* itob: convert integer n to base b
    in particular, itob(n,s,16) format n as
    a hexadecimal integer in s */
void itob(int n, char s[], int b)
{
    int i, sign, temp;

    if (n < 0) /* record sign */
        //n = -n
        sign = YES;
    else
        sign = NO;
    i = 0;
    do{
        temp = abs(n % b) + '0';
        if ((b == 16) && (temp > '9')){
            switch (temp){
                case '9' + 1:
                    s[i++] = 'A';
                    break;
                case '9' + 2:
                    s[i++] = 'B';
                    break;
                case '9' + 3:
                    s[i++] = 'C';
                    break;
                case '9' + 4:
                    s[i++] = 'D';
                    break;
                case '9' + 5:
                    s[i++] = 'E';
                    break;
                default:
                    s[i++] = 'F';
                    break;
            }

        }
        else{
            s[i++] = temp;
        }       
    } while (abs(n /= b) > 0);
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