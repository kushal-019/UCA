#include <stdio.h>
#include <stdlib.h>

void add(int a  ,int b)
{
	printf("%d \n" , a+b);
	return ;	
}

void sub(int a, int b)
{
	printf("%d \n" , b-a);
	return ;
}

void perform(void (*func)(int ,int) , int a, int b)
{
	func(a,b);
	return ;
}

int main()
{
	int a,b;
	scanf("%d %d" , &a ,&b);

	perform(add , a, b);
	perform(sub , a ,b);
	return 1;
}
