#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main()
{
	int fd,i,n;
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
		read(fd,s2,sizeof(s2));
		printf("%s\n",s2);
		n=strlen(s2);
		for(i=0;s2[i];i++)
		{
			s1[i]=s2[--n];
		}
		s1[i]='\0';
		write(fd,s1,strlen(s1)+1);
		sleep(1);


	}	
}

