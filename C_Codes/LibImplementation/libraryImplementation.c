#include<stdio.h>
#include"basicMAth.h"
#include"advanceMath.h"

int main(){
	int a , b;
	printf("Enter Two Numbers : \n");
	scanf("%d  %d" , &a , &b);

	printf("sum = %d \n" , add(a,b));
	printf("Diff :% d \n" , sub(a,b));
	printf("product = %d \n" , multi(a,b));
	printf("division  :% d \n" , divide(a,b));
	printf("max = %d \n" , max(a,b));
	printf("min :% d \n" , min(a,b));
	printf("abs :% d \n" , abs(a));
	printf("abs :% d \n" , abs(b));
	return 0;

}
