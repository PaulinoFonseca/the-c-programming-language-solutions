#include <stdio.h>
#include <ctype.h>

enum boolean { NO, YES};

double atof(char s[]);

int main()
{
    char s[] = "123.45e+6";
    printf("%.8f\n",atof(s));
    return 0;
}

/* atof: convert string s to double */
double atof(char s[])
{
    double val, power;
    int i, sign, esign, eval, epower;

    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-'){
        i++;
    }
    for (val = 0.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.'){
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if ((s[i] == 'e') || (s[i] == 'E')){
        ++i;
        esign = (s[i] == '-') ? YES : NO;
        if (esign){
            ++i;
        }
        else{
            if (s[i] == '+'){
                ++i;
            }
        } 
        for (eval = 0; s[i] != '\0'; ++i){
            eval = 10 * eval + (s[i] - '0');
        }
        epower = 1;
        while (eval){
            epower *= 10; 
            --eval;
        }
        if(esign){
            return sign * ((double ) (val / power) / epower);
        }
        else{
            return sign * ((double) (val / power) * epower);
        }        
    }
    return sign * val / power;
}