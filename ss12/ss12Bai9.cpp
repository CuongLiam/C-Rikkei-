#include <stdio.h>
#define max 100

void printingMenu();
void inputValue(int arr[max][max],int n,int m);
void printingValue(int arr[max][max],int n, int m);
void printingCorner(int arr[max][max],int n,int m);
void printingBorder(int arr[max][max],int n,int m);
void printingMainDiagonalLineAndsecondary(int arr[max][max],int n,int m);
void printingPrimes(int arr[max][max],int n,int m);
int isPrime(int a);

int main(void){
	int n,m;
	printf("Nhap so cot va dong ");
	scanf("%d%d",&n,&m);
	if(n <=0  || m <=0) return 1;	
	
	int arr[max][max];
	while(1){
		int choice;
		printingMenu();
		scanf("%d",&choice);
		
		switch(choice){
			case 1:{
				inputValue(arr,n,m);
				
				break;
			}
			case 2:{
				printingValue(arr,n,m);
				
				break;
			}
			case 3:{
				printingCorner(arr,n,m);
				
				break;
			}
			case 4:{
				printingBorder(arr,n,m);
				break;
			}
			case 5:{
				if(n!=m){
					printf("\narray ko phai ma tran vuon ko the in duong cheo chinh va phu");
					break;
				}
				printingMainDiagonalLineAndsecondary(arr, n, m);
				
				break;
			}
			case 6:{
				printingPrimes(arr,n,m);
				
				break;
			}
			case 7:
				printf(" gudbye ");
				return 1;
			default:
				return 1;
		}
		
	}
	
	return 0;
};
void printingMenu(){
	printf("\n=====Menu=====\n");
	printf("\n1. nhap cac gia tri phan tu cua mang");
	printf("\n2. in gia tri ");
	printf("\n3. in gia tri o goc");
	printf("\n4. in gia tri o duong bien");
	printf("\n5. in gia tri duong cheo chinh va duong cheo phu");
	printf("\n6. in cac so nguyen to ");
	printf("\n7. exit");
	printf("\nLua chon cua ban: ");
};
void inputValue(int arr[max][max], int n, int m){
	for(int i=0; i<n; i++){
		for(int j=0 ; j<m; j++){
			printf("nhap array[%d][%d]",i,j);
			scanf("%d",&arr[i][j]);
		}
	}
};
void printingValue(int arr[max][max],int n,int m){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
};
void printingCorner(int arr[max][max],int n,int m){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(i==0&&j==0 || i==n-1&&j==0 || i==0&&j==n-1 || i==n-1&&j==n-1 ){
				printf("%d ",arr[i][j]);
			} else{
				printf("  ");
			}
		}
		printf("\n");
	}
};
void printingBorder(int arr[max][max],int n,int m){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(i==0 || i==n-1 || j==0 || j==m-1){
				printf("%d ",arr[i][j]);
			} else{
				printf("  ");
			}
		}
		printf("\n");
	}
};
//     1 2 3
//     4 5 6
//     7 8 9
void printingMainDiagonalLineAndsecondary(int arr[max][max],int n,int m){
	printf("Cac phan tu tren duong cheo chinh la:\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(i==j ){
				printf("%d",arr[i][j]);
			} else{
				printf(" ");
			}
		}
		printf("\n");
	}
	
	printf("Cac phan tu tren duong cheo phu la:\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(i+j==n-1 ){
				printf("%d",arr[i][j]);
			} else{
				printf(" ");
			}
		}
		printf("\n");
	}	
	
};
int isPrime(int a){
	if(a <= 1){
		return 0;
	}
	for(int i=2; i*i<=a; i++){
		if(a % i==0){
			return 0;
		}
	}
	return 1;
};
void printingPrimes(int arr[max][max],int n,int m){
	printf("Cac phan tu bao gom so nguyen to la:\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(isPrime(arr[i][j])){
				printf("%d",arr[i][j]);
			} else{
				printf(" ");
			}
		}
		printf("\n");
	}	
};
