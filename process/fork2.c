#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	pid_t ret;
	fork();
	fork();
	fork();
	printf("hello\n");
	sleep(100);
}
