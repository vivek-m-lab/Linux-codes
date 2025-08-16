#include<stdio.h>
#include<sys/resource.h>
#define stack_size (1*1024*1024)
int main()
{
	struct rlimit v;
	getrlimit(RLIMIT_STACK,&v);
	printf("Soft :%u\n",v.rlim_cur);
	printf("Hard :%u\n",v.rlim_max);

	v.rlim_cur=10*stack_size;
	setrlimit(RLIMIT_STACK,&v);
	printf("Soft :%u\n",v.rlim_cur);
	printf("Hard :%u\n",v.rlim_max);

}
