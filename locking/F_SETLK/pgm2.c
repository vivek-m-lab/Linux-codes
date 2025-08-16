#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	struct flock v;
	int i,fd;
	char s[20]="1234567890";
	fd=open("temp",O_WRONLY|O_CREAT|O_APPEND,0644);
	if(fd<0)
	{
		perror("open");
		return 0;
	}
	v.l_type=F_WRLCK;
	v.l_whence=SEEK_SET;
	v.l_start=0;
	v.l_len=0;
	printf("Process 2 is checking for locking \n");
	fcntl(fd,F_SETLKW,&v);
	printf("Process 2 is locked\n");
	sleep(1);
	printf("Process PID : %d \n",getpid());
	sleep(1);
	printf("Process 2 is writing to file \n");
	sleep(1);
	for(i=0;s[i];i++)
	{
		write(fd,s+i,1);
		sleep(1);
	}
	printf("Process 2 completed writing\n");
	sleep(1);
	printf("process 2 is going to release\n");
	sleep(1);
/*	v.l_type=F_UNLCK;
	fcntl(fd,F_SETLK,&v);
	printf("Lock released\n");
	while(1);*/

}
