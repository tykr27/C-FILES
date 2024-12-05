#include"../header.h"
int main()
{
	int *current;
	current =brk();
	printf("teh size of the memory is :%d\n",current);
	brk=sbrk(1024);
	current =brk();
	printf("the size of memory is :%d\n",current);
}
