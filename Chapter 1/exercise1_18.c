#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* print input lines longer than 80 characters */
int main()
{
    int len;                /* current line length */
    char line[MAXLINE];     /* current input line */
    
    while ((len = get_line(line, MAXLINE)) > 0){
        
        /* only prints lines that are not blank */
        if (len > 1){
            printf("%s",line);
        }
    }
    return 0;
}

/* getline: read a line into s, return length */
int get_line(char s[], int lim)
{
    int c, i, state,nb, j;

    /* state is the control variable that indicates if
        we are in a blank-zone or not: we enter in a
        blank zone (1) after getting one blank and gets
        out of one (0) if a non-blank characters appears
        
        nb is the counter for the number of blanks encountered
        in the current blank zone */
    state = 0;
    nb = 0;
    for (i=0; i<lim-1 && (c = getchar()) != EOF && c != '\n'; ++i){
        
        /* will only directly add char if is not tab or blank */
        if ( c != '\t' && c != ' ') {

        /* if the last chars were blank and a char that is not blank
            has appeared, than we will add the blank char */
            if (state){
                for (j=nb;j != 0;--j){
                    s[i-j] = ' ';
                }
                nb = 0;
                state = 0;
            }
            s[i] = c;
        }
        else if ( c == ' '){
            state = 1; /* which means that we are in a "blank-zone" */
            ++nb;
        }
        /* if the char is tab, nothing is done
            we decrease i as if this is step of loop has not occurred */
        else if (c == '\t'){
            --i;
        }
    }

    /* if we are in a blank zone, we have not added the
        last blank chars, so we do not count them in i */
    if (c == '\n'){
        i = i - nb;
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}