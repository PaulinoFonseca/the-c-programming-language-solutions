/* preprocessing features */

/* includes */
#include <stdio.h>
#include <stdlib.h>

/* macros */
#define MAXLINE     100     /* maximum line size */
#define TABINC      8       /* default tab increment size */
enum boolean { NO, YES };

/* function prototypes */
void esettab(int argc, char *argv[], char *tab);
void entab(char *tab);
int tabpos(int pos, char *tab);