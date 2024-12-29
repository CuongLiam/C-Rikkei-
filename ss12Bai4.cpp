#include <stdio.h>
#define Max 100

int arr[Max];
int findingMax(int arr[],int size);

int main(void){
	int n;
	printf("nhap so luong phan tu trong array");
	scanf("%d",&n);
	
	if(n<=0){
		printf("Phai lon hon 0");
		return 1;
	}
	int arr[n];
	for(int i = 0 ;i<n ; i++){
	printf("nhap array[%d]",i);
	scanf("%d",&arr[i]);
	}
	
	int maxValue = findingMax(arr, n);
	printf("so lon nhat trong array la %d",maxValue);
	return 0;
};

int findingMax(int arr[],int size){
	int max = arr[0];
	for(int i =1; i < size; i++){
		if(arr[i] > max){
			max = arr[i];
		}
	}
	return max;
};
