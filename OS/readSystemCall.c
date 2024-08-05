#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc , char* argv[])
{
	int fd = open(argv[1],O_RDONLY);
	char buf[BUF_SIZE];
	if(fd != -1)
        {
		ssize_t numRead = read(fd , buf , BUF_SIZE-1);
		while(numRead > 0)
		{
			buf[numRead] = '\0';
			printf("%s \n" , buf);
			numRead = read(fd , buf , BUF_SIZE-1);
		}
	}
	else 
        {
		printf("Error to  read file \n");
		return -1;
        }
	return 0;
}
