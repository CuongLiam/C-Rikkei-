#include <stdio.h>

int main(){
	int arr[3][3] = {{2,6,8},{1,7,3},{2,9,2}};
	
	int max = arr[0][0];
	
	for(int i = 0;i<3;i++){
		for(int j = 0;j<3;j++){
			printf("%d ",arr[i][j]);
			if (arr[i][j] > max){
				max = arr[i][j];
			}
		}
		printf("\n");
	}
	printf("\n so lon nhat trong mang da khai bao la %d",max);
	return 0;
}
