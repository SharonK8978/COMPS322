#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <unistd.h>
#include <errno.h>

sem_t * returnVal;
sem_t * chopstick[3];
RAND_MAX = 3;
static int eat_count =0;
static int think_count=0;

void sighandler(int sig){
    sem_destroy();
    sem_close();
    sem_unlink();

    fprintf(stderr,"Philosopher #%d completed %d cycles", getpid(), cycle);
    
}

void eat(){
    //consume a random amount of real-time (usleep(3), rand(3))
    usleep(rand());
    //emits to stdout "Philosopher #n is eating."
    fprintf(stdout, "Philosopher #%d is eating.", getpid());
}

void think(){
    //consume a random amount of real-time (usleep(3), rand(3))
    usleep(rand());
    //emint to stdout "Philosopher #n is thinking."
    fprintf(stdout, "Philosopher #%d is thinking.",getpid());
}

int main(int argc, char** argv){
    do{
        wait(chopstick[i]);
        wait(chopstick[(i+1) % 5]);

        //eat for a while

        signal(chopstick[i]);
        signal(chopstick[(i+1) % 5]);

        //think for a while

    }while(true);

    }

}