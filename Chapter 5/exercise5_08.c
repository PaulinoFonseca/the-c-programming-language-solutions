/* preprocessing features */
#include <stdio.h>

/* external definitions */
static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* function prototypes */
int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

/* main: test day_of_year and month_day functions */
int main()
{
    int y, m, d, *pm, *pd, yd;

    y = 1900;
    m = 4;
    d = 20;
    pd = &d;
    pm = &m;
    yd = 367;

    printf("%d\n",day_of_year(y,m,d));
    month_day(y,yd,pm,pd);
    printf("%d,%d\n",m,d);
    return 0;
}

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    int i, leap;

    leap = (year%4 == 0) && (year%100 != 0) || (year%400 == 0);
    if ((month < 1) || (month > 12) || (day < 1) || (day > daytab[leap][month])) {
        printf("invalid date\n");
        return -1;
    }
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

/* month_day: set month, day from day of year */
void month_day (int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = (year%4 == 0) && (year%100 != 0) || (year%400 == 0);
    if ((yearday < 1) || (yearday > 366) || ((yearday > 365) && (!leap))) {
        printf("invalid yearday\n");
        return;
    }
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}

