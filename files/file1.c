#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
    int fd;
    char buf[100];
    fd=open("1.txt",O_WRONLY|  O_CREAT ,0666);
    if(fd==-1)
    {
        printf("failed to open the file\n");
        exit(0);
    }
    printf("enter the message to write in to the file \n");
    fgets(buf,sizeof(buf),stdin);
    write(fd,&buf,sizeof(buf));
    close(fd);
    
    
    fd=open("1.txt",O_RDONLY );
    if(fd==-1)
    {
        printf("failed to open the file\n");
        exit(0);
    }
    read(fd,&buf,sizeof(buf));
    printf("the messages in the file are :%s\n",buf);
    
}
