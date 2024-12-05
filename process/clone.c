#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	pid_t ret;
	ret=clone();
	if(ret==-1)
	{
		printf("unable to create the process\n");
		exit(0);
	}
	if(ret==0)
	{
		printf("inside the child process :%d\n",getpid());
		sleep(10);
		printf("child is exiting\n");
		//_exit();
	}
	else
	{
		printf("inside the parent process :%d\n",getpid());
		sleep(30);
		printf("child is exiting\n");
	//	_exit();
	}
}
