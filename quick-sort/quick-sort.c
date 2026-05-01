#include <stdlib.h>

long long confronti = 0;
long long scambi = 0;

int Partition(int a[], int lo, int hi) {
    int pivot = a[hi];
    int i = lo - 1, j, tmp;

    for (j = lo; j < hi; j++) {
        confronti++;                              
        if (a[j] <= pivot) {
            i++;
            tmp = a[i]; a[i] = a[j]; a[j] = tmp;
            scambi++;                             
        }
    }
    tmp = a[i+1]; a[i+1] = a[hi]; a[hi] = tmp;
    scambi++;                                     
    return i + 1;
}

void Quicksort(int a[], int lo, int hi) {
    int p;
    if (lo < hi) {
        p = Partition(a, lo, hi);
        Quicksort(a, lo, p - 1);
        Quicksort(a, p + 1, hi);
    }
}

void sort(int *arr, int n) {
    confronti = 0;
    scambi = 0;
    Quicksort(arr, 0, n - 1);
}

