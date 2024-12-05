#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<signal.h>
#include<errno.h>
#define death(mess){perror(mess);exit(errno);}
void sig_handler(int n)
{
	printf("\n%s------__fcntl__-----)");
	printf("we have recived the signal \n");
	alarm(5);
}
int main()
{
	struct sigaction act;
	memset(&act,0,sizeof(act));// filling structure size with 0's
	act.sa_handler=sig_handler;
	if(sigaction(SIGINT,&act,NULL)<0)
	{
		death("sigaction");
	}
	printf("Successfully intiates the handler\n");
	alarm(10);
	while(1)
	{
		printf("...............in main............\n");
		sleep(1);
	}
}


