#include<stdio.h>

int main(){
	char* str;

	fgets(str , 10 , stdin);
	printf("%s" , str);
	return 0;
}
