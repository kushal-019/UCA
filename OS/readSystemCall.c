#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main()
{
	int fd1 = open("sample.txt",O_RDONLY);
	int fd2 = open("fd2.txt",O_WRONLY | O_TRUNC);
	int fd3 = open("fd3.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);
	int fd4 = open("fd4.txt", O_WRONLY | O_APPEND);
	if(fd4 == -1)
	{
	    printf("unable to open file  that does not exist \n");
	}
	if(fd2 == -1)
	{
	    printf("unable to open file fd2.txt \n");
	    return -1;
	}
	char buf[BUF_SIZE];
	if(fd1 != -1)
        {
		int numRead = read(fd1, buf , 1024);
		write(STDOUT_FILENO, buf, numRead);
		write(fd2 , buf , numRead);
		write(fd3 , buf , numRead);
		int flag = write(fd4 , buf , numRead);
		if(flag == -1)
		{
		  printf("Nothing updated \n");
		}
                close(fd1);
                close(fd2);
      	}
	else 
        {
		printf("Error to  read file \n");
		return -1;
        }
	return 0;
}
