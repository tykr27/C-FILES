#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<signal.h>
#include<sys/types.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#define death(mess){perror(mess);exit(errno);}
void sig_handler(int n)
{
	printf("inside the funtion sig handler\n");
	sleep(4);
	printf("......%s....\n",__func__);
	printf("exiting.......\n");
}
int main()
{
	struct sigaction act;
	memset(&act,0,sizeof(act));
	act.sa_flags=SA_NODEFER;
	act.sa_handler=sig_handler;
	if(sigaction(SIGINT,&act,NULL)<0)
		death("sigaction..../n");
	printf("sucessfully hadled the handler\n");
	while(1)
	{
		printf("inside the main function\n");
	}
}

