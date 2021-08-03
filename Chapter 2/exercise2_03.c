#include <stdio.h>

int htoi(char s[]);
int len(char s[]);

/* test the htoi function */
int main()
{
    int ans;

    ans = htoi("0xF09");
    if (ans+1){
        printf("%d\n",ans);
    }
    else{
        printf("Cannot convert non-hex\n");
    }
    return 0;
}

/* convert a string of hex to decimal 
    only accept hex composed of number and letters
    in upper case from A to F
    
    hex can be written as 0xXXX... or xXXX...
    or even simply XXX..., where X is a digit
    that composes the value of the hex number */
int htoi(char s[])
{
    int i,n, state, hex;
    enum boolean { NO, YES };

    n = 0;
    state = YES;
    hex = 0;
    for (i = 0; i < len(s); ++i){
        if ((s[i-1] == '0' && s[i] == 'x') || (s[i-1] == '0' && s[i] == 'X')){
            ;
        }
        else if (s[i] >= '0' && s[i] <= '9'){
            hex = s[i] - '0';
        }
        else if (s[i] >= 'A' && s[i] <= 'F'){
            hex = (s[i] - 'A') + 10;
        }
        else {
            state = NO;
        }
        n = 16*n + hex; // hex to decimal conversion
    } 
    if (state){
        return n;
    }
    else {
        return -1; // error indicator
    }
}

/* give the length of a string */
int len(char s[])
{
    int i;

    for (i = 0; s[i] != '\0'; ++i){
        ;
    } 
    return i;
}