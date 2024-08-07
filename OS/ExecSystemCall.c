#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	printf("First Statement \n");
	fork();
	printf("%d" , getpid());
	sleep(2);
	char* argv[] = {"./readSystemCall" , NULL};
	execv(argv[0],argv);
	printf("Second statement \n");

	return 0;
}
