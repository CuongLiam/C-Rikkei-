#include <stdio.h>

int main(){
	int array[5] = {1,2,3,4,5};
	int n;
	
	printf("nhap vao 1 phan tu : ");
	scanf("%d",&n);
	
	int flag = 0,position;
	for(int i = 0; i<5; i++){
		if(n==array[i]){
			flag = 1;
			position = i;
		}
	}
	
	if(flag){
		printf("vi tri phan tu trong mang la %d",position);
	} else {
		printf("Phan tu khong ton tai trong mang");
	}
	return 0;
}
