//Wap to dissable SIGINT(2) and SIGQUIT(3) in a process for 10 seconds
#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void isr()
{
	printf("ISR...\n");
	signal(2,SIG_DFL);
	signal(3,SIG_DFL);
}
int main()
{
	signal(2,SIG_IGN);
	signal(3,SIG_IGN);
	signal(SIGALRM,isr);
	alarm(5);
	printf("After alarm\n");
	while(1);
}
