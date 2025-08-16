#include<stdio.h>
#include<sys/resource.h>
int main()
{
	char a[20]="we shall overcome";
	struct rlimit v;
	FILE *fs=fopen("data.txt","w");
	if(fs==NULL)
	{
		perror("fopen");
		return 0;
	}
	printf("Process under execution\n");
	getrlimit(RLIMIT_CORE,&v);
	printf("Soft :%u\n",v.rlim_cur);
	printf("Hard :%u\n",v.rlim_max); 

        v.rlim_cur=100;

	printf("After updation\n");
	setrlimit(RLIMIT_CORE,&v);
	printf("Soft :%u\n",v.rlim_cur);
	printf("Hard :%u\n",v.rlim_max);


	printf("Process under execution\n");
	getrlimit(RLIMIT_FSIZE,&v);
	printf("Soft :%u\n",v.rlim_cur);
	printf("Hard :%u\n",v.rlim_max);

	v.rlim_cur=10;

	printf("After updating the soft value\n");
	setrlimit(RLIMIT_FSIZE,&v);
	printf("Soft :%u\n",v.rlim_cur);
	printf("Hard :%u\n",v.rlim_max);

	fprintf(fs,"%s",a);

}

