/* preprocessing features */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000       /*  max #lines to be sorted */
#define MAXLEN 1000         /* max length of any input line */
#define ALLOCSIZE 10000     /* size of available space */

/* external variables definition */
char *lineptr[MAXLINES];    /* pointers to text lines */
//char allocbuf[ALLOCSIZE];   /* storage for alloc */
//char *allocp = allocbuf;    /* next free position */

/* functions prototypes */
int readlines(char *lineptr[], int maxlines, char *allocbuf);
void writelines(char *lineptr[], int nlines, int n);
int get_line(char *s, int lim);
char *alloc(int n);       
void str_cpy(char *s, char *t);

/* sort input lines */
int main(int argc, char *argv[])
{
    int nlines, n, i, len;             /* number of input lines read */
    char allocbuf[ALLOCSIZE];
    
    ++argv;                     /* ignoring file name */
    for (i = 0; isdigit(*((*argv)+i)); ++i)
        ;
    if (*((*argv)+i) != '\0') {
        printf("error: non-integer input");
        return 1;
    }
    n = atoi(*argv);
    if (((nlines = readlines(lineptr, MAXLINES, allocbuf)) >= 0) && (n < nlines)) {
        //qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines, n);
        return 0;
    }
    else {
        printf("error: incapable of printing the number of lines requested\n");
        return 1;
    }
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* return < 0 if s < t, 0 if s == t, >0  if s > t */
int str_cmp(char *s, char *t)
{
    int i;

    for( ; (*s == *t) && (*s) && (*t); s++, t++)
        ;
    return *s - *t;
}

/* read a line into s, return length */
int get_line(char *s, int lim)
{
    int c;
    char *t = s;        /* first string elem, used to calculate length */

    while ((--lim > 0) && ((c = getchar()) != EOF) && (c != '\n'))
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - t;
}

/* read lines: read input lines */
int readlines(char *lineptr[], int maxlines, char *allocbuf)
{
    int len, nlines;
    char *p, line[MAXLEN];
    char *allocp = allocbuf;

    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (allocbuf + ALLOCSIZE - allocp < len))
            return -1;
        else {
            allocp += len;
            line[len-1] = '\0';     /* delete newline */
            str_cpy(allocp - len, line);
            lineptr[nlines++] = allocp - len;
        }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines, int n)
{
    int i;

    for (i = 1; i <= n; ++i)
        printf("%s\n", lineptr[nlines - i]);
}

/* strcpy: copy t to s; pointer version 3 */
void str_cpy(char *s, char *t)
{
    while (*s++ = *t++)
        ;
}