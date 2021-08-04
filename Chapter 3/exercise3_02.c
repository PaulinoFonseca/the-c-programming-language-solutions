#include <stdio.h>

#define LEN 100 /* length of strings */

void escape(char s[], char t[]);
void runescape (char s[], char t[]);

/* test escape and runescape functions */
int main()
{
    char s[LEN] = "Having\ta good time?\n";
    char t[LEN];
    char c[LEN];

    escape(s,t);
    printf("%s\n",t);

    runescape(t,s);
    printf("%s",s);

    return 0;
}

/* convert newline and tab chars to \n and \t
    while copy the string t to s*/
void escape(char s[], char t[])
{
    int i, j;

    for (i = j = 0; s[i] != '\0'; ++i){
        switch(s[i]){
            case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                break;
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                break;
            default:
                t[j++] = s[i];
                break;
        }
    }
    t[j] = '\0';
}

/* do the opposite of escape s*/
void runescape (char s[], char t[])
{
    int i, j;

    for (i = j = 0; s[i] != '\0'; ++i){
        if (s[i] == '\\'){
            switch(s[++i]){
                case 't':
                    t[j++] = '\t';
                    break;
                case 'n':
                    t[j++] = '\n';
                    break;
                default:
                    t[j++] = '\\';
                    t[j++] = s[i];
                    break;
            }
        }
        else{
            t[j++] = s[i];
        }
    }
    t[j] = '\0';
}