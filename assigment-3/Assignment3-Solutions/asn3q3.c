/*
 * Mark Eramian
 * Instructor Model Solution
 * CMPT 214
 */

#include <stdio.h>
#include <string.h>
#include <err.h>

// Since a quest name may have up to 50 characters, and we are extracting the quest name from
// the first column of the tabular file, we need 50 characters + 1 for the null character to
// hold quest names.
//
// It is also acceptable to use a local variable in main() of type const size_t to store this value.
#define MAX_QUESTNAME_LENGTH 51

// Similary, since the maximum length of a single line is 80 characters not including the newline, we'll need
// 80 characters to store the character data, plus 1 for the newline, plus one for a null character
//
// It is also acceptable to use a local variable in main() of type const size_t to store this value.
#define MAX_LINE_LENGTH 82


/*
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


int main() {

    // Attempt to open the input file, exiting gracefully if it could not be found.
    FILE *infile = fopen("../Assignment3/fileinput-quests/quests.txt", "r");
    if(infile == NULL) {
        perror("quests.txt");
        errx(1, "Error: could not open quests.txt for reading.");
    }

    // Print table header row.
    printf("%-50s  %-12s  %-10s\n", "Quest Name", "Quest Level", "Experience");

    char buffer[MAX_LINE_LENGTH];
    int linenum = 0;

    // Repeatedly read lines until we reach the end of the file.
    while( fgets(buffer, MAX_LINE_LENGTH, infile) != NULL) {
        // Not required, but this allows us to report which file  line any error occurs on.
        linenum = linenum + 1;

        // Break up the current line of the file into its individual data elements.
        char questName[MAX_QUESTNAME_LENGTH];
        unsigned int level = 0;
        unsigned int xp = 0;
        if( sscanf(buffer, "%50s%u%u", questName, &level, &xp) != 3) {
            errx(1, "Error reading file on line %d.", linenum);
        }

        // Replace underscores in the quest name with spaces.
        underscores_to_spaces(questName);

        // Print the table row.
        printf("%-50s  %-12u  %-10u\n", questName, level, xp);
    }

    fclose(infile);

    return 0;
}
