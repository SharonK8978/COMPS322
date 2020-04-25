#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc,char** argv) {
    pid_t childPID;
    int status;

//The program forks a child process (fork())
    childPID = fork();
//The parent process prints the PID of the child on stderr  
    if(childPID > 0) {
        fprintf( stderr, "CPID = %d\n",childPID);
        waitpid(childPID, &status, 0);
    }
//The child process executes the supplied command (execve())
    else if(childPID == 0) {
    //the child needs to prepare the new argv structure
        char* newargv[] = { NULL };
        char* newenviron[] = { NULL };

        newargv[0] = argv[1];
        execve(argv[1], newargv, newenviron);
        perror("execve");
        exit(0);
    } else{
        //error if fork fails
        perror("fork failed");
    }
//The parent prints the return value of the child on stderr (waitpid())
fprintf(stderr, "RETVAL: %d\n", status);
    return 0;
}