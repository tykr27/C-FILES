#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<malloc.h>
int main()
{
        void *last,*old;
        last=sbrk(0);
        printf("the last valid address %p \n",last);
        getchar();
        brk(last+100);
        last=sbrk(0);
        printf("value after incrementing %p \n",last);
        getchar();
}

