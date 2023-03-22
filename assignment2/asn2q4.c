// Name: David Emmanuel
// Student Number: 11298443
// Couse: cmpt214 section03 Assignment2 
// NSID: Doe869
// Instructor: Tony Kusalik



#include <stdio.h>
#include <math.h>
#include <err.h>
#include <stdlib.h>


/**
Purpose: the purpose of this program is to combine the base experience function and the adjusted experience funtion
in one funtion called xp(), that takes all parameter and computes the values for base and adjusted experience via 
the pointer parameter

* using the solution from question1
*/


/*
 * Compute the base experience point value for a monster.
 *
 * monster_level:  The monster's level, assumed to be between 1 and 50.
 * monster_type:   The monster's type, assumed to be between 1 and 3.
 *                 1=normal, 2=elite, 3=boss
 *
 * modify the pointer parameter for base experience value
 */

/*
 * Computes the adjusted experience point value of a monster accounting for difference in level between
 * the hero and the monster.
 *
 * monster_level:  the monster's level, assumed to be between 1 and 50.
 * hero_level:     the hero's level, assumed to be between 1 and 50.
 * base_xp:        the base experience point value of the monster (e.g. computed using base_xp())
 *
 * modify the pointer parameter for adjusted experience points
 */
void xp(int monster_level, int monster_type, int hero_level, int *base, int *xp_b) {

    // This new version of base_xp() doesn't assume everything is OK,
    // rather it terminates the program gracefully if it detects invalid data.

    // If monster level is out of range ...
    if( monster_level < 1 || monster_level > 50) {
        // Print an informative error message and terminate the program with an "abnormal" (non-zero) exit status.
        errx(1, "Monster level of %d is out of the valid range of 1 through 50.", monster_level);
    }

    switch(monster_type) {
        case 1:
            // normal monster
            *base= (100 + 2.5 * monster_level);
            break;
        
        case 2:
            // elite monster
            *base= (100 + pow(monster_level, 1.2));
            break;
    
        case 3:
            // boss monster
            *base= (100 + pow(monster_level, 1.9));
            break;
    
        default:
        // The monster type was an illegal value.
        // Print an informative error message and terminate the program with an "abnormal" (non-zero) exit status.
        errx(1, "The monster type of %d was invalid, it must be 1, 2, or 3.", monster_type);
    }


    // If hero level is out of range ...
    if( hero_level < 1 || hero_level > 50) {
        // Print an informative error message and terminate the program with an "abnormal" (non-zero) exit status.
        errx(1, "Hero level of %d is out of the valid range of 1 through 50.", hero_level);
    }
    *xp_b= *base * pow(1.2, (monster_level - hero_level));
}

int main() {

    int start_level = 0;
    int end_level = 0;
    int monster_type = 0;
    int hero_level = 0;
    int xp_base;
    int xp_adj;

    // Read all the inputs, making sure that something was read.
    // Our improved xp calculation functions, above, will verify that
    // any values read are in a valid range.

    printf("Monster starting level: ");
    if( scanf("%d", &start_level) != 1) {
        errx(1, "Error reading starting monster level.");
    }
    printf("Monster ending_level: ");
    if( scanf("%d", &end_level) != 1) {
        errx(1, "Error reading ending monster level.");
    }
    printf("Monster type (1=normal, 2=elite, 3=boss): ");
    if( scanf("%d", &monster_type) != 1) {
        errx(1, "Error reading monster type.");
    }
    printf("Hero Level: ");
    if( scanf("%d", &hero_level) != 1) {
        errx(1, "Error reading hero level.");
    }
    // Complete the program here.
    // the table header displaying the monster level and the exp point

    // the table title
    printf("Generating experience point table for Hero level = %d, Monster type = %d ...\n", hero_level, monster_type);

    // The table column headings
    printf("%-15s %-30s\n", "Monster level", "Experience Points (Adjusted)");

    // using for loop to implement the table for one row for each loop
    for(int i= start_level; i<= end_level; i++){
        xp(i, monster_type,hero_level,&xp_base,&xp_adj);
        printf("%-15d %-30d\n",i,xp_adj);
    }

    return 0;
}

