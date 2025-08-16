#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
   int fd1,i;
   char s[20]="abcdefghijk";
   fd1=open("temp",O_WRONLY|O_CREAT|O_APPEND,0644);
   if(fd1<0)
   {
	   perror("open");
	   return 0;
   }
   for(i=0;s[i];i++)
   {
	   write(fd1,s+i,1);
	   sleep(1);
   }
}

