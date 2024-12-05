#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
void sig_handler(int n)
{
	printf("in sig handler\n");
	sleep(5);
}
int main()
{
	if(signal(SIGINT,sig_handler)==SIG_ERR)
	{
		perror("failed to handle the signal\n");
		exit(0);
	}
	while(1)
	{
		printf("inside the main.................\n");
	}
}
