#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
int main()
{
	int fd;
	fd=open("1.txt",O_CREAT | O_WRONLY | O_TRUNC ,0666);
	if(fd==-1)
	{
		perror("failed to open the file \n");
		exit(0);
	}
	char buf[100];
	int len=10;
	fgets(buf,10,stdin);
	size_t ret=write(fd,buf,len);
	if(ret==-1)
	{
		perror("failed to write in to the file\n");
		exit(0);
	}
	close(fd);
	
}
