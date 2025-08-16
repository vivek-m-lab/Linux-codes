#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int fd1,fd2;
	char s1[20],s2[20];
	mkfifo("fifo1",0664);
	perror("mkfifo");
	mkfifo("fifo2",0664);
	perror("mkfifo");
	fd1=open("fifo1",O_RDONLY);
	if(fd1<0)
	{
		perror("open");
		return 0;
	}
	fd2=open("fifo2",O_WRONLY);
	if(fd2<0)
	{
		perror("open");
		return 0;
	}
	if(fork()==0)
	{
		while(1)
		{
		scanf("%s",s2);
		write(fd2,s2,strlen(s2)+1);
		}
	}
	else
	{
		while(1)
		{
		read(fd1,s1,sizeof(s1));
		printf("Data recieved:%s\n",s1);
		}
	}


}
