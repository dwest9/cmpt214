#ifndef POSITION_H
#define POSITION_H

#include "field.h"      // for field_t

/*
 * a position_t consists of a row number and a column number, both
 * integers
 */
typedef struct _position {      
        int r;
        int c;
} position_t;


/*
 * Determine a random position for a treasure in a playing field and mark the
 * position of the treasure.
 * 
 * Parameters:
 *    fieldp:      a pointer to a struct describing the current playing field
 *
 * Returns:  a position_t struct recording the determined position.
 *
 * Preconditions:   fieldp is a valid pointer
 *
 * Postconditions:  the character at the determined position is set to
 *    TREASURE_CHAR.
 */
position_t position_treasure( field_t *fieldp );

/*
 * Determine a random position for a player in a playing field and mark the
 * position of the player.
 * 
 * Parameters:
 *    fieldp:      a pointer to a struct describing the current playing field
 *
 * Returns:  a position_t struct recording the determined position.
 *
 * Preconditions:   fieldp is a valid pointer
 *
 * Postconditions:  the character at the determined position is set to
 *    PLAYER_CHAR.
 */
position_t position_player( field_t *fieldp );

/*
 * Compare positions pos1 and pos2 and return
 * a boolean value indicating whether or not they are the same
 *
 * Parameters:
 *    pos1:  a position in a playing field
 *    pos2:  a position in a playing field
 *
 * Returns: non-zero (TRUE) if the positions are the same, 
 *    zero (FALSE) if the positions are different
 */
int position_same( position_t pos1, position_t pos2 );

/* 
 * Move from the current position in the playing field provided that the move
 * will result in a position within the bounds of the playing field (in-bounds).
 * If the move would result in a position beyond the bounds of the playing
 * field (out-of-bounds), the move is ignored.  In case of an in-bounds move, 
 * update the characters in the playing field to reflect the new position.
 *
 * Parameters:
 *    curpos:  the current position
 *    r_incr:  the amount by which to increment the row component of the 
 *             position (could be positive or negative)
 *    c_incr:  the amount by which to increment the column component of the 
 *             position (could be positive or negative)
 *    fieldp:  a pointer to a struct describing the current playing field
 *
 * Returns:
 *    If the move resulted in a position that was in-bounds, then the 
 *    new position is returned; if the move would have resulted in a position  
 *    that was out-of-bounds, then return the original position unchanged.
 *
 * Preconditions:
 *    - fieldp is a valid pointer
 *    - curpos is a valid position within the playing field.
 *
 * Postconditions: if the move resulted in a position that was in-bounds, reset 
 *    the character at the original position in the playing field grid to  
 *    FIELD_CHAR and set the character at the new position to PLAYER_CHAR. 
 */    
position_t move( position_t curpos, int r_incr, int c_incr, field_t* fieldp );


#endif
