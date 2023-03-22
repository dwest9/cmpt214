// Name: David Emmanuel
// Student Number: 11298443
// Couse: cmpt214 section03 Assignment 5
// NSID: Doe869
// Instructor: Tony Kusalik


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <err.h>
#include "gameboard.h"
#include "rand_num.h"
#include "gameplay.h"



/**
*Function first allocates memory to the Gameboard then randomly determines the number of ships there is(not less than 5
and not more than 10 ships) by calling the rand.init()function. And also randomly determining the locations of the ships

*@param width: Width of the gameboard (must be between 5 and 26)
*@param height: Height of the gameboard (must be between 5 and 26)

*Return: returns the gameboard
*/
Gameboard* create_gameboard(unsigned int width, unsigned int height){
    //allocating memory for gameboard
    Gameboard* game_board = malloc(sizeof(Gameboard));
    game_board->gameState = malloc(width*height*sizeof(char));
    
    if(game_board == NULL){
        errx(1, "Error allocating memory for game_board");
    }

    //if width is out of range must be no less than 5 and no more than 26
    if (width < 5 || width > 26){
        errx(2, "width of %d value is not within range.", width);
    }
    //if height is out of range must be no less than 5 and no more than 26
    else if (height < 5 || height > 26){
        errx(3, "height of %d value is not within range.", height);
    }
    else{
        game_board->width = width;
        game_board->height = height;
    }
    game_board->num_shots = 0;
    game_board->num_ships = 0;
    //randomly determining how many ships there are (there should be no less than 5 ships and no more than 10 ships)
    while(game_board->num_ships < 5){
        game_board->num_ships = rand_num(10);
    }
    game_board->grid_positions = malloc(game_board->num_ships*sizeof(BoardPosition));
    // for ship position random position for
    for(int i = 0; i < game_board->num_ships; i++){
        game_board->grid_positions[i].row =rand_num(game_board->width);
        game_board->grid_positions[i].col =rand_num(game_board->height);

    //a ship is the same as the already-determined random position for another ship, choose a different
    //random location for the current ship 
    }
    for(unsigned int i = 0; i < width*height; i++){
        game_board->gameState[i] = '.';
    }
    return game_board;
}


/**
*This function shows grid of characters to be displayed 

*The character ’.’ to represent a position that the player has not shot at

*The character ’o’ to represent a position that the player has shot at and missed

*The charcter ’X’ to represent a position that the player has shot at and hit.
*/
void print_game_state(Gameboard *game){
    printf(" ");
    for(size_t i = 0; i < game->height; i++){
        printf("%3zu", i+1);
    }
    printf("\n");
    //gameState by rows and col
    for(size_t i = 0; i < game->height; i++){
        printf("%c", toupper(i+'A'));
        for(size_t j = 0; j < game->width; j++){
            printf("%3c", game->gameState[i * game->width + j]);
        }
        printf("\n");
    }
}


/**
*This function accept a pointer to a Gameboard and a BoardPosition.
checking if the board position is valid and then increments the number of shots taken in the given Gameboard.

*Returns:  RESULT_HIT: if the given board position contains a ship and not shot at before
           RESULT_MISS: if the given board position does not contain a ship and was not shot at before
           RESULT_REPEAT: if the given board position was previously shot at
*/
int check_for_hit(Gameboard *g_board, BoardPosition b_position){
    // checking if the board position is valid
    if(b_position.row <= g_board->width && b_position.col <= g_board->height){
        //increments the number of shots taken in the gameboard
        g_board->num_shots +=1;
    }

    //RESULT_HIT if the given board position contains a ship and not shot at before
    for(size_t i=0; i < g_board->height; i++){
        if((g_board->grid_positions[i].row == b_position.row) &&(g_board->grid_positions[i].col == b_position.col) && (g_board->gameState[b_position.row*i +b_position.col] == '.')){
            return RESULT_HIT;
        }
        //RESULT_MISS if the given board position does not contain a ship and was not shot at before
        else if((g_board->grid_positions[i].row == b_position.row) && (g_board->grid_positions[i].col != b_position.col) && (g_board->gameState[b_position.row*i + b_position.col] == '.')){
            return RESULT_MISS;
        }
        //RESULT_REPEAT if the given board position was previously shot at
        else if((g_board->grid_positions[i].row == b_position.row) && (g_board->grid_positions[i].col == b_position.col) && (g_board->gameState[b_position.row*i + b_position.col] == 'X')){
            return RESULT_REPEAT;
        }
    }
    return 0;
}


/**
This function accepts a pointer to a Gameboard and a BoardPosition and checks if the
board position is valid, this function also records in the game state that a hit has occurred at the
given game board position so that the new hit is reflected in the output of subsequent calls to
print_game_state().
*/
void record_hit(Gameboard *g_board, BoardPosition b_position){
    g_board->gameState[b_position.row* g_board->width + b_position.col]= 'X'; // hit
}


/*
This function accepts a pointer to a Gameboard and a BoardPosition and checks if the
board position is valid, the function records in the game state that a miss has occurred at
the given game board position so that the new miss is reflected in the output of subsequent calls
to print_game_state().
*/
void record_miss(Gameboard *g_board, BoardPosition b_position){
    g_board->gameState[b_position.row* g_board->width + b_position.col]= 'o'; // hit
}


/**
This function accepts a pointer to a Gameboard. If all ships have been sunk
by the player (can be checked by comparing the game state to the ship locations), this function
should returns non-zero; otherwise, it returns zero.
*/
int is_victory(Gameboard *g_board){
    int num =0;
    for(int i = 0; i < g_board->num_ships; i++){
        if(g_board->gameState[i] == 'o'){
            num++;
        }
    }
    if(num == g_board->num_ships){
        return 1;
    }

    else{
        return 0;
    }
}

