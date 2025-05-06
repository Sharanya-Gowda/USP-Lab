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