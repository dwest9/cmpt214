// Name: David Emmanuel
// Student Number: 11298443
// Couse: cmpt214 section03 Assignment 5
// NSID: Doe869
// Instructor: Tony Kusalik


#ifndef _GAMEBOARD_H_
#define _GAMEBOARD_H_

//defining all MACROS
#define RESULT_HIT  0//if the given board position contains a ship and not shot at before
#define RESULT_MISS  1//if the given board position does not contain a ship and was not shot at before
#define RESULT_REPEAT  2//if the given board position was previously shot at


// A board position.
typedef struct board_position {
    unsigned int row;   // Row coordinate; for a gameboard with
                        // size width x height , must not greater
                        // than (board height )-1.
    unsigned int col;       // Column coordiante; for a gameboard with
                        // size width x height , must not be greater
                        // than (board width )-1.
} BoardPosition;

typedef struct _gameboard{
    unsigned int width;  // must be no less than 5 and no more than 26
    unsigned int height;  // must be no less than 5 and no more than 26
    int num_ships; // a random integer not less than 5 and not more than 10
    int num_shots; // initially zero
    BoardPosition *grid_positions;
    char* gameState;
} Gameboard;


/*
*Function first allocates memory to the Gameboard then randomly determines the number of ships there is(not less than 5
and not more than 10 ships) by calling the rand.init()function. And also randomly determining the locations of the ships

*@param width: Width of the gameboard (must be between 5 and 26)
*@param height: Height of the gameboard (must be between 5 and 26)

*Return: returns the gameboard
*/

Gameboard* create_gameboard(unsigned int width, unsigned int height);


/**
*This function shows grid of characters to be displayed 

*The character ’.’ to represent a position that the player has not shot at

*The character ’o’ to represent a position that the player has shot at and missed

*The charcter ’X’ to represent a position that the player has shot at and hit.
*/
void print_game_state(Gameboard *game);


/**
*This function accept a pointer to a Gameboard and a BoardPosition.
checking if the board position is valid and then increments the number of shots taken in the given Gameboard.

*Returns:  RESULT_HIT: if the given board position contains a ship and not shot at before
           RESULT_MISS if the given board position does not contain a ship and was not shot at before
           RESULT_REPEAT if the given board position was previously shot at
*/
int check_for_hit(Gameboard *g_board, BoardPosition b_position);

/**
This function accepts a pointer to a Gameboard and a BoardPosition and checks if the
board position is valid, this function also records in the game state that a hit has occurred at the
given game board position so that the new hit is reflected in the output of subsequent calls to
print_game_state().
*/
void record_hit(Gameboard *g_board, BoardPosition b_position);


/*
This function accepts a pointer to a Gameboard and a BoardPosition and checks if the
board position is valid, the function records in the game state that a miss has occurred at
the given game board position so that the new miss is reflected in the output of subsequent calls
to print_game_state().
*/
void record_miss(Gameboard *g_board, BoardPosition b_position);


/**
This function accepts a pointer to a Gameboard. If all ships have been sunk
by the player (can be checked by comparing the game state to the ship locations), this function
should returns non-zero; otherwise, it returns zero.
*/
int is_victory(Gameboard *g_board);


#endif
