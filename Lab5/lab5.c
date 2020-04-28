#include <stdio.h>
#include <stdlib.h>

int main(int argc,char** argv) {

    unsigned int address = atoi(argv[1]);
    unsigned int page_num = address/4096;
    unsigned int offset = address%4096;

    if(argc == 2) {
        printf("The address %d contains:\n", address);
        printf("page number = %d\n", page_num);
        printf("offset = %d\n", offset);
    } else {
        return 0;
    }
    return 0;

}