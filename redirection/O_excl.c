#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int fd1;
	fd1=open("/home/v24ce7v1/vivek/linux/redirection/test1",O_WRONLY|O_CREAT|O_EXCL|O_TRUNC,0644);
	if(fd1<0)
	{
		perror("open");
		return 0;
	}
	printf("File exist");
}
