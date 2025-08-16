#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
void isr()
{
	printf("Program running \n");
}
int main(int argc,char *argv[])
{
	int n,ret,i;
	n=atoi(argv[1]);
	printf("Before alarm \n");
	for(;n>=0;n--)
	{
		signal(SIGALRM,isr);
		ret=alarm(n);
		if(n==0)
			raise(9);
		pause();
	}
}
