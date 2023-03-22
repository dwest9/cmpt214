

// Use of fixed size types like int32_t or uint32_t are acceptable as long as they are consistent
// with other requirements for signed vs unsigned.

// Headers.  You can add more if you need to.
#include <stdio.h>
#include <stdlib.h>

/*******************************************************************
 * Add other type definitions for your data structure solution here.
 *******************************************************************/



// This structure will be your main database.
typedef struct _database {
    /************************************************
     * Add fields for the overall database here.
     ************************************************/
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

    return NULL;  // This is a placeholder to prevent a compiler error.  Replace this with an appropriate statement.
}

/**
 * Free all memory associated with a zombie database.
 *
 * Parameters:
 *
 * db - a pointer to a zombie database.
 */
void destroy_database(ShipDatabase *db) {
    /************************************************************************
    * Write this function free all dynamically allocated memory associated
    * with the database db.
    *************************************************************************/
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
    destroy_database(db);

    return 0;
}
