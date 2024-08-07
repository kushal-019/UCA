#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	fork();
	printf("Hello World Before Fork\n");
	fork();
	printf("Hello World After Fork \n");
	return 0;

}
