/*
 * Mark Eramian
 * Instructor Model Solution
 * CMPT 214
 */

#include <stdio.h>
#include <math.h>
#include <err.h>

/*
 * Compute the base experience point value for a monster.
 *
 * monster_level:  The monster's level, assumed to be between 1 and 50.
 * monster_type:   The monster's type, assumed to be between 1 and 3.
 *                 1=normal, 2=elite, 3=boss
 *
 * returns: the base experience point value of the monster described by the parameters.
 */
int base_xp(int monster_level, int monster_type) {

    // We assume that monster_type is always 1, 2, or 3.

    if(monster_type == 1) {
        // normal monster
        return (100 + 2.5 * monster_level);
    }
    else if(monster_type == 2) {
        // elite monster
        return (100 + pow(monster_level, 1.2));
    }
    else {
        // must be a boss!
        return (100 + pow(monster_level, 1.9));
    }
}

/*
 * Computes the adjusted experience point value of a monster accounting for difference in level between
 * the hero and the monster.
 *
 * monster_level:  the monster's level, assumed to be between 1 and 50.
 * hero_level:     the hero's level, assumed to be between 1 and 50.
 * base_xp:        the base experience point value of the monster (e.g. computed using base_xp())
 *
 * returns:        the adjusted experience of the monster described by the parameters
 *                 when killed by a hero of the specified hero_level.
 */
int adjusted_xp(int monster_level, int hero_level, int base_xp) {
    return base_xp * pow(1.2, (monster_level - hero_level));
}

/* Main program. */

int main() {
    int monster_level = 0;
    int hero_level = 0;
    int monster_type = 0;

    // Ask for the monster's level
    printf("What is the monster's level?  ");
    if( scanf("%d", &monster_level) != 1) {
        errx(1, "Error reading monster level.");
    }

    // Validate monster level
    while(monster_level < 1 || monster_level > 50) {
        printf("Error: monster level must be between 1 and 50.\n");
        printf("What is the monster's level?  ");
        if( scanf("%d", &monster_level) != 1) {
            errx(1, "Error reading monster level.");
        }
    }

    // Ask for the monster's type
    printf("What is the monster's type (1=normal, 2=elite, 3=boss)?  ");
    if( scanf("%d", &monster_type) != 1) {
        errx(1, "Error reading monster type.");
    }

    // Validate monster type.
    while(monster_type < 1 || monster_type > 3) {
        printf("Error: monster type must be 1 (normal) 2 (elite) or 3 (boss).  Try again.\n");
        printf("What is the monster's type (1=normal, 2=elite, 3=boss)?  ");
        if( scanf("%d", &monster_type) != 1) {
            errx(1, "Error reading monster type.");
        }
    }

    // Ask for the hero's level.
    printf("What is the hero's level?  ");
    if( scanf("%d", &hero_level) != 1) {
        errx(1, "Error reading hero level.");
    }

    // Validate hero level
    while(hero_level < 1 || hero_level > 50) {
        printf("Error: hero level must be between 1 and 50.\n");
        printf("What is the hero's level?  ");
        if( scanf("%d", &hero_level) != 1) {
            errx(1, "Error reading hero level.");
        }
    }

    // Compute the base xp and the adjusted xp
    int base = base_xp(monster_level, monster_type);

    int adjusted = adjusted_xp(monster_level, hero_level, base);

    // Report the results.
    printf("The monster is level %d.\n", monster_level);
    printf("The hero is level %d.\n", hero_level);
    printf("The monster's base XP value is: %d.\n", base);
    printf("The monster's adjusted XP is: %d.\n", adjusted);

    return 0;
}