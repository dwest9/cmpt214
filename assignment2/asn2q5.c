// Name: David Emmanuel
// Student Number: 11298443
// Couse: cmpt214 section03 Assignment2 
// NSID: Doe869
// Instructor: Tony Kusalik



#include <stdio.h>
#include <err.h>
// included this library because of the switch statement used
#include <stdlib.h>
// included the boolean library because of the boolean value used in the while loop
#include <stdbool.h>


/*
 * Prints the menu and total dollar amount ordered to console.
 *
 * total:     the total amount of food ordered so far in dollars.
 *
 * returns: nothing
 */
void print_menu(float total) {
    printf("Today's Menu\n");

    // TODO: Print out the names and prices of your menu items.  Label each menu item
    //  with a number starting from 1 (see the sample output).

    printf("1. Original Chicken Sandwich - $11.99\n");
    printf("2. Szechuan Flame Chicken Sandwich - $13.99\n");
    printf("3. Spicy Cumin Chicken Sandwich(spicy) - $10.99\n");
    printf("4. BBQ Chicken Sandwich - $15.99\n\n");
    printf("   (Dhey Signiture Drinks ~ ~ ~) \n\n");
    printf("5. Matcha Strawberry Milk - $8.99\n");
    printf("6. Lychee Smoothie Macchiato - $9.99\n");
    printf("7. Fresh Taro Latte(Milk Tea) - $5.99\n\n");


    printf("So far your order totals $%.2f.\n", total);
    printf("Which item should we add to your order (enter 0 if finished)? ");
}

/*
 * Reads an integer menu choice from the console.
 *
 * Returns: the integer menu choice read, or terminates abnormally
 *          if an integer could not be read at all.
 *
 * Note: does not check if the integer read corresponds to a valid menu item, only whether
 *       an integer was successfully read.
 */
int get_menu_choice() {
    int choice = 0;

    if( scanf("%d", &choice) != 1) {
        errx(1, "Error reading menu choice.");
    }

    return choice;
}

int main() {
    // TODO: Write your program here.

    /**
    * Purpose: This part takes the resturant title and also uses the switch statement to get price of any choice taken by the user
    * and added to the total which continuously adds up until the user exist the menu. 
    */
    printf("Welcome To Dhey's Chicken Sandwich Resturant\n");
    double total=0;
    int choice =0;
    while(true){
        print_menu(total);
        choice = get_menu_choice();
        switch(choice){
           case 1:
                total += 11.99;
                break;
            case 2:
                total += 13.99;
                break;
            case 3:
                total += 10.99;
                break;
            case 4:
                total += 15.99;
                break;
            case 5:
                total += 8.99;
                break;
            case 6:
                total += 9.99;
                break;
            case 7:
                total += 5.99;
                break;
            case 0:
            // displays the total price after all added up then it exist with a pleasant message
                printf("Your order grand total is now $%.2f. Have a great day!\n", total);
                exit(1);
            default:
            // displays this message when choice is out of range
                printf("Sorry that is not a valid choice. Try it again!\n\n");
        }


    }

    return 0;
}
