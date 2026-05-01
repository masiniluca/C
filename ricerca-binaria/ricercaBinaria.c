#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int RicercaBinaria(int[], int, int, int);

int main(){
	int i, n;
	int arr[MAX]= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	printf("Inserire il target: ");
	scanf("%d", &n);
	i=RicercaBinaria(arr, n, 0, 9);
	if(i>=0){
		printf("Il target cercato esiste ed è in posizione %d nell'array.", i);
	}
	else{printf("Il target cercato non esiste nell'array.");}
	return 0;
}

int RicercaBinaria(int v[], int n, int i, int j){
	int mid;
	if(i>j){return -1;}
	mid=(j+i)/2;

	if(v[mid]==n){return mid;}
	else if(n>v[mid]){return RicercaBinaria(v, n, mid+1, j);}
	else if(n<v[mid]){return RicercaBinaria(v, n, i, mid-1);}	
}	