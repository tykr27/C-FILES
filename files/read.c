#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	int fd;
	fd=open("1.txt",O_RDONLY );
	if(fd==-1)
	{
		perror("failed to open the file\n");
		exit(0);
	}
	size_t rt;
	char buf[100];
	size_t len=10;
	rt=read(fd,buf,sizeof(buf));
	if(rt==-1)
	{
		perror("failed to read from the file\n");
		exit(0);
	}
	buf[rt]='\0';
	write(1,buf,rt);
	//printf("the information is :%s\n",buf);
	close(fd);
}

