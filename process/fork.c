#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
int main()
{
	pid_t ret;
	ret=fork();
	if(ret==-1)
	{
		printf("failed to create the process \n");
		exit(0);
	}
	if(ret==0)
	{
		printf("in child preocess \n");
		printf("the process id is %d:\n",getpid());
		sleep(10);
		printf("child is exiting\n");
	}
	else
	{
		printf("inside the child process\n");
		printf("the proces id is :%d\n",getpid());
		//sleep(20);
		printf("parent is exiting\n");
	}

}

