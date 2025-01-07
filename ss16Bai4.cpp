#include <stdio.h>
#include <stdlib.h>
void printingArray(int *arr, int n);

int main(void){
	int n,*arr;
	printf("nhap size : ");
	scanf("%d", &n);
	
	arr = (int *) malloc(n * sizeof(int));
	
	for(int i=0; i<n; i++){
		printf("Nhap array[%d]= ", i);
		scanf("%d", (arr+i));
	}
	printingArray(arr,n);
	
	return 0;	
};
void printingArray(int *arr, int n){
	for(int i=0; i<n; i++){
		printf("\narray[%d] = %d", i, *(arr+i));
	}
};
