#ifndef FIELD_H
#define FIELD_H

/*
 * Informally a playing field consists of a size and a 2D grid or characters.  
 * Formally, a field_t struct consists of two elements, grid_size of type int
 * and grid of type (char**).  The 2D grid is realized through a vector (1D
 * array) of pointers of type (char *).  Element grid in a field_t struct
 * points to the beginning of that vector.  Each pointer then points to a
 * vector of elements of type char.  If t is of type (field_t *), then the
 * character at row r, column c in the grid can be accessed as t->grid[r][c].
 */
typedef struct _field {
        int grid_size;          // the grid size (both #rows and #cols)
        char ** grid;           // the actual 2D grid of characters
} field_t;

/*
 * Dynamically allocate a playing field and initialize all the characters
 * representing positions on the playing field.
 *
 * Parameters:
 *    sz: the size of one dimension of the playing field; i.e. the playing field
 *        is of size sz x sz
 *
 * Returns: on success, returns a pointer to the allocated structure describing
 *    the initialized playing field.  On error (e.g. memory allocation error), 
 *    causes program termination with a non-zero exit status.
 *
 * Preconditions: assumes that sz > 0
 *
 * Postconditions: on success, each character representing the playing field
 *    is set to FIELD_CHAR.
 */
field_t* init_field( int sz );

/* 
 * Print the grid in the playing field pointed to by fieldp on the standard
 * output. It is assumed that position [0][0] of the playing
 * field as at the top left of the output, and position [s-1][s-1] is at the
 * bottom right, where s is the size of the playing field.
 *
 * Parameters:
 *    fieldp: a pointer to the representation of a playing field
 * 
 * Returns: nothing
 *
 * Preconditions: fieldp is a valid pointer
 *
 * Assumptions: all output operations will succeed.
 */
void print_field( field_t *fieldp );

#endif
