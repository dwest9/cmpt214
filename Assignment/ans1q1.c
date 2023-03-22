// Name: David Emmanuel
// Student Number: 11298443
// Assignment: cmpt214 Assignment1 
// NSID: Doe869

#include <stdio.h>
#include <err.h>

int main(){
    
    int integer;
    double realNumber;
    int integer2;

    // this prompt the user for an input for the integer and also terminates when wrong input is entered
    printf("Enter an integer: ");
    if(scanf("%d", &integer)!=1){
        err(1, "must input an integer number");
    }

    printf("Enter a decimal number: ");
    if(scanf("%lf", &realNumber)!=1){
        err(1, "must input a decimal number");
    }

    printf("Enter an integer: ");
    if(scanf("%d", &integer2)!=1){
        err(1, " must input an integer number");
    }

    printf("James and Andrew had a project which required them going from house to house collecting surverys.\n At the end of each day they had collected about %d surveys. They were to split the total into half after each collection.\n They had walked %.1lf miles today. And At the end of the month they each get $%d for their contribution to the research program.\n", integer, realNumber, integer2);

    return 0;

}
