#include <stdio.h>
int main(){
	float r,S,C;
	const float pi = 3.14;
	printf("Input radius : ");
	scanf("%f",&r);
	S = pi*r*r;
	C = 2*pi*r;
	printf ("Chu vi hinh tron= %.2f",C);
	printf ("\nDien tich hinh tron= %.2f",S);	
	return 0;
}
