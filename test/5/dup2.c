#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(){
	int fd12=0;
	char buf[10]="qrstyh";
	if((fd12=open("text1.txt",O_RDWR,0))<0)
		printf("error");
	if((dup2(fd12,4)<0))
		printf("error");
	printf("%d%d \n",4,fd12);
	write(4,buf,6);
	return 0;
}