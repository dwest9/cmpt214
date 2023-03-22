#include <stdio.h>
#include <err.h>

#define MAX_MENU_ITEM_NAME_LENGTH 61    // Maximum length of a menu item string plus 1 for a null character.
#define MAX_MENU_ITEMS 20               // Maximum number of items that can be on the menu.
#define MAX_MENU_FILE_LINE_LENGTH 82    // Maximum length of a line of the menu data file, plus 1 for a newline
                                        // plus 1 for a NULL.

// Define the type name MenuItem to be a structure with two members.
typedef struct _menuitem {
    char name[MAX_MENU_ITEM_NAME_LENGTH];   // Stores the string that is the name of the menu item.
    float price;                   // Stores the price of the menu item in dollars and cents.
} MenuItem;


// TODO copy your underscores_to_spaces() function from question 3 and paste it here.

/*
 * Prints the menu and total dollar amount ordered so far to console as well as a
 * prompt to select a new menu item.
 *
 * total: the total price in dollars and cents of items ordered so far.
 * TODO: add documentation on additional parameters that you add.
 *
 * returns: nothing
 */
// TODO Add necessary additional parameter to print_menu as described in the assignment PDF.
void print_menu(float total) {

    // TODO Print out the names and prices of menu items

    printf("\nSo far your order totals $%.2f.\n", total);
    printf("Which item should we add to your order (enter 0 if finished)? ");
}


// TODO Add the read_menu_from_file() function here, as described in the assignment PDF.


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
    unsigned int choice = -1;        // The user's menu choice (initialized to -1 so that the while loop is initially true)
    float total = 0.0;      // Total amount of food ordered so far in dollars.


    // TODO Read the menu data from a file into an array of MenuItem structures.

    // Print greeting.  TODO: add the name of your restaurant to the greeting :)
    printf("Welcome to <The name of your restaurant!>\n");

    // Print the menu and get the user's first choice.
    // TODO: call print_menu() to print the menu here
    choice = get_menu_choice();

    // As long as the user didn't quit... (if their first choice is 0, the program will end with nothing ordered.)
    while (choice != 0) {
        // TODO: Examine their menu choice.  If it is a valid choice, add the correct dollar amount to the total
        //       (you'll need to access the data in the menu array to do this).  Otherwise, print an error message.
        //       Do not use a switch() statement here!  You don't need to!


        // Ask for a new choice.  Note that if the user enters 0, the while loop will terminate and
        // the program will end.
        // TODO: call print_menu() to print the menu here
        choice = get_menu_choice();
    }

    // Summarize how much lighter the user's wallet will be.
    printf("Your order total comes to $%.2f.  Have a nice day!\n", total);

    return 0;
}
