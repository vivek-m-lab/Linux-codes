#include<stdio.h>
#include<time.h>
int main()
{
	time_t t;// time_t structure name and t is structure variable
	while(1)
	{
	printf("%u\n",time(&t));
	printf("%s\n",ctime(&t));
	sleep(1);
	system("clear");
	}
}
