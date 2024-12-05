#include"../header.h"
pthread_spinlock_t spin;
int a=10;
void *threadfun1(void *arg)
{

	int a=*((int*)arg);
	pthread_spin_lock(&spin);
	a=a+10;
	printf("the value of in function 1  is:%d\n",a);
	pthread_spin_unlock(&spin);
	return (void*) a;
}
void *threadfun2(void *arg)
{
	int a=*((int *)arg);
	printf("the value of a in function 2 is :%d\n",a);
}
int main()
{
	pthread_spin_init(&spin,PTHREAD_PROCESS_PRIVATE);
	pthread_t t1,t2;
	int ret=pthread_create(&t1,NULL,threadfun1,&a);
	if(ret==-1)
	{
		perror("failed to create the thred\n");
		exit(0); 
	}
	ret=pthread_create(&t2,NULL,threadfun2,&a);
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
        }ret=pthread_join(t2,NULL);
        if(ret==-1)
        {
                perror("failed to create the thred\n");
                exit(0);
        }
	printf("the final resulatant value is:%d\n",a);


	
}
	
