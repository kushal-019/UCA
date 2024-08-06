#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
int main(){
	int n;
	scanf("%d" , &n);

	int digit = 0 , newDigit = 0;
	int flag = n >0 ?0 : 1;
	n = abs(n);
	while(n >0){
		int  digit = n%10;
		n = n/10;
		if(newDigit >(INT_MAX-digit-digit)/10)
		{
		    printf("%d" , 0);
		    return 0;
		}
		newDigit =(newDigit*10)+digit;
	}
	if(flag == 1)newDigit = - newDigit;
	
	printf("%d" , newDigit);
	return 0;
	
}
