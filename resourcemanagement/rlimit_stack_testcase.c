#include<stdio.h>
#include<sys/resource.h>
#define stack_size (1*1024*1024)
void recursive_fun(int n)
{
	char buf[1024];
	printf("%d\n",n++);
	recursive_fun(n);
}
int main()
{
	struct rlimit v;
	getrlimit(RLIMIT_STACK,&v);
	printf("Soft :%u\n",v.rlim_cur);
	printf("Hard :%u\n",v.rlim_max);

	v.rlim_cur=stack_size;
	setrlimit(RLIMIT_STACK,&v);
	printf("Soft :%u\n",v.rlim_cur);
	printf("Hard :%u\n",v.rlim_max);

	recursive_fun(1);
	while(1);

}
