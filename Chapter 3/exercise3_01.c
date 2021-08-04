#include <stdio.h>
#include <time.h>

#define LEN 5 /* length of sorted array */
#define NUM 6 /* number searched */

/* measure run-time binsearch function */
int binsearch(int x, int v[], int n);

int main()
{
    double time_spent;
    clock_t begin;
    clock_t end;
    int sorted[LEN] = {1,2,3,4,5}; 

    time_spent = 0.0;
    begin = clock();
    binsearch(NUM,sorted,LEN);
    end = clock();
    time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
    printf("The run-time is %f seconds", time_spent);
    return 0;
}

/* binsearch: find x in v[0] <= v[1] <= . . . <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while ((v[mid = (low+high) /2] != x) && low <= high) {
        if (x < v[mid]){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    if (v[mid] == x){
        return mid; /* found match */
    }
    else{
        return -1; /* no match */
    }
}