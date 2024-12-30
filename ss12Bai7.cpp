#include <stdio.h>
#define max 100

void printArray(int arr[max][max],int *m, int *n);

int main(void){
	int arr[max][max];
	int m,n;
	
	printArray(arr,&m,&n);
	
	return 0;
};

void printArray(int arr[max][max],int *m, int *n){
	printf("Nhap gia tri cot: ");
	scanf("%d",m);
	printf("\nNhap gia tri dong: ");
	scanf("%d",n);
	
	for(int i=0; i<*m; i++){
		for(int j=0; j<*n; j++){
			printf("\nNhap array[%d][%d]",i,j);
			scanf("%d",&arr[i][j]);
		}
	}
	printf("\n matrix vua nhap la\n");
	for(int i=0; i<*m; i++){
		for(int j=0; j<*n; j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
};
