#include "commands.h"
#include "common.h"
#include "level.h"
#include "monsters.h"
#include "game.h"

// A name/command pair
typedef struct {
    char *name;
    cmd_fxn_t fxn;
    bool player_vulnerable; // Whether or not monsters can attack the player during this command
} cmd_entry_t;

// commands[] maps command names to command functions
cmd_entry_t commands[] = {
    {"look",   look,     true},
    {"attack", attack,   true},
    {"dawdle", dawdle,   true},
    {"wait",   dawdle,   true},
    {"quit",   quit,     true},
    {"exit",   quit,     true},
    {"status", status,   true},
    {"help",   help,     true},
    {"cast",   cast,     true},

    // TA FUNCTION FOR PUZZLES 
    {"interact",  interact,    false},

    // movement aliases
    {"go",     go,       false},
    {"walk",   go,       false},
    {"move",   go,       false},
    {"north",  go_north, false},
    {"n",      go_north, false},
    {"south",  go_south, false},
    {"s",      go_south, false},
    {"east",   go_east,  false},
    {"e",      go_east,  false},
    {"west",   go_west,  false},
    {"w",      go_west,  false},
    {"up",     go_up,    false},
    {"u",      go_up,    false},
    {"down",   go_down,  false},
    {"d",      go_down,  false},
};

const unsigned int num_commands = sizeof(commands) / sizeof(cmd_entry_t);

// finds the command with the given name string in commands[]
// returns NULL if the command is not found
cmd_fxn_t lookup_command(char *name) {
    for(int i = 0; i < num_commands; i++) {
        if(!strcmp(name, commands[i].name)) {
            return commands[i].fxn;
        }
    }
    return NULL;
}

bool is_player_vulnerable(char *name) {
    for(int i = 0; i < num_commands; i++) {
        if(!strcmp(name, commands[i].name)) {
            return commands[i].player_vulnerable;
        }
    }
    // We have no out-of-bandwidth failure value, so just bail
    assert(false);
    return false; // to avoid a compiler error
}

// prints the player's status
int status(int argc, char **argv) {
    printf("level: %d\n", get_level(the_player.experience));
    printf("exp:   %d\n", the_player.experience);
    printf("hp:    %d/%d\n", the_player.hp, the_player.max_hp);
    i_love_additional_status_its_so_bad();
    return STATUS_TIME;
}

// attacks the first monster of monster type argv[1]
int attack(int argc, char **argv) {
    if(argc == 1) {
        printf("Please specify a monster to attack.\n");
        return 0;
    }

    // find the monster
    monster_t *target = find_monster(&the_player.current_room->mob, argv[1]);
    
    // give up if we can't find it
    if(target == NULL) {
        printf("There's no %s here...\n", argv[1]);
        return 0;
    }

    // inflict damage
    int damage_amount = the_player.level;
    printf("You attack the %s for %d damage...\n", target->name, damage_amount);
    damage(target, damage_amount);
    return ATTACK_TIME;
}

// waits for the specified number of seconds (15 by default)
int dawdle(int argc, char **argv) {
    int amount = argc == 2 ? atoi(argv[1]) : DAWDLE_DEFAULT_TIME;
    printf("You %s for %d seconds...\n", argv[0], amount);
    return amount;
}

// prints out the room description, the exits, and monsters
int look(int argc, char **argv) {
    room_t *r = the_player.current_room;
    printf("%s\n", r->description);

    if(r->puzzle.description_fxn != NULL) {
        r->puzzle.description_fxn(argc, argv);
    }

    int num_exits = 0;
    for(int i = 0; i < NUM_DIRECTIONS; i++) {
        if(r->exits[i].dest != NULL) {
            num_exits++;
        }
    }

    switch(num_exits) {
        case 0:
            break;
        case 1:
            for(int i = 0; i < NUM_DIRECTIONS; i++) {
                if(r->exits[i].dest != NULL) {
                    printf("There is an exit %s%s%s%s.\n", 
                            (i == UP || i == DOWN) ? "" : "to the ",
                            direction_names[i],
                            (i == UP || i == DOWN) ? "wards" : "",
                            r->exits[i].locked ? " (locked)" : "");
                    break;
                }
            }
            break;
        default:
            printf("There are exits");
            int exits_remaining = num_exits;
            int i = 0;
            while(exits_remaining) {
                if(r->exits[i].dest != NULL) {
                    exits_remaining--;
                    printf(" %s%s%s", direction_names[i],
                           r->exits[i].locked ? " (locked)" : "", 
                           exits_remaining == 1 ? " and" :
                           exits_remaining == 0 ? ".\n"   :
                                                   ","
                    );
                }
                if(exits_remaining == 0) break;
                i++;
            }
    }

    if(num_monsters(&r->mob) > 0) {
        print_monsters(&r->mob);
    }

    return LOOK_TIME;
}

// calls the puzzle function for the current room
int interact(int argc, char **argv) {
	if (the_player.current_room->puzzle.interact_fxn != NULL) {
		return the_player.current_room->puzzle.interact_fxn(argc, argv);
	} else {
		printf("There is no puzzle in this room.\n");
        return INTERACT_TIME;
	} 
}


// quit the game
int quit(int argc, char **argv) {
    printf("goodbye!\n");
    exit(0);
}

int help(int argc, char **argv) {
    printf("available commands:\n");
    unsigned int num_commands = sizeof(commands) / sizeof(cmd_entry_t);
    for (int i = 0; i < num_commands; i++) {
        printf("\t%s\n",commands[i].name);   
    }   
    return HELP_TIME;
}


// go moves the player from room to room by updating the_player.current_room
// and returns the amount of time movement has taken
// the argc and argv[] arguments are passed similarly to command-line arguments
// a typical "go" command would be:
//    > go north
// and would be passed in as:
//    argc = 2, argv = {"go", "north"}
int go(int argc, char **argv) {
  /*
   * DAC - Pseudo Code for Go function
   *   - make sure direction is n,s,e,w,u,d
   *   - convert direction to int
   *   - determine if there is an exit
   *   - determine if exit is locked
   *   - update or don't update player_t location 
   */
  direction dir;
  switch(**(argv+1)) {      // try to access first letter of second argument to go
  case 'n':
    dir = NORTH;
    break;
  case 's':
    dir = SOUTH;
    break;
  case 'e':
    dir = EAST;
    break;
  case 'w':
    dir = WEST;
    break;
  case 'u':
    dir = UP;
    break;
  case 'd':
    dir = DOWN;
    break;
  default:
    printf("%s isn't a direction\n", *(argv+1));
    assert(false);
  }
  if(the_player.current_room->exits[dir].dest!=NULL){        //see if there is an exit there
    if(the_player.current_room->exits[dir].locked==true){
      printf("\nOh no!  The exit in that direction is locked!\n");
      assert(look(0, NULL) == 0);
      return FAILED_MOVE_TIME;
    }
    else{
      the_player.current_room=the_player.current_room->exits[dir].dest;   //update current room to room player moves into
      // print the room description
      assert(look(0, NULL) == 0); // we're assuming that look doesn't take any time
      return MOVE_TIME;
    }
  }
  else{
    printf("\nThere is no exit in that direction!\n");
    assert(look(0, NULL) ==0);
    return 0;
  }
}

// cast() handles spellcasting
// uses get_spell() to check level_table[] in game.c for a spell name that matches argv[1] 
// and acquire the corresponding function pointer
// uses get_spell_level() to check that the spell's level is <= the player's level before casting
// this function should return whatver the spell itself returns.
int cast(int argc, char **argv) {
    // for part 3, remove this line
    printf("Cast? There's no such thing as magic...\n");
    return 0;
}
