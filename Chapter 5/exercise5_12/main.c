/* The framework of the following solution is based
on the entab program found on Kernighan & Plauger,
Software Tools (Addison-Wesley, 1976) */

/* preprocessing features */
#include "tab.h"

/* replace strings of blanks with tabs */
main(int argc, char *argv[])
{
    char tab[MAXLINE + 1];

    esettab(argc, argv, tab);    /* initialize tab stops */
    entab(tab);                 /* replace blanks w/ tab */
    return 0;
}

