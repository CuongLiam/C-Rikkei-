#include <stdio.h>
int main(void){
	double h,m;
	printf("Nhap so lam viec trong thang : ");
	scanf("%lf",&h);
	printf("Nhap muc luong theo gio : ");
	scanf("%lf",&m);
	
	double salary,withPhuCap;
	if(h>160){
		salary = h*m;
		withPhuCap = h*m+(h*m)*0.1;
		printf("Tien luong co ban la : %f\n Bao gom tien phu cap la: %lf",salary,withPhuCap);
	} else {
		salary =h*m;
		printf("Tien luong co ban la : %lf",salary);
	}
	return 0;
}
