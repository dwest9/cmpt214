// Name: David Emmanuel
// Student Number: 11298443
// Assignment: cmpt214 Assignment1 
// NSID: Doe869


#include <stdio.h>
#include <err.h>
#include <math.h>

int main() {
    int monster_l;
    int hero_l;
    int baseXP;
    int adjustedXP;
    double result;

    // this prompt the user for an input for the integer and also terminates when wrong input is entered
    printf("What is the monster's level?  ");
    if(scanf("%d", &monster_l)!=1){
        err(1, "input error: must be an integer value");
    }
    printf("What is the hero's level?  ");
    if(scanf("%d", &hero_l)!=1){
        err(1, "input error: must take an integer value");
    }

    printf("The monster is level %d.\n", monster_l);
    printf("The hero is level %d.\n", hero_l);

    // This Calculates the base exerience and the adjusted experience
    baseXP = (100 + (2.5 * monster_l));
    result = pow(1.2, (monster_l - hero_l));
    adjustedXP = baseXP * result;

    printf("The monster's base XP value is %d.\n", baseXP);
    printf("The monster's adjusted XP is %d.\n", adjustedXP);
}


