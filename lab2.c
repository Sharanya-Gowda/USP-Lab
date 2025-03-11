*******1********
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
void main(){
        int fd;
        if((fd=open("/home/cselab1/cs130/text1.txt",O_RDONLY))<0){
                printf("error");
                exit(1);
        }
        printf("Open %d",fd);
        close(fd);

}

*********2***********
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
void main(){
        int fd;
        if((fd=creat("text2.txt",777))<0){
                printf("error");
                exit(1);
        }
        printf("File created successfully %d",fd);
        close(fd);

}

