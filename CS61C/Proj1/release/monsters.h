#ifndef MONSTERS_H
#define MONSTERS_H

// sets monster rarity, so that on entering any room,
// a monster is generated with probability 1 / MONSTER_RARITY.
#define MONSTER_RARITY 5

// an instance of this struct defines a monster and provides all its numerical attributes.
// the monsters[] array in monsters.c lists instances of this struct that are used as templates
// for creating monsters.
typedef struct {
    char *name;
    char *attack;       // attack name, e.g. "bite"
    unsigned level;     // a monster can only be spawned when its level <= the player's level
    int hp;             // hp stands for "hit points" or "health points"
    unsigned damage;    // damage done when attacking the player
    unsigned exp;       // experience points provided when the player kills the monster
    unsigned frequency; // a value that reflects the relative frequency with which a monster is spawned
    char *description;  // a description of the beast
} monster_t;

typedef struct {
	/*** YOUR MEMBER VARIABLES HERE ***/
} mob_t;

// takes a mob pointer and prints the names of all monsters in the mob
// used for the "look" command
void print_monsters(mob_t *mob);

// takes a mob pointer and returns the number of monsters in the mob
// (IMPLEMENT THIS FUNCTION IN monsters.c)
int num_monsters(mob_t *mob);

// given a mob pointer and a name string, returns the monster pointer
// for the first monster in the mob that matches the given name string,
// or NULL if the name string is not matched in this mob
// (IMPLEMENT THIS FUNCTION IN monsters.c)
monster_t *find_monster(mob_t *mob, char *type);

// takes a mob pointer and adds a randomly generated monster to the mob.
// the random monster generation must generate monsters with relative frequencies
// proportional to the frequencies listed in monsters[] for each type.
// no monster with level greater than the player's current level should be generated.
// (IMPLEMENT THIS FUNCTION IN commands.c)
void spawn_new_monster(mob_t *mob);

// given a mob pointer and a monster pointer, this function adds the monster to the mob.
// the monster can be added at any position in the list.
// (IMPLEMENT THIS FUNCTION IN commands.c)
void append_monster(mob_t *mob, monster_t *monster);

// given a mob and a monster pointer, this function deletes the corresponding monster from the mob.
// all memory associated with that monster and any overhead memory in the mob should be deallocated.
// if the monster pointer does not exist in the mob, the function does nothing.
// (IMPLEMENT THIS FUNCTION IN commands.c)
void delete_monster(mob_t *mob, monster_t *monster);

typedef struct { 
	/*** YOUR MEMBER VARIBLES HERE ***/
} mob_iterator_t;

// given a mob pointer, this function creates and returns a mob iterator object
// (IMPLEMENT THIS FUNCTION IN commands.c)
mob_iterator_t *make_mob_iterator(mob_t *mob); 

// given a mob iterator object, returns the next monster in the iterator
// and changes the iterator's state to advance it to the next monster.
// if the iterator has exhausted the mob, NULL is always returned.
// (IMPLEMENT THIS FUNCTION IN commands.c)
monster_t *next_monster(mob_iterator_t *iter);

// given a mob iterator pointer, this function frees all memory associated with the iterator.
// it does not affect any underlying mob information, so that only the iterator is deleted.
// (IMPLEMENT THIS FUNCTION IN commands.c)
void delete_mob_iterator(mob_iterator_t *iter);

#endif
