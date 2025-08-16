#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>
int main()
{
	int fd;
	char s[20];
	int ret;
	mkfifo("fifo",0644);
	fd=open("fifo",O_RDONLY);
	if(fd<0)
	{
		perror("open");
		return 0;
	}
	while(1)
	{
	ret=read(fd,s,sizeof(s));
	printf("ret=%d\n",ret);
	printf("%s\n",s);
	}
}




