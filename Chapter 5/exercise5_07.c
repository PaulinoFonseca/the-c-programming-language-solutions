/* preprocessing features */
#include <stdio.h>

#define MAXLINES 5000       /*  max #lines to be sorted */
#define MAXLEN 1000         /* max length of any input line */
#define ALLOCSIZE 10000     /* size of available space */

/* external variables definition */
char *lineptr[MAXLINES];    /* pointers to text lines */
//char allocbuf[ALLOCSIZE];   /* storage for alloc */
//char *allocp = allocbuf;    /* next free position */

/* functions prototypes */
int readlines(char *lineptr[], int maxlines, char *allocbuf);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);
int get_line(char *s, int lim);
char *alloc(int n);       
void str_cpy(char *s, char *t);

/* sort input lines */
int main()
{
    int nlines;             /* number of input lines read */
    char allocbuf[ALLOCSIZE];

    if ((nlines = readlines(lineptr, MAXLINES, allocbuf)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr,nlines);
        return 0;
    }
    else {
        printf("error: input too big to sort\n");
        printf("%d\n",1);
        return 1;
    }
}

void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char  *v[], int i, int j);
    int str_cmp(char *s, char *t);

    if (left >= right)  /* do nothing if array contains */
        return;         /* fewer than two elements */
    swap(v, left, (left + right)/2);    /* move partition elem */
    last = left;                        /* to v[0] */
    for (i = left + 1; i <= right; i++) /* partition */
        if (str_cmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);    /* restore partition elem */
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
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
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

/* strcpy: copy t to s; pointer version 3 */
void str_cpy(char *s, char *t)
{
    while (*s++ = *t++)
        ;
}