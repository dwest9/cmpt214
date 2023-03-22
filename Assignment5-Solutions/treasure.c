#include <stdio.h>      // for printf(), putchar(), sscanf(), etc.
#include <stdlib.h>     // for atoi()
#include <string.h>     // for strlen()

#include "field.h"      // for field_t, init_field(), etc.
#include "position.h"   // for position_t, position_treasure(), etc.
#include "rand_num.h"   // for rand_init()

/*
 * symbols necessary only within treasure.c
 */
 
#define BUF_SIZE                80              // input buffer size
#define FIELD_SIZE_MIN  5

/*
 * functions used only within treasure.c
 */

/*
 * Return a Boolean value indicating whether the player is at the position of
 * the treasure.  Print a message to stdout if, indeed, the 
 * player has arrived at the treasure's location.
 *
 * Parameters:
 *    plyr_pos:  the player's position
 *    trsr_pos:  the position of the treasure 
 *
 * Returns: non-zero (TRUE) if the player's position and treasure's position
 *    are the same.  Returns zero (FALSE) otherwise.
 *
 * Assumptions: all output operations will succeed.
 */  
static int treasure_found( position_t plyr_pos, position_t trsr_pos ){
        if( position_same( plyr_pos, trsr_pos ) ){
                printf( "You have found the treasure!!\n" );
                return 1;
        } else {
                return 0;
        }
}

/*
 * Print a message on stdout describing how to use this program.
 *
 * Paremeters: none
 *
 * Returns: nothing
 *
 * Assumptions: all output operations will succeed.
 */
static void usage( void ) {
        printf( "Usage: treasure <field size>\n" );
}

/*
 * Obtain the first non-white space character on the next line of input on
 * stdin.  Handle various problematic cases.
 * 
 * Parameters: none
 *
 * Returns:
 *    - on success, returns the first non-white space character on the next line
 *      of input
 *    - if  EOF or error was detected on stdin, return the character 'q'.
 *    - if only white space input was provided, or a blank line was provided,
 *      return a null character.
 */
static char get_input( void ){
        char inbuf[BUF_SIZE];   // for input
        int inlen;              // length of string in inbuf
        char cmd;               // command given by user

        // Get a line of input up to BUF_SIZE-1 in length and place it in
        // the input buffer.
        if( fgets( inbuf, BUF_SIZE, stdin ) == NULL ){
                // handle EOF or error
                putchar( '\n' );
                return 'q';
        }
        // Remove any trailing newline character
        inlen = strlen(inbuf);
        if( inbuf[inlen-1] == '\n' ){
                inbuf[inlen-1] = '\0';
                --inlen;
        }
        // Check for blank line as input
        if( inlen == 0 ) {
                return '\0';
        }
        // Get the first non-white space character in the input 
        if( sscanf( inbuf, " %c", &cmd ) == 0 ) {
                // Handle the case of no non-white space character found in the
                // input buffer
                return '\0';
        }
        // Return the non-white space character
        return cmd;
}

/*
 * Main
 */
int main( int argc, char *argv[] ) {
        int fs;                         // playing field size
        field_t *fieldp;        // the playing field
        int quit;                       // flag when to exit the main loop
        position_t curpos;      // current position in the playing field
        position_t tsrpos;      // position of the treasure in the playing field

        // Check that we have one argument.
        if( argc != 2 ) {
                fprintf( stderr, "incorrect number of arguments, %d\n", argc-1 );
                usage();
                exit( 1 );
        }
        // Convert the command line argument to an integer.  It will be the field
        // size.  Check that the field size is big enough.
        fs=atoi( argv[1] );
        if( fs < FIELD_SIZE_MIN ) {
                fprintf( stderr, "field too small, %d\n", fs );
                exit( 2 );
        }
        // Initialize the random number generator to an arbitrary binary pattern
        // as the seed.  Otherwise, we will always get the same sequence of
        // random numbers; i.e., the same playing field.
        rand_init();
        // Create and initialize the playing field.
        fieldp=init_field( fs );
        // Determine a starting position for the player.
        curpos = position_player( fieldp );
        // Position the treasure, repeatedly trying until the treasure
        // is at a different position than the player.
        do {
                tsrpos = position_treasure( fieldp );
        } while( position_same( curpos, tsrpos ));
        // Print out the starting state of the playing field.
        print_field( fieldp );
        // Main loop: print a one-character prompt, get a command, process the 
        // command via switch-case, check for having reached the treasure, repeat.
        // Set the quit flag on input of the command to quit or if treasure found.
        // After a movement command, print the updated playing field.
        // Exit the loop when the quit flag is set.  
        quit = 0;               // initialize not to quit
        while( !quit ) {
                // Print the prompt
                putchar( '>' );
                // Get a command and process it
                switch( get_input() ) {
                        // do nothing on blank or no input
                        case '\0':
                                break;
                        // move up
                        case 'U':
                        case 'u':
                        case '8':
                                curpos = move( curpos, -1, 0, fieldp );
                                print_field( fieldp );
                                break;
                        // move down
                        case 'D':
                        case 'd':
                        case '2':
                                curpos = move( curpos, 1, 0, fieldp );
                                print_field( fieldp );
                                break;
                        // move right
                        case 'r':
                        case 'R':
                        case '6':
                                curpos = move( curpos, 0, 1, fieldp );
                                print_field( fieldp );
                                break;
                        // move left
                        case 'l':
                        case 'L':
                        case '4':
                                curpos = move( curpos, 0, -1, fieldp );
                                print_field( fieldp );
                                break;
                        // quit
                        case 'Q':
                        case 'q':
                        case 'E':
                        case 'e':
                                quit=1;
                                continue;
                                break;
                        // print
                        case 'P':
                        case 'p':
                                print_field( fieldp );
                                break;
                        // invalid input
                        default:
                                printf( "invalid command\n");
                                break;
                } // switch
                // If we are not supposed to quit, check whether the player has 
                // reached the treasure.  If so, quit.
                if( !quit ){
                        quit= treasure_found( curpos, tsrpos );
                }
        } // while
        
        // Done
        return 0;
}