#include <stdio.h>
#include <string.h>

int main(int argc, char** argv){
    char* file;
    FILE* fp = fopen("/lab6.log", "a");
    
        if(strcmp(argv[1],"1")== 0){
            fprintf(fp, "Pop mole1.");
        } else {
            fprintf(fp, "Pop mole2.");
        }
    fclose(fp);
    return 0;
}