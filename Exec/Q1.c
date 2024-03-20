#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<wait.h>
int main()

{
	pid_t p;
	p=fork();
	if(p<0){printf("error while creating child process");}
	else if(p==0)
	{
		//code for  child
		char *file_name="ls";
		char *arg1="-a";
		char *arg2="-s";
		execlp(file_name,arg1,arg2,NULL);
	}
	else
	{
		wait(NULL);
	}
}
