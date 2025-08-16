#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int fd;
	close(1);
	fd=open("temp",O_WRONLY|O_CREAT|O_TRUNC,0644);
	if(fd<0)
	{
	   perror("open");
	   return 0;
	}
	printf("fd:%d\n",fd);
	printf("Hello");
}
