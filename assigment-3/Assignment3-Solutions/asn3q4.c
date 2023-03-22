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


/*
 * Replace underscores in a string with spaces.
 *
 * str:    pointer to the first character of an character array containing a string.
 * length: the length of the string stored in the array.
 */
void underscores_to_spaces(char* str, size_t length) {
    for(size_t i=0; i < length; i++) {
        if( str[i] == '_' ) {
            str[i] = ' ';
        }
    }
}

/*
 * Prints the menu and total dollar amount ordered so far to console as well as a
 * prompt to select a new menu item.
 *
 * items:     a pointer to the first element of an array of elements of type MenuItem.
 * num_items: the number of menu items stored in the array items.
 *
 * returns: nothing
 */
void print_menu(MenuItem *items, size_t num_items, float total) {

    // Print out the data for each menu item from the items array.
    for(size_t i = 0; i < num_items; i++) {
        printf("%zu. %s - $%.2f\n", i+1, items[i].name, items[i].price);
    }

    printf("\nSo far your order totals $%.2f.\n", total);
    printf("Which item should we add to your order (enter 0 if finished)? ");
}

/*
 * Reads the menu data from a file.
 *
 * filename:  pointer to the first character of a character array containing a string that is
 *            a path to a text file containing the menu data.  The file must contain data for no more
 *            than 'max_items' menu items, but may contain fewer.
 * items:     a pointer to the first element of an array of MenuItem structures
 * max_items: the length of the 'items' array.
 *
 * returns:   the number of menu items actually read and stored in the array.
 */
size_t read_menu_from_file(char* filename, MenuItem *items, size_t max_items) {

    // Attempt to open the given menu data file path for reading.
    FILE *infile = fopen(filename, "r");

    // If there was a problem...
    if(infile == NULL) {
        // ... report on it and terminate.
        perror(filename);
        errx(1, "Failed to open menu data file: %s.", filename);
    }

    // Set up a buffer to store each line of the file read with fgets().
    char buffer[MAX_MENU_FILE_LINE_LENGTH];

    // Keep track of the number of lines read.
    size_t itemcount = 0;

    // As long as we don't read past the end of the file, and have not read more than the maximum number
    // of menu items...
    while(fgets(buffer, MAX_MENU_FILE_LINE_LENGTH, infile) != NULL && itemcount < max_items) {

        // Read another one with error checking.
        if( sscanf(buffer, "%s%f", items[itemcount].name, &(items[itemcount].price)) != 2) {
            errx(1, "Error reading menu items on line %zu of file %s.", itemcount+1, filename);
        }
        underscores_to_spaces(items[itemcount].name, MAX_MENU_ITEM_NAME_LENGTH);
        itemcount = itemcount + 1;
    }

    // If the loop, above, terminated because we exceeded the maximum number of menu items...
    if( itemcount >= max_items ) {
        // Report an error and terminate.
        errx(1, "Data file contained too many menu items.  Maximum number of items is %d.", MAX_MENU_ITEMS);
    }

    // Keep things tidy by closing the input file since we are done with it.
    fclose(infile);

    // Return the *actual* number of menu items read (which may be smaller than max_items).
    return itemcount;
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
    unsigned int choice = -1;        // The user's menu choice (initialized to -1 so that the while loop is initially true)
    float total = 0.0;      // Total amount of food ordered so far in dollars.


    // Read the menu data from a file into an array of MenuItem structures.
    MenuItem menu[MAX_MENU_ITEMS];
    size_t num_menu_items = read_menu_from_file("../Assignment3/menu-fromfile/menu.txt", menu, MAX_MENU_ITEMS);

    // Print greeting.
    printf("Welcome to Aunt Carrie's Seafood Shack\n");

    // Print the menu and get the user's first choice.
    print_menu(menu, num_menu_items, total);
    choice = get_menu_choice();

    // As long as the user didn't quit... (if their first choice is 0, the program will end with nothing ordered.)
    while (choice != 0) {
        // Examine their choice.  If it is a valid choice, add the correct dollar amount to the total.
        // Otherwise, print an error message.

        if( choice > 0 && choice <= num_menu_items) {
            total = total + menu[choice-1].price;
        }
        else {
            printf("Sorry, that's not a valid choice!  Try again.\n\n");
        }

        // Ask for a new choice.  Note that if the user enters 0, the while loop will terminate and
        // the program will end.
        print_menu(menu, num_menu_items, total);
        choice = get_menu_choice();
    }

    // Summarize how much lighter the user's wallet will be.
    printf("Your order total comes to $%.2f.  Have a nice day!\n", total);

    return 0;
}
