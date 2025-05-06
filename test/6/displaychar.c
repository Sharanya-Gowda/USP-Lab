#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
        int file=0,n;
        char buffer[100];
        if((file=open("text1.txt",O_RDONLY))<-1)
                printf("Error");
        if(read(file,buffer,20)!=20)
                printf("file read opeartion failed");
        else
                write(STDOUT_FILENO,buffer,20);
        printf("\n");

        if(lseek(file,10,SEEK_CUR)<0)
                printf("Lseek op failed");
        if(read(file,buffer,20)!=20)
                printf("failed");
        else
                write(STDOUT_FILENO,buffer,20);
        printf("\n");

        if((n=lseek(file,0,SEEK_END))<0)
                printf("lseek op to end failed");
        printf("size of file %d",n);
        close(file);
        return 0;
}