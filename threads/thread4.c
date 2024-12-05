#include"../header.h"
pthread_mutex_t spin;
int a=0;
void *threadfun1(void *arg)
{

	int loops=*((int*)arg);
	pthread_mutex_lock(&spin);
	for(int i=0;i<loops;i++)
	{
		a++;
	}
	//printf("the value of in function 1  is:%d\n",a);
	pthread_mutex_unlock(&spin);
	return NULL;
}
void *threadfun2(void *arg)
{
	int loops=*((int *)arg);
	pthread_mutex_lock(&spin);
	for(int j=0;j<loops;j++)
	{
		a++;
	}
	pthread_mutex_unlock(&spin);
	return NULL;
}
int main()
{
	int loops=10000;
	pthread_mutex_init(&spin,PTHREAD_PROCESS_PRIVATE);
	pthread_t t1,t2;
	int ret=pthread_create(&t1,NULL,threadfun1,&loops);
	if(ret==-1)
	{
		perror("failed to create the thred\n");
		exit(0); 
	}
	printf("the value of a is :%d\n",a);
	ret=pthread_create(&t2,NULL,threadfun2,&loops);
        if(ret==-1)
        {
                perror("failed to create the thred\n");
                exit(0);
        }
       	ret=pthread_join(t1,NULL);
        if(ret==-1)
        {
                perror("failed to create the thred\n");
                exit(0);
        
	}
	printf("value of a %d\n",a);
	ret=pthread_join(t2,NULL);
        if(ret==-1)
        {
                perror("failed to create the thred\n");
                exit(0);
        }
	printf("the final resulatant value is:%d\n",a);


	
}
	
