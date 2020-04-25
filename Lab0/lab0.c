#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]){
FILE* inputfile;
char* filename = "data.txt";
char word[9];
char space[2];

    if (argv[1] == NULL){
        printf("There is no %s file.", filename);
    }
    
    if (argv[1] != NULL) {
        inputfile = fopen(argv[1],"r");
                printf("Original ASCII    Decimal  Parity\n");
                printf("-------- -------- -------- --------\n");
            while(!feof(inputfile)){
                //Get the first 8 bytes and prints a 0 for any spaces within the 8 bytes.
                
                    fgets(word, 9, inputfile);
                    int countone = 0;
                    int num = 8;
                    int dec = 0;
                        //Printing Original and counting the # of ones
                        for(int i = 0; i < 8; i++){
                            if(word[i] == ' '){
                                    printf("0");
                                }
                                    else{
                                        printf("%c", word[i]);
                                        if(word[i]=='1'){                                             
                                            countone++;
                                        }
                                    }  
                        }
                        //Calc decmial value
                            if(word[7] == '1'){
                                dec = 1;
                            }
                            if(word[6] == '1'){
                                dec = dec + 2;
                            }
                            if(word[5] == '1'){
                                dec = dec + 4;
                            }
                            if(word[4] == '1'){
                                dec = dec + 8;
                            }
                            if(word[3] == '1'){
                                dec = dec + 16;
                            }
                            if(word[2] == '1'){
                                dec = dec + 32;
                            }
                            if(word[1] == '1'){
                                dec = dec + 64;
                            }  
                        printf(" ");


                        fgets(space, 2, inputfile);
                    //Print the Ascii from the Ascii value
                        printf("       %c", dec);
                    //Print Decimal val
                        if (dec >= 0 && dec < 100){
                            printf("       %d ", dec);
                        }
                        if (dec >= 100 && dec < 1000){
                            printf("      %d ", dec);
                        }
                    //Prints even or odd for 1's
                        if(countone%2 == 0){
                            printf("EVEN");
                        } else {
                            printf("ODD");
                        }

                    printf("\n");
            }
        fclose(argv[1]);
    }
    return 0;
}