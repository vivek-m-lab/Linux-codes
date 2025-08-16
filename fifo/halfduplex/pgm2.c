#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
int main()
{
    int fd,ret;
    char s1[20],s2[20];
    mkfifo("fifo",0644);
    perror("mkfifo");
    fd=open("fifo",O_RDWR);
    if(fd<0)
    {
	    perror("open");
	    return 0;
    }
    while(1)
    {
	    ret=read(fd,s1,sizeof(s1));
	    printf("ret = %d\n",ret);
	    printf("Data : %s\n",s1);
	    printf("Enter the Data \n");
	    scanf("%s",s2);
	    write(fd,s2,strlen(s2)+1);
	    sleep(1);
    }


}
