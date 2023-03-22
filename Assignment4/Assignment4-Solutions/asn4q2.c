/*
 * Mark Eramian
 * Instructor Model Solution
 * CMPT 214
 */

#include <stdio.h>
#include <stdlib.h>
#include <err.h>

// A type definition for a magic square.
typedef struct _magic_square {
    int size;       // Size of the magic square.
    int *square;    // A 1D view of a 2D array with size rows and size columns containing the values in the entries
                    // of the magic square.
} MagicSquare;

// Note: It would be acceptable to use type size_t for the size of the magic square.   However, If we did this,
// we'd have to use type size_t for all the loop counters as well to avoid warnings about comparing signed types to
// unsigned types.

/**
 * Read a magic square from a file.
 *
 * Parameters:
 * filename:       Name of the file to read the magic square data from.
 *
 * Returns:        Pointer to a newly allocated MagicSquare.
 *
 */
MagicSquare* read_magic_square(char* filename) {
    FILE *fp;
    fp = fopen(filename, "r");
    if(fp == NULL) {
        perror(filename);
        errx(1, "Error opening file %s.\n", filename);
    }

    int square_size = 0;
    fscanf(fp, "%d", &square_size);

    // Allocate memory a new magic square.
    MagicSquare *sq = (MagicSquare*) malloc(sizeof(MagicSquare));
    if(sq==NULL) {
        errx(1, "Error allocating memory for magic square structure of size %d.", square_size);
    }

    // Initialize the newly allocated magic square, not forgetting to allocate memory for the 1D view of a 2D array
    // with square_size rows and columns
    sq->size = square_size;
    sq->square = (int*) malloc(sizeof(int) * square_size * square_size);
    if(sq->square == NULL) {
        errx(1, "Error allocating memory for magic square elements.");
    }

    // Since 1D views of 2D arrays are stored as first row, followed by second row, etc, we don't even
    // need to calculate linear indexes from 2D indexes -- we can just read everything into the 1D array in the
    // order it appears in the file.
    for(int i=0; i < square_size * square_size; i++) {
       fscanf(fp, "%d", &(sq->square[i]));
    }

    // Alternate approach to previous loop that uses pointer arithmetic:
    // int * squarep = sq->square;
    // for (i=0; i < square_size*square_size; i++ ) {
    //     fscanf( fp, "%d", squarep );
    //     squarep++;
    // }

    return sq;
}

/**
 * Test whether the data stored in a MagicSquare really is a magic square.
 *
 * Parameters:
 * magic_square:        A pointer to a MagicSquare.
 *
 * Returns:             0 indicating "false" if the square is NOT a magic square or 1 indicating "true" if the
 *                      array IS a magic square.
 */
int test_magic_square(MagicSquare *square) {
    // Recall that the linear index formula to get the element at row r, column c for an array of
    // square_size rows and square_size columns is r*square_size + c

    // NOTE: While Mark doesn't like it much, it is acceptable to use += operators to compute the sums,
    // that is, instead of writing expressions like x = x + y, write x += y.

    // Get the sum of the elements in the first row of the magic square.
    int first_row_sum = 0;
    for(int c=0; c < square->size; c++) {
        first_row_sum = first_row_sum + square->square[0*square->size + c];  // we could use just square->square[c] here
    }

    // Check the remaining rows to see if they have  the same sum as first_row_sum
    for(int r=1; r < square->size; r++) {
        // Compute the next row's sum.
        int this_row_sum = 0;
        for(int c=0; c < square->size; c++) {
            this_row_sum = this_row_sum + square->square[r*square->size + c];
        }

        // If this row's sum does not equal the first row's sum, we can immediately return "false".
        if(this_row_sum != first_row_sum) {
            return 0;
        }
    }

    // Check the sum of each column to see if they have the same sum as first_row_sum
    for(int c=0; c < square->size; c++) {
        int this_col_sum = 0;
        for(int r=0; r < square->size; r++) {
            this_col_sum = this_col_sum + square->square[r*square->size + c];
        }

        // If this column's sum does not equal the first row's sum, we can immediately return "false".
        if(this_col_sum != first_row_sum) {
            return 0;
        }
    }

    // All the row and column sums were the same (execution would have never reached here otherwise) so return "true".
    return 1;
}

void free_magic_square(MagicSquare* square) {
    free(square->square);
    free(square);
}

int main(int argc, char* argv[]) {

    // Make sure there is at least one filename argument besides the program name.
    if(argc < 2) {
        errx(1, "At least one filename argument is required.\n");
    }

    // Process each filename argument.
    for(int i=1; i < argc; i++) {
        MagicSquare *magic_square = read_magic_square(argv[i]);
        if(test_magic_square(magic_square)) {
            printf("%s is a magic square.\n", argv[i]);
        }
        else {
            printf("%s is NOT a magic square.\n", argv[i]);
        }
        free_magic_square(magic_square);
    }

    return 0;
}

