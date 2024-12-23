#include <stdio.h>
int arr[100];
int main(void){
	int n;
	printf("Nhap so luong phan tu trong mang");
	scanf("%d",&n);
	
	for(int i = 0; i<n ; i++){
		printf("\nNhap array[%d]",i);
		scanf("%d",&arr[i]);
	}
	printf("\n ban vua nhap ");
	for(int i = 0; i<n ; i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
