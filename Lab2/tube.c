#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc,char** argv) {
    int fd[2];
    int status;
    pid_t childPID1, childPID2;
//The program allocates a pipe (pipe())
    pipe(fd);
//The program forks two children
    childPID1 = fork();
    childPID2 = fork();

//The parent process prints the PID of both children on stderr (fprintf())
    if (childPID1 > 0 && childPID2 > 0) {
        fprintf( stderr, "CPID1: %d\n", childPID1);
        fprintf( stderr, "CPID2: %d\n", childPID2);

        waitpid(childPID1, &status, 0);
        waitpid(childPID2, &status, 0);
//The parents process closes access to the pipe
        close(fd[0]);
        close(fd[1]);
//The program prints the return value of the first child and then the second child on stderr
        fprintf(stderr, "RETVAL1: %d\n", status);
        fprintf(stderr, "RETVAL2: %d\n", status);
    }

//The first process executes the first command, and the second process executes the second command (execve())
    if(childPID1 == 0){
        close(fd[0]);
        char* newargv[] = { NULL };
        char* newenviron[] = { NULL };
        newargv[0] = argv[1];

        execve(argv[1], newargv, newenviron);
        perror("execve1");
        exit(0);
    }
    else if(childPID2 == 0){
        close(fd[1]);

        char* newargv2[] = { NULL };
        char* newenviron2[] = { NULL };
        newargv2[0] = argv[2];

        close(fd[1]);
        dup2(fd[0],STDIN_FILENO);

        execve(argv[2], newargv2, newenviron2);
        perror("execve2");
        exit(0);
    }

    //for the first interation keep it simple - i.e., the child has no command line args

    //enchance your program to allow for an arbitrary number of command line args

}