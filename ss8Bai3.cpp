#include <stdio.h>
int main(){
	int n;
	printf("Nhap vao so nguyen n : ");
	scanf("%d",&n);
	
	int arr[n][n]={{n,n,n},{n,n,n},{n,n,n}};
	
	for(int i = 0 ;i<3;i++){
		for(int j = 0; j < 3;j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
