#include <err.h>        // for err()
#include <stdio.h>      // for putchar()
#include <stdlib.h>     // for malloc(), calloc(), NULL
#include <string.h>     // for memset()

#include "field.h"      // for field_t
#include "treasure.h"   // for FIELD_CHAR

field_t* init_field( int sz ){
        field_t* nfieldp;       // pointer to new field
        char *grid_row;         // pointer to a row of the grid
        int i;
        
        // Allocate a new playing field
        nfieldp=(field_t *)malloc( sizeof( field_t ) );
        if( nfieldp == NULL ) {
                err( 3, NULL);  // on alloc error, abort
        }
        nfieldp->grid_size=sz;
        // Allocate a vector of pointers to the rows
        nfieldp->grid=(char **)calloc( sz, sizeof( char *));
        if( nfieldp->grid == NULL ) {
                err( 3, NULL);  // on alloc error, abort
        }
        // For each row, allocate a pointer to the columns
        for ( i=0; i<sz; ++i ){
                grid_row=(char *)calloc( sz, sizeof( char ));
                if( grid_row == NULL ) {
                        err( 3, NULL ); // on alloc error, abort
                }
                // Set all the columns in the row to FIELD_CHAR
                memset( grid_row, FIELD_CHAR, sz );
                // Record the pointer to the initialized row
                nfieldp->grid[i] = grid_row;
        }
        return nfieldp;
}

void print_field( field_t *fieldp ){
        int i, j;
        int size;
        char *grid_row;         // pointer to a row of the grid
        
        size=fieldp->grid_size;
        for( i=0; i<size; ++i ) {
                // Output row i
                grid_row=fieldp->grid[i];
                for( j=0; j<size; ++j ) {
                        putchar( *(grid_row++) );// Dereference grid_row, then increment
                }                                // it. Could also be putchar(grid_row[j])
                                                 // or putchar(fieldp->grid[i][j])
                // Output a newline at the end of the row
                putchar( '\n' );
        }
}
