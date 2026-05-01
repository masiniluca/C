#include <stdlib.h>

long long confronti = 0;
long long scambi = 0;

void InsertionSort(int a[], int len) {
    int i, j, tmp;
    for (j = 1; j < len; j++) {
        tmp = a[j];
        i = j - 1;
        while (i >= 0) {
            confronti++;                  
            if (a[i] > tmp) {
                a[i+1] = a[i];
                scambi++;                 
                i--;
            } else {
                break;
            }
        }
        a[i+1] = tmp;
    }
}

void sort(int *arr, int n) {
    confronti = 0;
    scambi = 0;
    InsertionSort(arr, n);
}