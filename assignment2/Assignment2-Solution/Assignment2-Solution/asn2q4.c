/*
 * Mark Eramian
 * Instructor Model Solution
 * CMPT 214
 */

#include <math.h>
#include <stdio.h>
#include <err.h>

/*
 * Compute base and adjusted monster experience points.
 *
 * monster_level:  Level of the monster between 1 and 50
 * hero_level:     Level of the hero between 1 and 50
 * monster_type:   The monster's type, assumed to be between 1 and 3.
 *                 1=normal, 2=elite, 3=boss
 * base_xp:        Pointer to an integer in which to store the calculated base experience point value.
 * adjusted_xp:    Pointer to an integer in which to store the calculated adjusted experience point value.
 *
 * Returns:        Nothing
 * Postconditions: Calculated base and adjusted experience point values are stored in the integers pointed to
 *                 by base_xp and adjusted_xp, respectively.
 */
void xp(int monster_level, int hero_level, int monster_type, int* base_xp, int* adjusted_xp) {
    // We assume that monster_type is always 1, 2, or 3.

    // If monster level is out of range ...
    if( monster_level < 1 || monster_level > 50) {
        // Print an informative error message and terminate the program with an "abnormal" (non-zero) exit status.
        errx(1, "Monster level of %d is out of the valid range of 1 through 50.", monster_level);
    }

    // If hero level is out of range ...
    if( hero_level < 1 || hero_level > 50) {
        // Print an informative error message and terminate the program with an "abnormal" (non-zero) exit status.
        errx(1, "Hero level of %d is out of the valid range of 1 through 50.", hero_level);
    }

    if(monster_type == 1) {
        // normal monster
        *base_xp = 100 + 2.5 * monster_level;
    }
    else if(monster_type == 2) {
        // elite monster
        *base_xp = 100 + pow(monster_level, 1.2);
    }
    else if(monster_type == 3) {
        // boss monster
        *base_xp = 100 + pow(monster_level, 1.9);
    }
    else {
        // The monster type was an illegal value.
        // Print an informative error message and terminate the program with an "abnormal" (non-zero) exit status.
        errx(1, "The monster type of %d was invalid, it must be 1, 2, or 3.", monster_type);
    }

    *adjusted_xp = *base_xp * pow(1.2, (monster_level - hero_level));
}

int main() {
    int start_level = 0;
    int end_level = 0;
    int monster_type = 0;
    int hero_level = 0;

    // Read all the inputs.  We don't require error checking for this program.

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

    // Print the table header information.
    printf("Generating experience point table for Hero Level = %d, Monster type = %d ...\n", hero_level, monster_type);
    printf("%-15s %-30s\n", "Monster Level", "Experience Points (Adjusted)");

    // Loop through monster level values, and output one row of the table per loop iteration.
    int base=0;
    int adj=0;

    for(int i = start_level; i <= end_level; i++) {
        xp(i, hero_level, monster_type, &base, &adj);
        printf("%-15d %-30d\n", i, adj);
    }

    return 0;
}

