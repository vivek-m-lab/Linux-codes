#include<stdio.h>
#include<sys/resource.h>
int main()
{
	struct rlimit v;
	printf("Execution started\n");
	getrlimit(RLIMIT_CORE,&v);
	printf("%u\n",v.rlim_cur);
	printf("%lu\n",v.rlim_max);

        v.rlim_cur=2000;
	setrlimit(RLIMIT_CORE,&v);

	getrlimit(RLIMIT_CORE,&v);
	printf("%u\n",v.rlim_cur);
	printf("%lu\n",v.rlim_max);
}

