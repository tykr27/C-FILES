#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<malloc.h>
#include<malloc.h>
int main()
{
        int th;
        char*p1;
        mallopt(M_MMAP_MAX,2);
        malloc(1024*12);
        getchar();
        malloc_stats();
        malloc(140*1024);
        getchar();
        malloc_stats();
        malloc(140*1024);
        getchar();
        malloc_stats();
        exit(0);
}
