#ifndef GAME_H
#define GAME_H

#include "level.h"

// the struct representing a player
typedef struct {
    room_t *current_room;
    unsigned experience;
    unsigned level;
    int hp;
    int max_hp;
} player_t;

unsigned get_level(unsigned exp);
void damage(monster_t *monster, int amount);
void gain_experience(int amount);

typedef int (*spell_fxn)(int argc, char **argv);

// takes a spell name string and checks level_table[] in game.c
// if a matching spell name string is found, this function returns a function pointer
// to the corresponding spell
spell_fxn get_spell(char *name);

// takes a spell name string and checks level_table[] in game.c
// if a matching spell name string is found, this function returns the level
// of the corersponding spell
unsigned get_spell_level(char *name);

#endif
