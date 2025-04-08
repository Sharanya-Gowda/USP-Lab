/////////1.	Write a C program to demonstrate the creation of soft links and hard links.

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) 
{
    if (argc == 3) 
    {
        printf("Hard linking %s and %s\n", argv[1], argv[2]);
        if (link(argv[1], argv[2]) == 0)
            printf("Hard link created successfully.\n");
        else
            printf("Error creating hard link");
    } 
    else if (argc == 4) 
    { 
        printf("Soft linking %s and %s\n", argv[1], argv[2]);
        if (symlink(argv[1], argv[2]) == 0)
            printf("Soft link created successfully.\n");
        else
            printf("Error creating soft link");
    } 
    
    return 0;
}


////2.	Write a program to implement ls –li command which list the files in a specified directory. Your program should Print 5 attributes of files.


#include<stdio.h> 
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<time.h>
#include<sys/stat.h>

int main(int argc,char* argv[])
{
	struct dirent *dir;
	struct stat mystat;
	DIR *dp;
	dp = opendir(".");
	if(dp)
	{
	printf("--inode--mode-- uid--guid--access_time--Filename\n");
	while(dir = readdir(dp))
	{
		stat(dir->d_name,&mystat);
		// inode mode uid guid access_time 
		
		printf("\n%ld %o %d %d %s %s\n", 				mystat.st_ino,mystat.st_mode,mystat.st_uid,mystat.st_gid,ctime(&mystat.st_atime),dir->d_name);
	}
	}
}

////3.	Write a C program to remove empty files from the given directory.
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

int main(){
DIR *dp;
struct dirent *dir;
int fd,n;
dp = opendir("."); //open current directory

if(dp){

  while((dir = readdir(dp)) != NULL){

    fd = open(dir->d_name,O_RDWR,0777);
    n = lseek(fd,0,SEEK_END);
    if(!n){
      unlink(dir->d_name);
    }

  }

}
}


///4. Write a program to Copy access and modification time of a file to another file using utime function.

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <utime.h> 
#include <time.h> 
#include <fcntl.h>

int main(int argc,char* argv[]) //copying ctime and mtime of argv[2] to argv[1] 
{
int fd;
struct stat statbuf_1;
struct stat statbuf_2;
struct utimbuf times;

if(stat(argv[1],&statbuf_1)<0)/*Destination file status*/
printf("Error!\n");

if(stat(argv[2],&statbuf_2)<0) /* Source file status*/
printf("Error!\n");

printf("Before Copying ...\n");
printf("Access Time %s\nModification Time%s\n",ctime(&statbuf_1.st_atime),ctime(&statbuf_1.st_mtime));

times.modtime = statbuf_2.st_mtime;
times.actime = statbuf_2.st_mtime;
if(utime(argv[1],&times)<0)
printf("Error copying time \n");

if(stat(argv[1],&statbuf_1)<0)
printf("Error!\n");


printf("After Copying ...\n");
printf("Access Time %s\nModification Time%s\n",ctime(&statbuf_1.st_atime),ctime(&statbuf_1.st_mtime));
}
