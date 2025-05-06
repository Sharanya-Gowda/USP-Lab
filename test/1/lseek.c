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