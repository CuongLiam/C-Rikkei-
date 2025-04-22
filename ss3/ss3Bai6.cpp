#include <stdio.h>
#include <math.h>
int main(){
	int a,b,c,h;
	float S,P;
	printf("Nhap chieu dai 3 canh va chieu cao : \n");
	scanf("%d""%d""%d""%d",&a,&b,&c,&h);
	if (a+b > c && a+c > b && b+c > a){
		P = (float) (a+b+c)/2;
		S = (float) sqrt(P*(P-a)*(P-b)*(P-c));
		printf("Dien tich tam giac nay la : %.2f",S);
	} else{
		printf("Hay nhap canh lon hop le");
	}
	return 0;
}
