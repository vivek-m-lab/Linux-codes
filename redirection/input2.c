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
	close(1);
	fd2=dup(fd1);
	//fd2=dup(fd1);
	execlp("pwd","pwd",NULL);
	printf("After excl function\n");

}
