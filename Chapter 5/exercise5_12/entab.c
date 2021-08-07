#include "tab.h"

/* entab: replace strings of blanks with tabs and blanks */
void entab(char *tab)
{
    int c, pos;
    int nb = 0;
    int nt = 0;

    for (pos = 1; (c = getchar()) != EOF; pos++)
        if (c == ' ') {
            if (tabpos(pos, tab) == NO)
                ++nb;                   /* increment of blanks */
            else {
                nb = 0;
                ++nt;
            }
        }
        else {
            for (; nt > 0; nt--)
                putchar('\t');  /* output tab(s) */
            if (c == '\t')      /* forget the blank(s) */
                nb = 0;
            else
                for ( ; nb > 0; nb--)
                    putchar(' ');
            putchar(c);
            if (c == '\n')
                pos = 0;
            else if (c == '\t')
                while (tabpos(pos, tab) != YES)
                    ++pos;
        }
}