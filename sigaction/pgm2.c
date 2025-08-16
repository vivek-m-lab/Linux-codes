#include<stdio.h>
#include<signal.h>
void isr(int n)
{
	printf("isr ....\n");
}
int main()
{
	struct sigaction v;
	v.sa_handler=isr;
	v.sa_flags=0;
	sigfillset(&v.sa_mask);
	sigdelset(&v.sa_mask,3);
	sigaction(2,&v,0);
	while(1);
}

