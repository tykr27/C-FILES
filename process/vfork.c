#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	pid_t ret;
	ret=vfork();
	if(ret==-1)
	{
		printf("failed to create the process\n");
		exit(0);
	}
	if(ret==0)
	{
		printf("inside the child process   :%d\n",getpid());
		sleep(20);
		printf("child is exiting  .... \n");
	}
	else
	{
		printf("inside the parent process :%d\n",getpid());
		sleep(1);
		printf("parent is exiting ....\n");
	}
}
