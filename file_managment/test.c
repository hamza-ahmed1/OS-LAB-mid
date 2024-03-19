#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#define READ_END 0
#define WRITE_END 1
int main()
{
        int fd;
        char buffer[100];
  
        //write(1,"Hello World",11);
	//taking input:
        fgets(buffer,sizeof(buffer),stdin);
        //read(0,buffer,100);
        
     	 fd=open("file.txt",O_WRONLY,777);
	size_t len=strlen(buffer);
        if(write(fd,buffer,len)==-1 || fd==-1)
	{
		printf("Error while writing into file");
	}
close(fd);
	fd=open("file.txt",O_RDONLY,777);
	if(fd==-1|| read(fd,buffer,sizeof(buffer)))
{
printf("Error while reading from file");
}
       
	close(fd);
        printf("%s\n",buffer);	

}
