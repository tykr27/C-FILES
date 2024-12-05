#include"../header.h"
static void sig_handler()
{
	printf("inside the function %s\n",__func__);
	sleep(10);
	printf("Eniting the function........\n");
}
void handler()
{
	pid_t ret=fork();
        if(ret==0)
        {
                printf("inside the child \n");
                exit(0);
        }
}
int main()
{
	struct sigaction act;
	memset(&act,0,sizeof(act));
	act.sa_handler=sig_handler;
	act.sa_flags=SA_NODEFER;
	if(sigaction(SIGINT,&act,NULL)<0)
	{
		perror("death of the siganl\n");
	}
	alarm(5);
	if(signal(SIGALRM,handler)<0)
	{
		perror("failed to send alaram siganl\n");
		exit(0);
	}
	if(signal(SIGCHLD,handler)<0)
	{
		perror("failed to call the child\n");
		exit(0);
	}
	else
	{
		handler();
	}
	while(1)
	{
		printf("inside the function...........\n");
		handler();
		sleep(5);
		alarm(5);
		sleep(1);
	}
}
