#include <stdio.h>
#define Max 100
int arr[Max];
int n;
int showArray();

int main(void){
	showArray();
	
	return 1;
}


int showArray(){
	printf("nhap so luong array muon them");
	scanf("%d",&n);
	if(n>Max){
		return 0;
	}
	
	for(int i=0 ; i<n ; i++){
		printf("\nnhap array[%d]",i);
		scanf("%d",&arr[i]);
	}
	
	printf("\ncac phan tu trong array la ");
	for(int i = 0 ; i<n ; i++){
		printf("%d ",arr[i]);
	}
};
