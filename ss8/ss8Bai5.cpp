#include <stdio.h>

int main(){
	int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	
	int sum;
	for(int i = 0; i < 3; i++){
		for(int j=0; j<3; j++){
			if(i==0 || j==0 || i==3-1 || j==3-1){
				sum += arr[i][j];
				printf("%d ",arr[i][j]);
			} else{
				printf("  ");
			}
		}
		printf("\n");
	}
	printf(" tong cac phan tu tren duong bien cua ma tran = %d",sum);
	return 0;
}
