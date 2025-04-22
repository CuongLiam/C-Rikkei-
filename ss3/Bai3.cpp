#include <stdio.h>
int main(){
	double amount, money;
	int choice;
	
	printf("==============CHUONG TRINH CHUYEN DOI TIEN TE=============\n");
    printf("1. USD to VND\n");
    printf("2. EUR to VND\n");
    printf("3. GBP to VND\n");
    printf("4. JPY to VND\n");
    printf("5. VND to USD\n");
    printf("6. VND to EUR\n");
    printf("7. VND to GBP\n");
    printf("8. VND to JPY\n");
    printf("Nhap don vi tien te muon doi :  (1-8) ?: ");
    scanf("%d",&choice);
    printf("Nhap so tien muon doi :   ?: ");
    scanf("%lf",&amount);
    
	const double USD_TO_VND = 23500;
    const double EUR_TO_VND = 25000;
    const double GBP_TO_VND = 28000;
    const double JPY_TO_VND = 180;
    switch(choice){
    	case 1 :
    		money = amount *  USD_TO_VND ;
			printf("%lf USD = %lf VND\n",amount,money);
    		break;
    	case 2 :
    		money = amount *  USD_TO_VND ;
			printf("%lf EUR = %lf VND\n",amount,money);
    		break;
    	case 3 :
    		money = amount *  USD_TO_VND ;
			printf("%lf GBP = %lf VND\n",amount,money);
    		break;
    	case 4 :
    		money = amount *  USD_TO_VND ;
			printf("%lf JPY = %lf VND\n",amount,money);
    		break;
    	case 5 :
    		money = amount /  USD_TO_VND ;
			printf("%lf VND = %lf USD\n",amount,money);
    		break;
    	case 6 :
    		money = amount /  USD_TO_VND ;
			printf("%lf VND = %lf EUR\n",amount,money);
    		break;
    	case 7 :
    		money = amount /  USD_TO_VND ;
			printf("%lf VND = %lf GBP\n",amount,money);
    		break;
    	case 8 :
    		money = amount /  USD_TO_VND ;
			printf("%lf VND = %lf JPY\n",amount,money);
    		break;
    	default: 
    		printf("please type in correctly\n");
    		break;
    }
    return 0;
}
