#include <stdio.h>

int main(void){
	int arr[5];
	
	for(int i = 0 ; i<5 ; i++){
		printf("Nhap array[%d]",i);
		scanf("%d",&arr[i]);
	}
	for(int i = 0 ; i<5 ; i++){
		printf("\nNhap phan tu vua nhap la %d",arr[i]);
	}
	return 0;
}



