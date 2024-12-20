#include <stdio.h>
int const maxSize = 100;

int main(){
	int arr[maxSize],size;
	
	printf("Nhap vao so phan tu ma ban muon nhap vao mang ");
	scanf("%d",&size);
	
	for(int i=0 ; i < size;i++){
		printf("\nNhap vao phan tu array[%d] ",i);
		scanf("%d",&arr[i]);
	}
	
	printf("\nCac phan tu ban vua nhap la ");
	for(int i=0 ; i < size;i++){
		printf("%d ",arr[i]);
	}
	
	int flag = 1;
	while(flag){
	int addPosition,addValue;
	printf("\nNhap vi tri ban muon them vao trong mang (0-%d)",size-1);
	scanf("%d",&addPosition);
	if(addPosition<0 || addPosition> size){
		printf("\nvi tri khong hop le hay nhap lai");
		break;
	}
	printf("\nNhap gia tri ban muon them vao trong mang ");
	scanf("%d",&addValue);
	
	for(int i = size ; i > addPosition ; i--){
		arr[i] = arr[i-1]; 
	}
	arr[addPosition] = addValue;
	size++;
	
	printf("\nda them thanh cong!!");
	printf("\nCac phan tu hien gio la: ");
	for(int i=0 ; i < size;i++){
		printf("%d ",arr[i]);
	}
	flag = 0;
	
	}
	
	return 0;
}
