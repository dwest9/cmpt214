/*
 * Mark Eramian
 * Instructor Model Solution
 * CMPT 214
 */

#include <stdio.h>
#include <math.h>
#include <err.h>

int main() {
    int monster_level = 0;
    int hero_level = 0;

    // Obtain inputs from the console.
    printf("What is the monster's level?  ");
    if( scanf("%d", &monster_level) != 1 )
    {
        errx(1, "Error reading monster level.");
    }
    printf("What is the hero's level?  ");
    if( scanf("%d", &hero_level) != 1 ) {
        errx(1, "Error reading hero level.");
    };

    // Compute the base xp and the adjusted xp
    int base_xp = 100 + 2.5 * monster_level;
    int adjusted_xp = base_xp * pow(1.2, (monster_level - hero_level));

    // Report the results.
    printf("The monster is level %d.\n", monster_level);
    printf("The hero is level %d.\n", hero_level);
    printf("The monster's base XP value is %d.\n", base_xp);
    printf("The monster's adjusted XP is %d.\n", adjusted_xp);

    return 0;
}