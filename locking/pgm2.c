#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	struct flock v;
	int fd,i;
	char s[20]="1234567890";
	fd=open("temp1",O_WRONLY|O_CREAT|O_APPEND,0644);
	if(fd<0)
	{
		perror("open");
		return 0;
	}
	v.l_type=F_WRLCK;
	v.l_whence=SEEK_SET;
	v.l_start=0;
	v.l_len=0;
	printf("waiting for Lock \n");
	fcntl(fd,F_SETLKW,&v);
	printf("p2 now locked \n");
	printf("p2 writing data \n");
	for(i=0;s[i];i++)
	{
		write(fd,s+i,1);
		sleep(1);
	}
	printf("p2 process completed\n");
	sleep(2);
	printf("p2 is going to release \n");
	sleep(2);
	v.l_type=F_UNLCK;
	fcntl(fd,F_SETLKW,&v);
	printf("LOCK RELEASED \n");
	while(1);
}


