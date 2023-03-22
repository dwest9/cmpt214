// Name: David Emmanuel
// Student Number: 11298443
// Couse: cmpt214 section03 Assignment4 
// NSID: Doe869
// Instructor: Tony Kusalik

// Use of fixed size types like int32_t or uint32_t are acceptable as long as they are consistent
// with other requirements for signed vs unsigned.

// Headers.  You can add more if you need to.
#include <stdio.h>
#include <stdlib.h>
#include <err.h>

/*******************************************************************
 * Add other type definitions for your data structure solution here.
 *******************************************************************/

typedef struct _name_date_time {
    char name[100];    // 99 characters for name, plus 1 for a null character.
    char town[100];     // 99 charaters for river town, plus 1 for a null character.
    int day;  //integer not less than 1 and not more than 31
    int month;  //nteger not less than 1 and not more than 12
    int year;   // positive integer
    unsigned int hour;   //non-negative integer not less than 0 and not more than 23
    unsigned int minute;    //non-negative integer not less than 0 and not more than 59
} namedatetime;

typedef struct _plunder {
    unsigned int num_wheat;   //The number of sacks of wheat plundered (non-negative integer)
    unsigned int num_barley;   //The number of sacks of barley plundered (non-negative integer)
    unsigned int num_other;    //The number of sacks of other grains plundered (non-negative integer)
    void *namedatetime;            // date and time of plunder
} plundered;

typedef struct _singleShip {
    char ship_names;      //The name of the ship
    size_t raid_list;      //A list of the raids stored in the ship’s hold
    plundered *raids;   //array of raids
} singleShip;


// This structure will be your main database.
typedef struct _database {
    /************************************************
     * Add fields for the overall database here.
     ************************************************/
     int num_ships;        //number of ships
     singleShip * ships;     //array of ships
} ShipDatabase;

/**
 * Create a new database of ships.
 *
 * Parameters:
 *
 * num_ships -            Number of ships in the database.
 * ship_capacities -      Pointer to first element of an array that holds the number of raids that each ship can
 *                        store in its cargo hold.
 * ship_names -           Pointer to the first element of a pointer array that stores the name of each ship.
 *
 * Returns a pointer to the newly allocated (but *uninitialized*) database.
 */
ShipDatabase* new_database(size_t num_ships, size_t *ship_capacities, char* ship_names[]) {
    /************************************************************************
    * Write this function to allocate space for your database data structure.
    * Remember: you don't have to initialize it with data, just allocate
    * storage.
    *************************************************************************/
    ShipDatabase* data_base = (ShipDatabase*) malloc(sizeof(ShipDatabase));  //allocating memory for database
    data_base->num_ships = num_ships;      //this set the number of ships
    data_base ->ships = (singleShip*) malloc(sizeof(singleShip) * num_ships);  //this allocates the memory for ships
    if(data_base == NULL){
        errx(1, "Did not allocate memory");
    }
    for(size_t i=0; i<num_ships; i++){   // this for each reason allocating memory 
        ship_names[i] = (char*)malloc(sizeof(char)* ship_capacities[i]);
    }
    return data_base;  // This is a placeholder to prevent a compiler error.  Replace this with an appropriate statement.
}

/**
 * Free all memory associated with a zombie database.
 *
 * Parameters:
 *
 * db - a pointer to a zombie database.
 */
void scuttle_database(ShipDatabase *db) {
    /************************************************************************
    * Write this function free all dynamically allocated memory associated
    * with the database db.
    *************************************************************************/
    for(int j = 0;  j< db->num_ships; j++) {    //iterate through the shipdatabase that needs to freed
        free(db->ships[j].raids);
    }
    // frees memory allocated to db
    free(db);
}

int main() {
    const size_t num_ships = 5;
    size_t ship_capacities[5] = {12, 15, 6, 4, 19};
    char *ship_names[] = {
            "The Prairie Onion",
            "The Pirating Plover",
            "The Haskap Hunter",
            "The Scourge of Saskatoon",
            "The Aurora"
    };
    ShipDatabase *db = new_database(num_ships, ship_capacities, ship_names);
    scuttle_database(db);

    return 0;
}
