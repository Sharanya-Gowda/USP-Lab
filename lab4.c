//*********access1.c***********//
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc,char *argv[]){
	if(argc!=2){
		printf("\n Usage: %s text1.c \n",argv[0]);
		exit(1);
	}

	if(access(argv[1],R_OK)<0)
		printf("\n Access error for %s",argv[1]);
	else
		printf("\n Readaccess OK\n");


	if(open(argv[1],O_RDONLY)<0){
		printf("\n Open error for %s",argv[1]);
	}

	else{
		printf("\n Open for reading OK \n");
	}

	exit(0);

}


//****chmod*****//
#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	struct stat statbuf;
	if(stat("foo",&statbuf)<0)
		printf("stat error for foo");
	if(chmod("foo",(statbuf.st_mode & ~S_IXGRP) | S_ISGID)<0)
		printf("chmod error for foo");
	if(chmod("bar",S_IRUSR | S_IWUSR |S_IRGRP | S_IROTH ) <0)
		printf("chmod error for bar");
	exit(0);

}

///******umask*******
#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int main(){
	umask(0);
	if(creat("foo",RWRWRW)<0){
		printf("create error for foo");
	}
	umask(S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
	if(creat("bar",RWRWRW)<0){
		printf("creat error for bar");
	}
	exit(0);
}



