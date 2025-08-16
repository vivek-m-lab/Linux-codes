#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
int main()
{
	int fd;
	char a[20];
	mkfifo("fifo",0644);
	perror("mkfifo");
	fd=open("fifo",O_WRONLY);
	if(fd<0)
	{
		perror("open");
		return 0;
	}
	while(1)
	{
		printf("Enter the data \n");
		scanf("%s",a);
		write(fd,a,strlen(a)+1);
	}
}



