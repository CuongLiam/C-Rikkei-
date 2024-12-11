#include <stdio.h>
int main(){
	float cel,far;
	printf("Input degree in Celsius: ");
	scanf("%f",&cel);
	far = cel*1.8+32;
	printf ("\nFahrenheit = %.2f",far);
	
	return 0;
}
