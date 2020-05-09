#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// void matrix_add(int block, int size, int scalar){
    
//     for(int i = 1;i <= size; i++){
//         for(int j = 1; j <= size; j++){
//             block[i][j] += scalar;
//         }
//     }

// }

int main(int argc, char** argv){

    // clock_t start_time;
    // start_time = clock();
    // printf("START: %ld\n", start_time);

    srand(time(0));

    int scalar = (rand() %201)- 100;
    printf("%d\n", scalar);

    int block_size = size/blocks;

        for(int x = 1; x <= blocks; x++){
            for(int y = 1; y <= blocks; y++){
                //async read request matrix[x,y]

                //block=async read return martrix[x,y]

                //matrix_add(block,block_size,scalar)

                //async write request block

                //async write return block
                
            }
        }

    return 0;

}