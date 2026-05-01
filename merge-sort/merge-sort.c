#include <stdlib.h>

long long confronti = 0;
long long scambi = 0;

void Merge(int a[], int p, int q, int r){
    int i, j, k;
    int len1 = q-p+1;
    int len2 = r-q;
    int *l = malloc(len1*sizeof(int));
    int *rr = malloc(len2*sizeof(int));
    for(i=0; i<len1; i++){
        l[i]=a[p+i];
    }
    for(i=0; i<len2; i++){
        rr[i]=a[q+i+1];
    }
    i=0; j=0;
    for(k=p; k<=r; k++){
        if(i<len1 && j<len2){
            confronti++;
        }
        if (i < len1 && (j >= len2 || l[i] <= rr[j])) {
            a[k] = l[i++];
        } else {
            a[k] = rr[j++];
        }
    }
    free(l);
    free(rr);
}

void Mergesort(int a[], int p, int r){
    int q;
    if(p<r){
        q=(p+r)/2;
        Mergesort(a, p, q);
        Mergesort(a, q+1, r);
        Merge(a, p, q, r);
    }
}

void sort(int *arr, int n) {
    confronti = 0;
    scambi = 0;
    Mergesort(arr, 0, n - 1);
}