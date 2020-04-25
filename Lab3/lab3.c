#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

static int count = 0;
static int sig_count = 0;
char sig_name[28][20];

void sighandler(int sig){
    time_t seconds;
    time(&seconds);

    sig_count++;

        //The program gracefully terminates after recieving three sucessive SIGTERM signals    (hint: static int count)
    if(strcmp(sig_name[sig-1], "TERM")==0 ){
        count++;
    }

    //The handler registers itself again (read about unreliable signals)
    signal(sig, sighandler);
    //The handler emits a line to stdout that indicates the signal caught, and the time it was caught    (time(2))
    fprintf(stdout, "SIG%s caught at %ld\n", sig_name[sig-1], seconds);
}

int main(int argc, char** argv) {

//All the SIG_names accepted
strcpy(sig_name[0],"HUP"); 
strcpy(sig_name[1],"INT"); 
strcpy(sig_name[2],"QUIT"); 
strcpy(sig_name[3],"ILL");
strcpy(sig_name[4],"TRAP"); 
strcpy(sig_name[5],"ABRT"); 
strcpy(sig_name[6],"BUS"); 
strcpy(sig_name[7],"FPE");
strcpy(sig_name[9],"USR1"); 
strcpy(sig_name[10],"SEGV"); 
strcpy(sig_name[11],"USR2");
strcpy(sig_name[12],"PIPE"); 
strcpy(sig_name[13],"ALRM"); 
strcpy(sig_name[14],"TERM"); 
strcpy(sig_name[15],"STKFLT");
strcpy(sig_name[16],"CHLD"); 
strcpy(sig_name[17],"CONT"); 
strcpy(sig_name[19],"TSTP");
strcpy(sig_name[20],"TTIN"); 
strcpy(sig_name[21],"TTOU"); 
strcpy(sig_name[22],"URG"); 
strcpy(sig_name[23],"XCPU");
strcpy(sig_name[24],"XFSZ"); 
strcpy(sig_name[25],"VTALRM"); 
strcpy(sig_name[26],"PROF"); 
strcpy(sig_name[27],"WINCH");
strcpy(sig_name[28],"IO"); 


//The program emits a status line that includes its PID to stderr
fprintf(stderr, "catcher: $$ = %d\n",getpid());

//The program registers a handler for each arguement (signal(2))
printf("%d : argc \n", argc);
for(int i = 1; i < argc; ++i){
    if (strcmp(argv[i], sig_name[0])==0 ) {
        signal(SIGHUP, sighandler);
    } 
    else if (strcmp(argv[i], sig_name[1])==0 ){
        signal(SIGINT, sighandler);
    } 
    else if (strcmp(argv[i], sig_name[2])==0 ){
        signal(SIGQUIT, sighandler);
    } 
    else if (strcmp(argv[i] ,sig_name[3])==0 ){
        signal(SIGILL, sighandler);
    } 
    else if (strcmp(argv[i] ,sig_name[4])==0 ){
        signal(SIGTRAP, sighandler);
    } 
    else if (strcmp(argv[i] ,sig_name[5])==0 ){
        signal(SIGABRT, sighandler);

    } 
    else if (strcmp(argv[i] ,sig_name[6])==0 ){
        signal(SIGBUS, sighandler);

    } 
    else if (strcmp(argv[i] ,sig_name[7])==0 ){
        signal(SIGFPE, sighandler);

    } 
    else if (strcmp(argv[i] ,sig_name[9])==0 ){
        signal(SIGUSR1, sighandler);
    } 
    else if (strcmp(argv[i] ,sig_name[10])==0 ){
        signal(SIGSEGV, sighandler);
    } 
    else if (strcmp(argv[i] ,sig_name[11])==0 ){
        signal(SIGUSR2, sighandler);
    } 
    else if (strcmp(argv[i] ,sig_name[12])==0 ){
        signal(SIGPIPE, sighandler);
    } 
    else if (strcmp(argv[i] ,sig_name[13])==0 ){
        signal(SIGALRM, sighandler);
    } 
    else if (strcmp(argv[i] ,sig_name[14])==0 ){
        signal(SIGTERM, sighandler);
    } 
    else if (strcmp(argv[i] ,sig_name[15])==0 ){
        signal(SIGSTKFLT, sighandler);
    } 
    else if (strcmp(argv[i] ,sig_name[16])==0 ){
        signal(SIGCHLD, sighandler);
    } 
    else if (strcmp(argv[i] ,sig_name[17])==0 ){
        signal(SIGCONT, sighandler);
    } 
    else if (strcmp(argv[i] ,sig_name[19])==0 ){
        signal(SIGTSTP, sighandler);
    } 
    else if (strcmp(argv[i] ,sig_name[20])==0 ){
        signal(SIGTTIN, sighandler);
    } 
    else if (strcmp(argv[i] ,sig_name[21])==0 ){
        signal(SIGTTOU, sighandler);
    } 
    else if (strcmp(argv[i] ,sig_name[22])==0 ){
        signal(SIGURG, sighandler);
    } 
    else if (strcmp(argv[i] ,sig_name[23])==0 ){
        signal(SIGXCPU, sighandler);
    } 
    else if (strcmp(argv[i] ,sig_name[24])==0 ){
        signal(SIGXFSZ, sighandler);
    } 
    else if (strcmp(argv[i] ,sig_name[25])==0 ){
        signal(SIGVTALRM, sighandler);
    } 
    else if (strcmp(argv[i] ,sig_name[26])==0 ){
        signal(SIGPROF, sighandler);
    } 
    else if (strcmp(argv[i] ,sig_name[27])==0 ){
        signal(SIGWINCH, sighandler);
    } 
    else if (strcmp(argv[i] ,sig_name[28])==0 ){
        signal(SIGIO, sighandler);
    } else {
        printf("%s is not a valid signal. \n", argv[i]);
    }
}
//The program pauses itself continually (pause(2))
while (count != 3) {
    pause();
}

//The program emits a final status message to stderr that indicates 
    //the number of signals caught
    fprintf(stderr, "catcher: Total signals count = %d\n", sig_count);

}