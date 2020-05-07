#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>

pid_t mole1, mole2;
int count;
char sig_name[3][20];

void sighandler(int sig){
signal(sig, sighandler);

    if(sig == SIGUSR1){
        kill(mole1);
        
    }

    if(sig == SIGUSR2){
        kill(mole2);
    }

}

void daemonize(const char* cmd) {
    int i, fd0, fd1, fd2;
    pid_t pid;
    struct rlimit rl;

//set the file creation mask to 0
    unmask(0);

//Fork and have the parent exit
    pid = fork();
    exit(0);

//Create a new session 
if(pid != 0){ 
    pid = setsid();
    //create a new process group
}

//Change the current working directory to be "/"
    chdir("/");

//Close all unneeded file descriptors
    getrlimit(RLIMIT_NOFILE, &rl);

    if(rl.rlim_max == RLIM_INFINITY){
        rl.rlim_max = 1024;
    }

    for(i=0; i < rl.rlim_max; i++){
        close(i);
    }
//Reopen the standard file descriptors to map to /dev/null
fd0 = open("/dev/null", O_RDWR);
fd1 = dup(0);
fd2 = dup(0);
}

int main(int argc, char** argv){

strcpy(sig_name[0],"TERM");
strcpy(sig_name[1],"USR1");
strcpy(sig_name[2],"USR2");

for(int i = 1; i < argc; ++i){
    if(strcmp(argv[i], sig_name[0])==0){
        signal(SIGTERM, sighandler);
    }
    else if(strcmp(argv[i], sig_name[1])==0){
        signal(SIGUSR1, sighandler);
    }
    else if(strcmp(argv[i], sig_name[2])==0){
        signal(SIGUSR2, sighandler);
    } else {
        print("%s is not a valid signal.\n",argv[i]);
    }
}


}