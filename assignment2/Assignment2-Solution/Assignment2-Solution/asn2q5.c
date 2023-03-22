#include <stdio.h>
#include <err.h>


/*
 * Prints the menu and total dollar amount ordered to console.
 *
 * total:     the total amount of food ordered so far in dollars.
 *
 * returns: nothing
 */
void print_menu(float total) {
    printf("Today's Menu\n");
    printf("1. Fried Clams - $15.99\n");
    printf("2. Fish & Chips - $9.99\n");
    printf("3. Bacon-wrapped Sea Scallops - $18.99\n");
    printf("4. Bowl of clam chowder - $5.99\n");
    printf("5. Lobster roll - $11.99\n");
    printf("6. Extra tartar sauce - $0.79\n\n");

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
    int choice = -1;        // The user's menu choice (initialized to -1 so that the while loop is initially true)
    float total = 0.0;      // Total amount of food ordered so far in dollars.

    // Print greeting.
    printf("Welcome to Aunt Carrie's Seafood Shack\n");

    // Print the menu and get the user's first choice.
    print_menu(total);
    choice = get_menu_choice();

    // As long as the user didn't quit... (if their first choice is 0, the program will end with nothing ordered.)
    while (choice != 0) {
        // Examine their choice.  If it is a valid choice, add the correct dollar amount to the total.
        // Otherwise, print an error message.
        switch(choice) {
            case 1: total = total + 15.99;
                break;
            case 2: total = total + 9.99;
                break;
            case 3: total = total + 18.99;
                break;
            case 4: total = total + 5.99;
                break;
            case 5: total = total + 11.99;
                break;
            case 6: total = total + 0.79;
                 break;
            default:
                printf("Sorry, that's not a valid choice!  Try again.\n\n");
        }

        // Ask for a new choice.  Note that if the user enters 0, the while loop will terminate and
        // the program will end.
        print_menu(total);
        choice = get_menu_choice();
    }

    // Summarize how much lighter the user's wallet will be.
    printf("Your order total comes to $%.2f.  Have a nice day!\n", total);

    return 0;
}
