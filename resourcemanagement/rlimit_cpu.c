#include<stdio.h>
#include<sys/resource.h>
int main()
{
	struct rlimit v;
	getrlimit(RLIMIT_CPU,&v);
	printf("Soft :%u\n",v.rlim_cur);
	printf("Hard :%u\n",v.rlim_max);

	v.rlim_cur=100;
	setrlimit(RLIMIT_CPU,&v);

	getrlimit(RLIMIT_CPU,&v);
	printf("Soft :%u\n",v.rlim_cur);
	printf("Hard :%u\n",v.rlim_max);
}
