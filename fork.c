#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	pid_t ret;
	ret=fork();
	if(ret==-1)
	{
		printf("failed to create the process\n");
		exit(0);
	}
	else if(ret==0)
	{
		 int ret;
		 ret = execl ("/c/practice1.c", "practice1.c", NULL);
		 if (ret == (-1))
			 perror ("execl");
		exit(0);
	}
	else
	{
		printf("inside the parent\n");
		sleep(20);
		printf("parent is exitin\n");
	}
}

