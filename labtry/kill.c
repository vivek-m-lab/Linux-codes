#include<stdio.h>
#include<signal.h>
void isr(int n)
{
	printf("daa...\n");
}
int main()
{
	signal(9,isr);
	while(1);
}
