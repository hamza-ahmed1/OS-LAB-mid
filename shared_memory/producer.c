#include<stdio.h>
#include<sys/shm.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>
int main()
{
	int fd;
	char *ptr;
	//1-creating shm object
	fd=shm_open("OS",O_CREAT|O_RDWR,0666);
	
	//2-configure the size;
	ftruncate(fd,10*sizeof(char));

	//3-memory map with shm_obj
	ptr=(char*)mmap(NULL,10*sizeof(char),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);


	//4-writing to shared memory obj
	sprintf(ptr,"%s","Hello");
	ptr+=strlen("Hello");
	sprintf(ptr,"%s","World");
	ptr+=strlen("World");
	return 0;


}
