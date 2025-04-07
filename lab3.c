//**********dup1.c*********//

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(){
	int fd1=0,fd2=0;
	char buf[10]="abcdef";
	if((fd1=open("text1.txt",O_RDWR,0))<0)
		printf("error");
	fd2=dup(fd1);

	printf("%d%d \n",fd1,fd2);
	write(fd1,buf,6);
	return 0;
}


//************dup2.c**********//

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


///***************fileacc***********
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>


void err_ret(const char *msg) {
    perror(msg);
}

int main(int argc, char *argv[]) {
    int i;
    struct stat buf;
    char *ptr;

    
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> <file2> ...\n", argv[0]);
        exit(1);
    }

    
    for (i = 1; i < argc; i++) {
        printf("%s: ", argv[i]);

        
        if (lstat(argv[i], &buf) < 0) {
            perror("lstat error");
            continue;
        }

       
        if (S_ISREG(buf.st_mode))
            ptr = "regular file";
        else if (S_ISDIR(buf.st_mode))
            ptr = "directory";
        else if (S_ISCHR(buf.st_mode))
            ptr = "character special";
        else if (S_ISBLK(buf.st_mode))
            ptr = "block special";
        else if (S_ISFIFO(buf.st_mode))
            ptr = "FIFO (named pipe)";
        else if (S_ISLNK(buf.st_mode))
            ptr = "symbolic link";
        else if (S_ISSOCK(buf.st_mode))
            ptr = "socket";
        else
            ptr = "**unknown type**";

        
        printf("%s\n", ptr);
    }

    exit(0);
}

//*********fileacceper**********//
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    if (argc != 2)
        return 1;

    struct stat fileStat;
    if (stat(argv[1], &fileStat) < 0)
        return 1;

    printf("Information for %s\n", argv[1]);
    printf("---------------------------\n");
    printf("File Size: \t\t%ld bytes\n", fileStat.st_size);
    printf("Number of links: \t%ld\n", fileStat.st_nlink);
    printf("File inode: \t\t%ld\n", fileStat.st_ino);

    printf("File Permissions: \t");
    printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");

    printf("The file %s a symbolic link\n", (S_ISLNK(fileStat.st_mode)) ? "is" : "is not");

    return 0;
}

