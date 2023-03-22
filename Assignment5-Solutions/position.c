#include "field.h"      // for field_t
#include "position.h"   // for position_t
#include "rand_num.h"   // for rand_int(), rand_num()
#include "treasure.h"   // for TREASURE_CHAR, PLAYER_CHAR, FIELD_CHAR

/*
 * functions used only within treasure.c
 */

/*
 * Determine a random position in a playing field
 * 
 * Parameters:
 *    fieldp:      a pointer to a struct describing the current playing field
 *
 * Returns:  a position_t struct recording the determined position.
 *
 * Preconditions:   fieldp is a valid pointer
 *
 * Assumptions: library function rand_num() always succeeds
 */
static position_t random_position( field_t *fieldp ){
        int size;
        position_t pos;
        
        size=fieldp->grid_size;
        pos.r=rand_num( size );
        pos.c=rand_num( size );

        return pos;
}

/*
 * global functions
 */

position_t position_treasure( field_t *fieldp ){
        position_t pos;
        
        pos=random_position( fieldp );
        fieldp->grid[pos.r][pos.c]=TREASURE_CHAR;
        
        return( pos );
}

position_t position_player( field_t *fieldp ){
        position_t pos;
        
        pos=random_position( fieldp );
        fieldp->grid[pos.r][pos.c] = PLAYER_CHAR;
        
        return pos;
}


int position_same( position_t pos1, position_t pos2 ){
        return( (pos1.r==pos2.r) && (pos1.c == pos2.c) );
}

position_t move( position_t curpos, int r_incr, int c_incr, field_t* fieldp ) {
        int fs;
        
        fs = fieldp->grid_size;
        // Check if the move would be legal.  If so, proceed with the move.
        if( (curpos.r+r_incr < fs) && (curpos.c+c_incr<fs) &&
                (curpos.r+r_incr >= 0) && (curpos.c+c_incr>=0) ) {
                // Change the character at the current position
                fieldp->grid[curpos.r][curpos.c]=FIELD_CHAR;
                // new position
                curpos.r += r_incr;
                curpos.c += c_incr;
                // Change the character at the new position
                fieldp->grid[curpos.r][curpos.c]=PLAYER_CHAR;
        }
        // Return the resultant position, even if it didn't change
        return curpos;
}

