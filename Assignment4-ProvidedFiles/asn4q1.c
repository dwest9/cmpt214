/*
 * Mark Eramian
 * Instructor Model Solution
 * CMPT 214
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>

// TODO #define array sizes you need for your structure definition here.


// A structure for holding the data for a single item of loot.
typedef struct _lootitem {
    // TODO fill in the necessary definitions for structure members.
} LootItem;


/**
* Replace underscores in a string with spaces.
*
* str:    pointer to the first character of an character array containing a string.
* length: the length of the string stored in the array.
*/
void underscores_to_spaces(char* str) {
    for(size_t i=0; i < strlen(str); i++) {
        if( str[i] == '_' ) {
            str[i] = ' ';
        }
    }
}

/**
 * Read a line of the input file and return a pointer to a newly allocated LootItem structure
 * containing the loot item record data from the line read.  We assume the data file is properly
 * formatted and do not check for errors.
 *
 * Parameters:
 *
 * infile: a pointer to a file stream that has been opened for reading.
 *
 * Returns: a pointer to a new dynamically allocated LootItem structure containing the loot record read from the next
 *          line of the file stream 'infile'.
 *
 * Note: don't change the header of this function!
 */
LootItem* read_loot_record(FILE *infile) {
    // TODO Dynamically allocate a new LootItem structure.

    // TODO read the next line of the file to obtain the data for the members of the newly allocated
    //  LootItem structure and store the items in the structure.  Use underscores_to_spaces() to replace
    //  underscores in item names with spaces.

    // TODO Return the pointer to the newly allocated and initialized loot item.
}

/**
 * Free all dynamically allocated memory reachable from a pointer array of LootItems.
 *
 * Parameters:
 *
 * items:          A dynamically allocated pointer array where each element points to a dynamically allocated loot item.
 * num_loot_items: Length of the array 'items'.
 *
 * Returns: Nothing
 *
 * Postconditions: All dynamic memory reachable from the 'items' array is freed.
 */
void free_loot_memory(LootItem **items, const size_t num_loot_items) {
    // TODO Complete this function.  Think about this *carefully*.
}


int main(int argc, char* argv[]) {
    // TODO Verify correct number of command line arguments.  There should be only one argument besides
    //   the program executable name, in other words, argc should be exactly 2.  Terminate the program
    //   with an appropriate error message and exit code if there are not the correct number of command
    //   line arguments.
    //   REMINDER: Command line arguments are explained in Appendix C of the textbook.

    // TODO Open the file named in the command line argument.

    // TODO Read the number of loot items from the first line of the input file.

    // TODO Dynamically allocate an array of pointers to LootItem structures with exactly enough pointers
    //   to refer to all the loot item records in the datafile.  Hint: consult the "Background" section of the
    //   assignment PDF for information on how to dynamically allocate pointer arrays.


    // TODO Initialize the pointer array by repeatedly calling read_loot_record() and assigning each returned pointer
    //   to a different array element.


    // TODO Print a message indicating that file reading was completed successfully and
    //   how many records were read.

    // TODO Ask the user to enter the rarity as a string (Common, Uncommon, Rare, or Legendary).  If the user
    //   enters a rarity string that doesn't match one of the valid rarity strings that's OK, but don't read more
    //   than 9 characters, which is the maximum length of a valid rarity from the data file format.
    //

    // TODO Print out all data for all loot items of the rarity indicated by the user's choice.
    //   Data for an individual loot item should be on the same line.  On such a line, the various
    //   members of the LootItem structure should be separated by exactly one space.
    //   Beyond that, there are no special formatting requirements.  See the sample output.
    //   If the rarity string entered by the user wasn't a valid rarity string, simply print out no items (since
    //   the entered rarity won't match that of any of the loot items) -- this is actually not a special case! :)

    // TODO Clean up our mess.  Call free_loot_memory() to de-allocate all the memory we allocated and
    //   close the input file.

    return 0;
}

