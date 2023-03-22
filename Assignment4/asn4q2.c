// Name: David Emmanuel
// Student Number: 11298443
// Couse: cmpt214 section03 Assignment4 
// NSID: Doe869
// Instructor: Tony Kusalik

#include <stdio.h>
#include <stdlib.h>
#include <err.h>

typedef struct magic_square{
    int size;  //Size of the magic square.
    int *square; //A pointer to the first element of a 1D view of
    //a 2D array with size rows and size columns
    //containing the values in the entries of the
    //magic square in row-major order
    //(dynamically allocated)

}MagicSquare;

/*
 * This reads a data from file and store in a MagicSquare structure
 *
 * fp: a file name
 */
MagicSquare read_magic_square(char* filename){

    FILE *fp = fopen(filename, "r");  //opens the filename

    if(fp == NULL){
        perror("filename");
        errx(1, "error opening file");
    }

    int size;
    if(fscanf(fp, "%d", &size)!= 1){
        errx(2, "error getting size");
    }
    
    MagicSquare *mg = (MagicSquare*) malloc(sizeof(MagicSquare)*size);  // allocating memory for mg
    mg->size = size;
    mg->square = (int*)malloc(sizeof(int)*mg->size*mg->size);

    while(!feof(fp)){
        for(int i = 0; i < mg->size; i++) {
            for(int j = 0; j < mg->size; j++) {
                fscanf(fp, "%d\n", &mg->square[i * mg->size + j]);
            }
        }
    }
    return *mg;
}

/* This checks if pointer to a MagicSquare is a magic Square or not
 *
 * *magicSquare: a pointer to a MagicSquare
 *
 * return: 1 if the pointer to a MagicSquare is a valid magic square(true)
 *         else, 0 if not(false)
 */
int test_magic_square(MagicSquare *magicSquare){

    //declare variables
    int sum_row; 
    int sum_column; 
    int sum_diagonal;
    int isMagicSquare=0;

    //this calculates sum for columns in the magicsquare
    for(int  i = 0; i < magicSquare->size; i++){
        sum_column = 0;
        for(int j = 0; j < magicSquare->size; j++) {
            sum_column = sum_column + magicSquare->square[j * magicSquare->size + i];
        }
    }
    //this calculates the sum for rows in the magicsquare
    for(int i = 0; i < magicSquare->size; i++){
        sum_row = 0;
        for(int j = 0; j < magicSquare->size; j++) {
            sum_row = sum_row + magicSquare->square[i * magicSquare->size + j];
        }
    }

    //this calculates the sum for diagonal in the magicsquare
    sum_diagonal = 0;
    for(int i= 0;i<magicSquare->size;i++){
        for(int j=0; j<magicSquare->size;j++){
            if(i==j){
                sum_diagonal = sum_diagonal + magicSquare->square[i * magicSquare->size + j];
            }
        }
    }

    // this checks if the pointer to the magicsquare is valid comparing all rows, column and diagonals
    if((sum_column == sum_row) && (sum_column == sum_diagonal) && (sum_row == sum_diagonal)){  
        isMagicSquare = 1;  //true
    }
    else{
        isMagicSquare = 0;  //false
    }

    return isMagicSquare;

}


/**
* This void function takes one parameter that frees all dynamic memory 
* associated with the magic square pointed to by the parameter.
* 
*  *magicSquare: a pointer to MagicSquare
*
*  returns nothing
*/
void free_magic_square(MagicSquare *magicSquare){

    free((*magicSquare).square);
    if((magicSquare->square) == NULL){
        errx(3, "Error freeing all dynamic memory associated with magicsquare ");
    }
}

int main(int argc, char* argv[]) {

    if(argc == 1){
	    errx(4, "Error: Expected at least 1 argument, the filenames to read. Got 0 arguments instead.\n");
    } 

    for(int f = 1; f<argc; f++){
        MagicSquare mg = read_magic_square(argv[f]);
        int isMagic = test_magic_square(&mg);
        if(isMagic == 1){
	        printf("%s is a magic square.\n",argv[f]);
        } 
        else{
            printf("%s is not a magic square\n",argv[f]);
        }

        //this frees the magic square
        free_magic_square(&mg);

    }
    
    return 0;


}
