#include <stdio.h>
int const maxSize = 100;

int main(){
	int arr[maxSize],size;
	
	printf("Nhap vao so luong phan tu ma ban muon tao mang ");
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
	int editPosition,editValue;
	printf("\nNhap vi tri ban muon sua vao trong mang (0-%d)",size-1);
	scanf("%d",&editPosition);
	if(editPosition<0 || editPosition> size){
		printf("\nvi tri khong hop le hay nhap lai");
		break;
	}
	
	int temp = arr[editPosition];
	printf("\nNhap gia tri ban muon sua vao trong mang(hien tai la %d)",temp);
	scanf("%d",&editValue);
	
	arr[editPosition] = editValue;
	
	printf("\nda sua thanh cong!!");
	printf("\nCac phan tu hien gio la: ");
	for(int i=0 ; i < size;i++){
		printf("%d ",arr[i]);
	}
	flag = 0;
	
	}
	
	return 0;
}
