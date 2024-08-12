#include <stdio.h>

int add(int a, int b)
{
	return a+b;
}

int sub(int a , int b)
{
	return b-a;
}

int main()
{
	int a,b;
	scanf("%d %d" , &a ,&b);

	int (*fun_ptr)(int , int);
       fun_ptr = &sub;

	printf("%d \n" , sub(a,b));
	fun_ptr = &add;
	printf("%d \n" , add(a,b));

	return 1;

}
