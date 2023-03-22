// Name: David Emmanuel
// Student Number: 11298443
// Couse: cmpt214 section03 Assignment3 
// NSID: Doe869
// Instructor: Tony Kusalik



#include <stdio.h>
#include <err.h>
#include <string.h>
#include <stdlib.h>

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

/**
- this is void function that takes one parameter, which is a character array containing strings to replace 
- underscores with space,using a for loop to iterate through the filename and takes no return 
*/

void underscore_to_space(char under_score[]){
    for(size_t space = 0; space <= strlen(under_score); space++){
        if(under_score[space] == '_'){
            under_score[space] = ' ';
        }
    }
}


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

/*
* this print_menu function, takes two more parameters which are added to the function
* float total param: this prints the total price in dollar and cent ordered so far
* MenuItem menu: this is an array of structures which is use in printing the menu
* size_t m_num: just takes the size_t for the menu number 
*/
void print_menu(float total, MenuItem menu[], size_t m_num) {

    //displays today's menu
    printf("Today's menu\n");
    //uses the for loop to iterate through the menu list and price
    for (size_t i =0; i < m_num; i++){
        printf("%-42s $%-15.2f\n", menu[i].name, menu[i].price);
    }


    // TODO Print out the names and prices of menu items

    printf("\nSo far your order totals $%.2f.\n", total);
    printf("Which item should we add to your order (enter 0 if finished)? ");
}


// TODO Add the read_menu_from_file() function here, as described in the assignment PDF.

// this reads the menu from the file and stores into the array.
int read_menu_from_file(char* filename, MenuItem menu[], int menu_size ){
    FILE *menufile;

    //opens the menu-doe869.txt for reading and error checking
    menufile = fopen(filename, "r");
    if(menufile==NULL){
    perror("menu-doe869.txt");
    errx(1, "Error reading menu from file");
    }
    float item_price;
    char name[MAX_MENU_ITEM_NAME_LENGTH];
    char buffer[MAX_MENU_FILE_LINE_LENGTH];
    int line_num=0;


    while(fgets(buffer, MAX_MENU_FILE_LINE_LENGTH, menufile) != NULL){

        if(line_num<menu_size){
            line_num+=1;

            if(sscanf(buffer, "%s %f", name, &item_price) !=2){
                errx(1, "error reading file");
            }
            //this calls the underscore function
            underscore_to_space(name);

            //this gives the right indexing of the menu for the item_price by minus -1
            menu[line_num-1].price = item_price;
            //this stringcopy copies the string pointed to  
            strcpy(menu[line_num-1].name, name);
        }
    }

    // this shows If fgets () failed and we did not reach the
    // end of the file then this an error .

    if(!feof(menufile)){
        perror("menu-doe869.txt");
        errx(1, " Error reading file .");

    }

    // closes the file
    fclose(menufile);
    
    return line_num;
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
    size_t m_num;
    MenuItem full_item[MAX_MENU_ITEMS];
    
    // TODO Read the menu data from a file into an array of MenuItem structures.
    m_num = read_menu_from_file("menu-doe869.txt", full_item, MAX_MENU_ITEMS);


    // Print greeting.  TODO: add the name of your restaurant to the greeting :)
    printf("Welcome To Dhey's Chicken Sandwich Resturant\n");

    // Print the menu and get the user's first choice.
    // TODO: call print_menu() to print the menu here
    print_menu(total, full_item, m_num);
    choice = get_menu_choice();

    // As long as the user didn't quit... (if their first choice is 0, the program will end with nothing ordered.)
    while (choice != 0) {
        // TODO: Examine their menu choice.  If it is a valid choice, add the correct dollar amount to the total
        //       (you'll need to access the data in the menu array to do this).  Otherwise, print an error message.
        //       Do not use a switch() statement here!  You don't need to!

        //this checks if the choice entered by the user exceeds the number of menu items and displays the error message
        if (choice > m_num){
            printf("Invalid choice. Please try it again!\n\n");
        }
        total += full_item[choice-1].price;
        
        // Ask for a new choice.  Note that if the user enters 0, the while loop will terminate and
        // the program will end.
        // TODO: call print_menu() to print the menu here
        print_menu(total, full_item, m_num);
        choice = get_menu_choice();
    

    }

    // Summarize how much lighter the user's wallet will be.
    printf("Your order grand total is now $%.2f. Have a great day!\n", total);



    return 0;
}
