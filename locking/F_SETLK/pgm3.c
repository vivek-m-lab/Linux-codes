#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<signal.h>
int main()
{
	struct flock v1,v2;
	int i,fd,ret;
	char s[20]="!@##$$$%^&*()";
	fd=open("temp",O_WRONLY|O_CREAT|O_APPEND,0644);
	if(fd<0)
	{
		perror("open");
		return 0;
	}
	v1.l_type=F_WRLCK;
	v1.l_whence=SEEK_SET;
	v1.l_start=0;
	v1.l_len=0;
	printf("Process 3 is checking for locking \n");
	ret=fcntl(fd,F_SETLK,&v1);
	if(ret==-1)
	{
          fcntl(fd,F_GETLK,&v2);
	  printf("Locked process PID : %d\n",v2.l_pid); 
	  kill(9,v2.l_pid);
	}
	else
	{
	printf("Process 3 is locked\n");
	sleep(1);
	printf("Process PID : %d \n",getpid());
	sleep(1);
	printf("Process 3 is writing to file \n");
	sleep(1);
	for(i=0;s[i];i++)
	{
		write(fd,s+i,1);
		sleep(1);
	}
	printf("Process 3 completed writing\n");
	sleep(1);
	printf("process 3 is going to release\n");
	sleep(1);
	}
/*	v.l_type=F_UNLCK;
	fcntl(fd,F_SETLK,&v);
	printf("Lock released\n");
	while(1);*/

}
