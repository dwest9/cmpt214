/*
 * Mark Eramian
 * Instructor Model Solution
 * CMPT 214
 */


#include <stdio.h>
#include <err.h>

int main() {
    int miles = 0;
    int num_spirits = 0;
    float mushrooms = 0.0;

    printf("Enter an integer: ");
    if( scanf("%d", &miles) != 1) {
        errx(1, "Error reading the first integer.");
    }

    printf("Enter a real number: ");
    if( scanf("%f", &mushrooms) != 1) {
        errx(1, "Error reading the second integer.");
    }

    printf("Enter an integer: ");
    if( scanf("%d", &num_spirits) != 1) {
        errx(1, "Error reading the third integer.");
    };

    printf("A young hobbit was walking in the woods about %d miles form home.\n", miles);
    printf("After collecting %f baskets of tasty mushrooms they were beset\n", mushrooms);
    printf("upon by %d restless spirits.  The hobbit took a bite of a mushroom\n", num_spirits);
    printf("and offered some to the spirits.  The spirits, their hunger sated,\n");
    printf("left the hobbit in peace.\n");

    return 0;
}