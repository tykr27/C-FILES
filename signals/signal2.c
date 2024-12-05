#include"../header.h"
static void sig_handler(int n)
{
	if(n==SIGINT)
	{
		printf("sig int signal caught\n");
	}
	else if(n==SIGCHLD)
	{
		printf("sig child is caught\n");
	}
	else if(n==SIGALRM)
	{
		printf("sig alarm is caught\n");
	}
	else
	{
		printf("no signal is caught\n");
	}
}
int main()
{
	if(signal(SIGINT,sig_handler)==SIG_ERR)
	{
		printf("failed to hanlder the sigint\n");
		//exit(0);
	}if(signal(SIGCHLD,sig_handler)==SIG_ERR)
	{
		printf("failed to hanlde the sigchild signal\n");
	}
	if(signal(SIGALRM,sig_handler)==SIG_ERR)
	{
		printf("failed to handle the sig alarm signal\n");
	}
	//int ret=kill(getpid(),SIGINT);
          //      if(ret==0)
            //    ls
	    //    {
              //          perror("failed to create the signal]\n");
                //        exit(EXIT_SUCCESS);
                //}


	while(1)
	{
		printf("insode the main...\n");
		sleep(5);
	}
}
