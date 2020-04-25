#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/times.h>

int main() {
    time_t seconds;
    pid_t childPID;
    int status;
    struct tms buf;
    clock_t bt;

    bt = times(&buf);
//prints the number of seconds since...
    time(&seconds);
    printf("START: %ld\n", seconds);

//Create a child process
    childPID = fork();
        //Error if childPID == -1   
        if(childPID == -1){
            perror("fork error");
            exit(EXIT_FAILURE);
        }

//Program will wait for the child to finish
    waitpid(childPID, &status, 0);
//The program and it's child reports on the information
    if (childPID == 0) {
        //The process (this is child) ID of its parent
        printf("PPID: %ld",(long) getppid());
        //Its own process ID
        printf(",   PID: %ld\n",(long) getpid());
        exit(0);
    }
        //The process (this is parent) ID of its parent  
        printf("PPID: %ld",(long) getppid());
        // Its own process (this is parent) ID
        printf(",   PID: %ld",(long) getpid());  
        //The process ID of its child(if applicable)
        printf(",   CPID: %ld",(long) childPID);
        //The return status of its child(if applicable)
            if(WIFEXITED(status)){
                printf(",   RETVAL: %d\n", WEXITSTATUS(status));
            }
            //Error if Child process does not properly exit
            if(!WIFEXITED(status)){
                perror("exit error");
                exit(EXIT_FAILURE);
            }
    
//The program will report the following time information
    //User time
    printf("USER: %ld", buf.tms_utime);
    //System time
    printf(",   SYS: %ld\n", buf.tms_stime);
    //User time of child
    printf("CUSER: %ld", buf.tms_cutime);
    //System time of child
    printf(",   CSYS: %ld\n", buf.tms_cstime);
//The program prints the number of seconds since...
    printf("STOP: %ld\n", seconds);
    return 0;
}