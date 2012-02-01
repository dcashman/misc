#ifndef LEVEL_H
#define LEVEL_H

#include "monsters.h"
#include "commands.h"
#include <stdbool.h>

typedef enum {
    NORTH,
    SOUTH,
    EAST,
    WEST,
    UP,
    DOWN,

    NUM_DIRECTIONS
} direction;

// maps direction enums to human readable direction strings
extern char *direction_names[];

// flips a direction enum (hint: enums start from 0 and increase)
#define flip_direction(original) (original ^ 1)

/* We need this typedef because exit_t contains a room_t*,
 * but the compiler hasn't seen room_t yet. This works
 * because pointers are all the same size, and the
 * compiler doesn't need to know what *kind* of pointer a
 * room_t* is. */
typedef struct room room_t;

// a struct representing an exit
typedef struct {
    room_t *dest;
    bool locked;
} exit_t;

// don't worry about the below struct
// the two functions which bring a puzzle to life!
typedef struct {
    // prints a description of the puzzle
    cmd_fxn_t description_fxn;
    
    // lets the player attempt to solve the puzzle
    cmd_fxn_t interact_fxn;    
} puzzle_t;

// a struct containing all the information which represents a room
struct room {
    int room_id;
    char *description;
    mob_t mob;
    exit_t exits[NUM_DIRECTIONS];
    puzzle_t puzzle;
};


// loads a level config file and returns a pointer to the starting room
// (FINISH IMPLEMENTING THIS FUNCTION IN level.c)
room_t *load_level(char *filename);

#endif
