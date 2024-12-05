#include"../header.h"
static void sig_handler()
{
	printf("inside the function %s\n",__func__);
	sleep(10);
	printf("Eniting the function........\n");
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
	while(1)
	{
		printf("inside the function...........\n");
		sleep(1);
	}
}
