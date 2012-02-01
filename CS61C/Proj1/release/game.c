#include "common.h"
#include "game.h"
#include "globals.h"

// information about a particular level
typedef struct {
    unsigned  exp;
    const char *spell_name;
    spell_fxn spell;
} level_entry;

// a magic spell
int fireball(int argc, char **argv);

// the amount of exp needed to reach a level
// and the spells gained at each level
// the index into the table corresponds to the level
level_entry level_table[] = {
    {0,   "",         NULL},     // you must keep this entry here to play the game
    {10,  "fireball", fireball}, // you must keep this entry here to play the game
    {25,  "",         NULL},
    {45,  "",         NULL},
    {70,  "",         NULL},
    {100, "",         NULL},
    {135, "",         NULL},
    {175, "",         NULL},
    {220, "",         NULL},
    {270, "",         NULL}
};
unsigned num_levels = sizeof(level_table) / sizeof(level_entry);

// get the corrasponding level for an amount of experience
unsigned get_level(unsigned exp) {
    int i;
    static unsigned num_levels = sizeof(level_table) / sizeof(level_entry);
    for(i = 0; i < num_levels; i++) {
        if(exp < level_table[i].exp) {
            return i;
        }
    }

    return i;
}

// return the level at which a particular spell can be cast
// this spell should never be called 
unsigned get_spell_level(char *name) {
    /*** YOUR CODE HERE ***/
    // this function should not be called if the spell
    // does not exist, so just blow up if we can't find
    // it
    assert(false);
    return 0; // to avoid a compiler error
}

// get the function which implementes the spell with a given name
spell_fxn get_spell(char *name) {
    /*** YOUR CODE HERE ***/
    // A null return value signals that the spell
    // does not exist
    return NULL;
}

// do damage to a monster
void damage(monster_t *target, int damage_amount) {
    target->hp -= damage_amount;

    if(target->hp <= 0) {
        printf("you killed the %s and gained %d experience!\n", target->name, target->exp);
        gain_experience(target->exp);
        delete_monster(&the_player.current_room->mob, target);
    }
}

void gain_experience(int amount) {
    unsigned new_exp = the_player.experience + amount;
    int new_level = get_level(new_exp);

    while(the_player.level < new_level) {
        the_player.level++;
        the_player.max_hp += 10;
        the_player.hp = the_player.max_hp;
        printf("You are now level %d!\n", the_player.level);
    }

    the_player.experience = new_exp;
}

// I love the fire spell. It's so bad.
int fireball(int argc, char **argv) {
    if(argc == 1) {
        printf("Please specify a monster to torch.\n");
        return 0;
    }

    char *target_name;

    if(argc > 2 && !strcmp(argv[1], "at")) {
        target_name = argv[2];
    } else {
        target_name = argv[1];
    }

    // find the monster
    monster_t *target = find_monster(&the_player.current_room->mob, target_name);
    
    // give up if we can't find it
    if(target == NULL) {
        printf("There's no %s here...\n", argv[1]);
        return 0;
    }

    // inflict damage
    int damage_amount = the_player.level * 2;
    printf("A fireball forms at your fingertips. You hurl it across room at the %s, doing %d damage.\n", target->name, damage_amount);
    damage(target, damage_amount);
    return 40;
}


