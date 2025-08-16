#include<stdio.h>
#include<signal.h>
int main()
{
	int ret;
	printf("hi...\n");
	ret=raise(9);
	printf("after raise \n");
	printf("%d\n",ret);
	while(1);

}
