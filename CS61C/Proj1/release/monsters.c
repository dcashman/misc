#include "monsters.h"
#include "common.h"

// monsters[] maps monster names to their attributes,
// and is used as a template to instantiate monsters.
// this array must be sorted by level (ascending).
// there must be at least one level 1 monster.
monster_t monsters[] = {
    // name     attack   level hp  damage  exp  frequency  description
    {"goblin",  "bite",  1,    2,  1,      4,   1,         "mean spirited goblin"},
    {"donkey",  "kick",  2,    5,  3,      15,  1,         "small brown donkey"},
    {"squirrel","gnaw",  3,    13, 5,      45,  1,         "a grotesque, irradiated squirrel"}
};

// takes a mob pointer and prints the names of all monsters in the mob
// used for the "look" command
void print_monsters(mob_t *mob) {
    monster_t *monster;
    int num_monsters_here = num_monsters(mob);
    mob_iterator_t *iter = make_mob_iterator(mob);

    printf("There %s %d monster%s here:\n",
            num_monsters_here > 1 ? "are" : "is",
            num_monsters(mob),
            num_monsters_here > 1 ? "s" : ""
            );

    while((monster = next_monster(iter))) {
        printf("\ta %s\n", monster->description);
    }

    delete_mob_iterator(iter);
}

// takes a mob pointer and returns the number of monsters in the mob
int num_monsters(mob_t *mob) {
	/*** YOUR CODE HERE ***/
    return 0;
}

// given a mob pointer and a name string, returns the monster pointer
// for the first monster in the mob that matches the given name string,
// or NULL if the name string is not matched in this mob
monster_t *find_monster(mob_t *mob, char *name) {
	/*** YOUR CODE HERE ***/
    return NULL;
}

// takes a mob pointer and adds a randomly generated monster to the mob.
// the random monster generation must generate monsters with relative
// frequencies proportional to the frequencies listed in monsters[] for each
// type. no monster with level greater than the player's current level should
// be generated.
void spawn_new_monster(mob_t *mob) {
	/*** YOUR CODE HERE ***/
}

// given a mob pointer and a monster pointer, this function adds the monster
// to the mob. the monster can be added at any position in the list.
void append_monster(mob_t *mob, monster_t *monster) {
	/*** YOUR CODE HERE ***/
}

// given a mob and a monster pointer, this function deletes the corresponding
// monster from the mob. all memory associated with that monster and any
// overhead memory in the mob should be deallocated. if the monster pointer
// does not exist in the mob, the function does nothing.
void delete_monster(mob_t *mob, monster_t *monster) {
	/*** YOUR CODE HERE ***/
}

// this function creates and returns a mob iterator object from a mob pointer
mob_iterator_t *make_mob_iterator(mob_t *mob) {
	/*** YOUR CODE HERE ***/
    return NULL;
}

// given a mob iterator object, returns the next monster in the iterator
// and changes the iterator's state to advance it to the next monster.
// if the iterator has exhausted the mob, NULL is always returned.
monster_t *next_monster(mob_iterator_t *iter) {
	/*** YOUR CODE HERE ***/
    return NULL;
}

// given a mob iterator pointer, this function frees all memory associated with
// the iterator. it does not affect any underlying mob information, so that
// only the iterator is deleted.
void delete_mob_iterator(mob_iterator_t *iter) {
	/*** YOUR CODE HERE ***/
}
