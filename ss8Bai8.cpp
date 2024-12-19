#include <stdio.h>
int main(){
	int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	
	int sum;
	for(int i = 0; i < 3; i++){
		for(int j=0; j<3; j++){
			printf("%d ",arr[i][j]);
			} 
		printf("\n");
	}
	
	printf("Cac phan tu tren duong cheo phu la ");
	for(int i = 0; i < 3; i++){		
		printf("%d ",arr[i][3-i-1]);
		sum += arr[i][3-i-1];		
	}
	printf("\ntong cac phan tu tren duong cheo phu cua ma tran = %d",sum);
	return 0;
}
