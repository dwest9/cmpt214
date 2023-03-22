// Name: David Emmanuel
// Student Number: 11298443
// Couse: cmpt214 section03 Assignment3 
// NSID: Doe869
// Instructor: Tony Kusalik


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>



/**
- this is void function that takes one parameter, which is a character array containing strings to replace 
- underscores with space,using a for loop to iterate through the filename and takes no return 
*/

void underscore_to_space(char under_score[]){
    for(size_t space = 0; space <= strlen(under_score); space++){
        if(under_score[space] == '_'){
            under_score[space] = ' ';
        }
    }
}


int main() {

    const int MAX_LINE_LENGTH = 82;
    const int MAX_QUEST_LENGTH = 51;

    //read lines of the file one at a time
    char buffer[MAX_LINE_LENGTH + 1];
    
    
    char filename[] = "quests-doe869.txt";

    const int LEVEL_LENGTH = 12;
    const int EXPERIENCE_LENGTH = 10;
    int linum =0;

    //opens the quests.txt or quests-doe869.txt for reading and error checking
    FILE *fp = fopen(filename, "r");
    if(fp == NULL){
        perror("quests-doe869.txt");
        errx(1, "error opening quest.txt");
        
    }

    printf("%-50s  %-12s  %-10s\n", "Quest Name", "Quest Level", "Experience");

    while(fgets(buffer, MAX_LINE_LENGTH+1, fp) != NULL){
        linum = linum + 1;

        // this extract data item from this line using sscanf 
        char quest_len[MAX_QUEST_LENGTH+1];
        char quest_level[LEVEL_LENGTH+1];
        char quest_exp[EXPERIENCE_LENGTH+1];
       
        if ( sscanf (buffer, "%51s %12s %10s", quest_len, quest_level, quest_exp ) !=3){
            errx(1, "error reading file on line %d", linum);
        }
        // this calls the underscore function
        underscore_to_space(quest_len);
        printf ("%-51s %-13s %-11s\n", quest_len , quest_level , quest_exp );
    }


    // this shows If fgets () failed and we did not reach the
    // end of the file then this an error .
    if( ! feof ( fp ) ) {
        perror ("quests-doe869.txt");
        errx (1, " Error reading file .");

    }

    // closes the file
    fclose(fp);


    return 0;
}


