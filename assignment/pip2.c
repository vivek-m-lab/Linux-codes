#include<stdio.h>
#include<string.h>
#include<unistd.h>
int main()
{
	int i,fd[2];
	if(pipe(fd)<0)
	{
		perror("pipe");
		return 0;
	}
	printf("fd[0]=%d fd[1]=%d \n",fd[0],fd[1]);
	if(fork()==0)
	{
		char s1[20],s2[20];
		while(1)
		{
			read(fd[0],s1,sizeof(s1));
			printf("Data recieved in child :%s\n",s1);
			for(i=0;s1[i];i++)
			{
				if((s1[i]>='A')||(s1[i]<='Z')||(s1[i]>='a')||(s1[i]<='z'))
					s2[i]=s1[i]^32;
				else
					s2[i]=s1[i];
			}
			s2[i]='\0';
			sleep(1);
			write(fd[1],s2,strlen(s2)+1);
			sleep(1);
		}	
	}
	else
	{
		char a1[20],a2[20];
		while(1)
		{
			printf("Enter the string in parent :\n");
			scanf("%[^\n]",a1);
			write(fd[1],a1,strlen(a1)+1);
			sleep(1);
			printf("Parent process :\n");
			read(fd[0],a2,sizeof(a2));
			printf("Data recieved in parent : %s\n",a2);
		}
	}
}
