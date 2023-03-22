// Name: David Emmanuel
// Student Number: 11298443
// Assignment: cmpt214 Assignment1 
// NSID: Doe869



#include <stdio.h>
#include <math.h>
#include <err.h>


int baseXP(int monster_l, int monster_t){
    /**
    Purpose:
        creates a function that computes the value for base experience(baseXP) for each monster type
    Pre-conditions:
        :param monster_l: interger parameter, from range 1 to 50 (inclusive)
        :param monster_t: interger parameter, from range 1 to 3 (inclusive)
    Return: this returns an integer for the calculated value of base experience
    */ 
    
    int xp;
    double power;
    
    if(monster_t == 1){
	xp = (100 + (2.5 * monster_l));
	return xp;
    }
    if(monster_t == 2){
	power = pow(monster_l, 1.2);
	xp = 100 + power;
	return xp;
    }
    if(monster_t == 3){
	power = pow(monster_l, 1.9);
	xp = 100 + power;
	return xp;
    }
    return 0;
}


int adjustedXP(int baseXP, int monster_l, int hero_l){

     /**
    Purpose:
        creates a function that calculates the value for the adjusted base type for each monster level and hero level
        adjustedXP = baseXP * 1.2^(monster_l - hero_l) from the calculation of question2
    Pre-conditions:
        :param baseXP: int value for base experienced calculated from basXP
        :param monster_l: interger parameter, from range 1 to 50 (inclusive)
        :param monster_t: interger parameter, from range 1 to 3 (inclusive)
    Return: this returns an integer for the calculated value of adjusted base experience
    */ 

    // declare
    double powr;
    int adjust;
    
    // computes the calculation adjustedXP
    powr = pow(1.2, (monster_l - hero_l));
    adjust = baseXP * powr;
    return adjust;

    return 0;
}


int main(){

    // declaration of variables 
    int m_level;
    int m_type;
    int h_level;
    int XP;
    int XP_a;

    // this prompt the user for an input for the monster level and also terminates when wrong input is entered
    printf("What is the monster's level? ");
    if(scanf("%d", &m_level)!=1){
        errx(1,"input error: normal termination, must take an integer value btw 1 to 50");
    };


    //this check for invalid inputs and diplays the error message
    while(m_level < 1 || m_level > 50){
	printf("Error: monster level must be between 1 and 50.\n");
        printf("What is the monster's level? ");
        scanf("%d", &m_level);
    }

    // this prompt the user for an input for the monster level and also terminates when wrong input is entered
    printf("What is the monster's type (1=normal, 2=elite, 3=boss)? ");
    if(scanf("%d", &m_type)!=1){
        errx(1, "input error: normal termination, must take an integer value btw 1 to 3");
    };


    //this check for invalid inputs and diplays the error message
    while(m_type < 1 || m_type > 3){
	printf("Error: monster type must be 1 (normal) 2 (elite) or 3 (boss).\n");
        printf("What is the monster's type (1=normal, 2=elite, 3=boss)?  ");
        scanf("%d", &m_type);
    }

    
    // this prompt the user for an input for the monster level and also terminates when wrong input is entered
    printf("What is the hero's level? ");
    if(scanf("%d", &h_level)!=1){
        errx(1, "input error: normal termination, must take an integer value btw 1 to 50");
    };
    

    //this check for invalid inputs and diplays the error message
    while(h_level < 1 || h_level > 50){
	printf("Error: hero level must be between 1 and 50.\n");
        printf("What is the monster's level? ");
        scanf("%d", &h_level);
    }


    printf("The monster is level %d\n", m_level); 
    printf("The hero is level %d\n", h_level);

    XP = baseXP(m_level, m_type);
    printf("The monster's base XP value is: %d\n", XP);
  
    XP_a = adjustedXP(XP, m_level, h_level);
    printf("The monster's adjusted XP is: %d\n", XP_a);

    return 0;
}

