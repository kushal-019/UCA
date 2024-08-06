
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>


int main()
{
	int file1 = open("helloworld.txt" , O_RDONLY);
	int file2 = open("printingFile.txt" , O_WRONLY | O_APPEND | O_CREAT ,
	 0644);	
	if(file1 == -1){
		printf("unable to open");
	}

	if(file2 == -1)printf("unable to open file2");
	char buf[1024];
	int currdata = read(file1 , buf , 1024);
	write(STDOUT_FILENO , buf , currdata);
	int flag = write(file2 , buf , currdata);
	if(flag == -1)printf("unable to write in file2");
	return 0;

}

