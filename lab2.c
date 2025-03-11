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

*


********3************
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
        char buffer[100];
        int bytesRead;
        printf("Enter some text: ");
        fflush(stdout);
        bytesRead = read(STDIN_FILENO, buffer, sizeof(buffer));
        if (bytesRead == -1) {
                printf("Error reading input");
                return 1;
        }
        write(STDOUT_FILENO, "You entered: ", 13);
        write(STDOUT_FILENO, buffer, bytesRead);
        return 0;
}


**********4*********
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


********5********
        #include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
int main(int argc,char *argv[]){
        int source,dest,n;
        char buf;
        int fs;
        int i;
         if(argc!=3){
                 fprintf(stderr,"usage %s <source><dest>",argv[0]);
                 exit(-1);
         }
        if((source=open(argv[1],O_RDONLY ))<0){
                printf("error");
                exit(-1);
        }
        if((dest=open(argv[2],O_WRONLY | O_CREAT |O_TRUNC))<0){
                printf("error");
                exit(-1);
        }
        fs=lseek(source,0,SEEK_END);
        for(i==fs-1;i>=0;i--){
                lseek(source,i,SEEK_SET);
                read(source,&buf,1);
                write(dest,&buf,1);
        }
                close(source);
                close(dest);
                return 0;
}
