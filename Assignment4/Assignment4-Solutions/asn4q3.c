

// Use of fixed size types like int32_t or uint32_t are acceptable as long as they are consistent
// with other requirements for signed vs unsigned.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <err.h>
#include <string.h>

#define RAID_COMMANDER_NAME_ARRAY_LENGTH 100
#define RIVER_TOWN_NAME_ARRAY_LENGTH     100

// A structure to store a date and time
typedef struct _datetime {
    uint8_t day;            // Any unsigned integer type is acceptable for these members
    uint8_t month;
    uint16_t year;
    uint8_t hour;
    uint8_t minute;
} DateTime;

// A structure to store sacks of grain plundered in a raid.
typedef struct _plunder {
    uint32_t wheat_sacks;   // Any unsigned integer type larger than 8-bits is acceptable for these members
    uint32_t barley_sacks;
    uint32_t other_sacks;
} Plunder;

// A structure that stores information about a raid.
typedef struct _raid {
    char commander[RAID_COMMANDER_NAME_ARRAY_LENGTH];
    char town[RIVER_TOWN_NAME_ARRAY_LENGTH];
    DateTime date;
    Plunder sacks_plundered;
} Raid;

// A structure that stores information about a ship and its cargo.
typedef struct _ship {
    char *name;             // Holds a string.  Must be dynamically allocated.
    Raid *raids;            // An array of Raid structures.  Must be dynamically allocated.
} Ship;

// This structure will be your main database.
typedef struct _database {
    uint32_t num_ships;         // Any unsigned integer type is acceptable here.
    Ship *ships;                // An array of Ship structures.  Must be dynamically allocated.
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

    // Allocate main database
    ShipDatabase* new_db = (ShipDatabase*)malloc(sizeof(ShipDatabase));
    if( new_db == NULL) { errx(1, "Error allocating memory for database."); }

    // Record the number of ships
    new_db->num_ships = num_ships;

    // Allocate array of ships within the database
    new_db->ships = (Ship*) malloc(sizeof(Ship) * num_ships);
    if( new_db == NULL) { errx(1, "Error allocating memory for ships."); }

    // For each ship, allocate enough space for the ship name and the raids.
    for(size_t i = 0; i < num_ships; i = i + 1) {
        new_db->ships[i].name = strdup(ship_names[i]);
        new_db->ships[i].raids = (Raid*)malloc(sizeof(Raid) * ship_capacities[i]);
    }

    return new_db;  // This is a placeholder to prevent a compiler error.  Replace this with an appropriate statement.
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
    // Free memory associated with each ship.
    for(size_t i = 0; i < db->num_ships; i = i + 1) {
        free(db->ships[i].name);
        free(db->ships[i].raids);
    }

    // Free ships, and then the main database.
    free(db->ships);
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
