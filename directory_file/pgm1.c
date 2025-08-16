#include<stdio.h>
#include<dirent.h>
int main(int argc,char *argv[])
{
    DIR * dp;
    struct dirent *p;
    if (argc!=2)
   {
	   printf("./a.out dirname\n");
	   return 0;
   }
    dp=opendir(argv[1]);
    if(dp==NULL)
    {
	    perror("opendir");
	    return 0;
    }
    p=readdir(dp);
    printf("%ld\n",p->d_ino);
    printf("%s\n",p->d_name);

}

