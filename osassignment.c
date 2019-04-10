#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 50

int main( int argc, char* argv[] ) {
    int arc[2];
    pid_t childid;

    char readBuff[SIZE];

    pipe(arc);

    if( argc != 3 ) {
        printf("ERROR: Need exactly 2 parameters.\n");
        exit(1);
    }

    int fopen = open(argv[1], 0);
    int ftarget = open(argv[2], O_RDWR|O_CREAT|O_APPEND, 0666);

    if (fopen == -1 || ftarget == -1) {
        printf("ERROR: Opening file failed\n");
        exit(1);
    }
    childid = fork();

    if (childid == 0) {
        // inside the child prcocess
        close(arc[1]);

        while (read(arc[0], readBuff, sizeof(readBuff)) > 0) {
            // Writing to the target fopen
            write(ftarget, readBuff, strlen(readBuff) - 1);
        }

        close(arc[0]);
        close(ftarget);
    }
    else {
        // inside the parent process
        close(arc[0]);

        // code to read from a text file
        while (read(fopen, readBuff, sizeof(readBuff)) > 0) {
            write(arc[1], readBuff, sizeof(readBuff));
            memset(readBuff, 0, SIZE);
        }

        close(arc[1]);
        close(fopen);
        wait(NULL);
    }
}