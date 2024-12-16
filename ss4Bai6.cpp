#include <stdio.h>
int main(void){
	double n,m,j,bill=0;
	printf("Nhap chi so cu(chi so cong to dien o dau thang) kwh: ");
	scanf("%lf",&n);
	printf("Nhap chi so moi(chi so cong to dien o cuoi thang) kwh: ");
	scanf("%lf",&m);
	j = m - n;
	
	if(j>=0 && j<50){
		bill = 10000 *j;
		printf("Gia dien la %lf /kwh",bill);
	} else if(j>=50 && j<100){
		bill = 10000 + 15000*j;
		printf("Gia dien la %lf /kwh",bill);
	} else if(j>=100 && j<150){
		bill = 10000 + 15000 + 20000*j;
		printf("Gia dien la %lf /kwh",bill);
	} else if(j>=150 && j<200){
		bill = 10000 + 15000 + 20000 + 25000*j;
		printf("Gia dien la %lf /kwh",bill);
	} else if(j>=200){
		bill = 10000 + 15000 + 20000 + 25000 + 30000*j;
		printf("Gia dien la %lf /kwh",bill);
	}
	return 0;
}
