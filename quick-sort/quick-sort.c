#include <stdio.h>
#include <stdlib.h>

int Partition(int[], int, int);
void Quicksort(int[], int, int);

int main(){
    int array[10] = {4, 3, 1, 2, 6, 5};
    int i;

    printf("Array: 4 3 1 2 6 5");
    Quicksort(array, 0, 5);
    printf("\nArray ordinato: ");
    for(i=0; i<6; i++){
        printf("%d ", array[i]);
    }
    return 0;
}

int Partition(int a[], int lo, int hi){
    int pivot = a[hi];
    int i = lo - 1, j, tmp;

    for(j = lo; j < hi; j++){
        if(a[j] <= pivot){
            i++;
            tmp = a[i]; a[i] = a[j]; a[j] = tmp;
        }
    }
    tmp = a[i+1]; a[i+1] = a[hi]; a[hi] = tmp;
    return i + 1;
}

void Quicksort(int a[], int lo, int hi){
    int p;
    if(lo<hi){
        p=Partition(a, lo, hi);
        Quicksort(a, lo, p-1);
        Quicksort(a, p+1, hi);
    } 
}

