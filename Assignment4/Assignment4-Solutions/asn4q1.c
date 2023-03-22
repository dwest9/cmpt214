/*
 * Mark Eramian
 * Instructor Model Solution
 * CMPT 214
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>

// #define array sizes you need for your structure definition here.

#define LOOT_NAME_ARRAY_LENGTH 31     // The maximum number of characters in a loot item name (30) in the file plus
                                      // room for a null character.
#define FILE_LINE_ARRAY_LENGTH 81     // The maximum length of a line in the datafile, plus room for a null character.
#define RARITY_LENGTH 10              // Maximum length of the name of a rarity level (9), plus an extra null character.

// A structure for holding the data for a single item of loot.
typedef struct _lootitem {
    char name[LOOT_NAME_ARRAY_LENGTH];
    unsigned int item_level;
    unsigned int value;
    char rarity[RARITY_LENGTH];
    unsigned int durability;
    float probability;
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
    // Dynamically allocate a new LootItem structure.
    LootItem *loot = (LootItem*)malloc(sizeof(LootItem));
    if( loot == NULL) {
        errx(1, "Error allocating memory for a loot item in read_loot_record().");
    }

    // Following the paradigm for tabluar files in the textbook, we read the line with fgets()
    // first, and then use sscanf() to extract the individual data items.
    char line[FILE_LINE_ARRAY_LENGTH];
    fgets(line, FILE_LINE_ARRAY_LENGTH, infile);

    if( sscanf(line, "%s%u%u%s%u%f", loot->name, &(loot->item_level), &(loot->value), loot->rarity,
           &(loot->durability), &(loot->probability)) != 6 ) {
        errx(1, "Failed to read expected number of data items in read_loot_record().");
    }

    // Convert underscores in the item name to spaces.
    underscores_to_spaces(loot->name);

    // Return the pointer to the newly allocated and initialized loot item.
    return loot;
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
    for(size_t i=0; i < num_loot_items; i++) {
        free(items[i]);
    }
    free(items);
}

int main(int argc, char* argv[]) {
    // Verify correct number of command line arguments.  There should be only one argument besides
    // the program executable name, in other words, argc should be exactly 2.  Terminate the program
    // if there are not the correct number of command line arguments.
    if(argc != 2) {
        errx(1, "Error: Expected exactly one argument, the filename to read. Got %d arguments instead.\n", argc-1);
    }

    // Open the file named in the command line argument, with an error check to make sure it was successful.
    // Terminate the program if the file was not opened successfully.
    FILE *infile = fopen(argv[1], "r");
    if(infile == NULL) {
        perror(argv[1]);
        errx(1, "Error: was not able to open %s for reading.\n", argv[1]);
    }

    // Read the first line of the file to get the number of lines in the file.
    // We use the standard paradigm for reading tabular files - use fgets() to read the line
    // and then extract the number using sscanf().
    char line[FILE_LINE_ARRAY_LENGTH];
    fgets(line, FILE_LINE_ARRAY_LENGTH, infile);
    int num_loot_items = 0;
    sscanf(line, "%d", &num_loot_items);

    // Dynamically allocate an array of pointers to LootItem structures with exactly enough pointers
    // to refer to all the loot item records in the datafile.  Hint: consult the "background" section of the
    // assignment PDF for information on dynamically allocated pointer arrays.
    LootItem** items = (LootItem**) malloc(sizeof(LootItem*) * num_loot_items);
    if(items == NULL) {
        errx(1, "Error allocating a pointer array for LootItem storage.");
    }

    // Fill the pointer array by repeatedly calling read_loot_record() and assigning each returned pointer
    // to a different array element.
    for(int i=0; i < num_loot_items; i++) {
        items[i] = read_loot_record(infile);
    }

    // Print a message indicating that file reading was completed successfully, and
    // how many records were read.
    printf("Successfully read %d loot items from %s.\n\n", num_loot_items, argv[1]);

    // Ask the user to enter the rarity as a string (Common, Uncommon, Rare, or Legendary).  If the user
    // enters a rarity string that doesn't match one of the valid rarity strings that's OK, but don't read more
    // than 9 characters, which is the maximum length of a valid rarity from the data file format.

    printf("List loot of what rarity? (Common, Uncommon, Rare, Legendary): ");
    char rarity[RARITY_LENGTH];
    fgets(rarity, RARITY_LENGTH, stdin);
    if(rarity[strlen(rarity)-1] == '\n') {  // Remove the newline in the event fewer than 9 characters were read
        rarity[strlen(rarity)-1] = '\0';    // Note: we can't do this with scanf() because scanf() won't let us
                                            // restrict the number of characters read.
    }

    // Print out all data for all loot items of that rarity.  Data for an individual loot item should be on
    // the same line.  On such a line, the various fields of the record should be separated by exactly one space.
    // Beyond that, there are no special formatting requirements.  See the sample output.
    for(int i=0; i < num_loot_items; i++) {
        if(strcmp(items[i]->rarity, rarity)==0) {
            printf("%s %u %u %s %u %f\n", items[i]->name, items[i]->item_level, items[i]->value, items[i]->rarity,
                   items[i]->durability, items[i]->probability);
        }
    }

    // Clean up our mess.  Call free_loot_memory() to de-allocate all the memory we allocated and
    // close the input file.
    free_loot_memory(items, num_loot_items);
    fclose(infile);

    return 0;
}

