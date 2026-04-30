#include <stdio.h>
#include <stdlib.h>
#define MAX 20

void InsertionSort(int[], int);

int main(){
	int array[MAX] = {5, 4, 3, 2, 1};
	int i;

	printf("Array: 5 4 3 2 1");
	InsertionSort(array, 5);
	printf("\nArray ordinato: ");
	for(i=0; i<5; i++){
		printf("%d ", array[i]);
	}
	return 0;
}

void InsertionSort(int a[], int len){
	int i, j, tmp;
	for(j=1; j<len; j++){
		tmp=a[j];
		i=j-1;
		while(i>=0 && a[i]>tmp){
			a[i+1]=a[i];
			i--;
		}
		a[i+1]=tmp;
	}
}
