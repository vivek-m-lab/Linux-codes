#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int fd1,fd2;
	fd1=open("temp",O_WRONLY|O_CREAT|O_TRUNC,0644);
	if(fd1<0)
	{
		perror("open");
		return 0;
	}
	fd2=dup(fd1);
	printf("fd1:%d fd2:%d ",fd1,fd2);
	write(fd1,"hello",5);
	write(fd2,"Dharma",6);

}
