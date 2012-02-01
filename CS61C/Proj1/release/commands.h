#ifndef COMMANDS_H
#define COMMANDS_H

#include <stdbool.h>

// amount of time taken by each command
#define LOOK_TIME            0
#define ATTACK_TIME          15 
#define DAWDLE_DEFAULT_TIME  15
#define HELP_TIME            0
#define INTERACT_TIME        0 
#define MOVE_TIME            120
#define FAILED_MOVE_TIME     15
#define STATUS_TIME          0

// typedefs cmd_fxn_t to be a function pointer of type (int, char**) -> int
// every command function returns the amount of time the command took (if any)
typedef int (*cmd_fxn_t)(int argc, char **argv);

// returns a pointer to the function implementing the command with a given name
cmd_fxn_t lookup_command(char *name);
bool is_player_vulnerable(char *name);

// basic adventure game type commands
int look(int argc, char **argv);
int attack(int argc, char **argv);
int dawdle(int argc, char **argv);
int status(int argc, char **argv);
int quit(int argc, char **argv);
int help(int argc, char **argv);


// plugs into the magic blob to implement puzzles
int interact(int argc, char **argv);

// go moves the player from room to room by updating the_player.current_room
// the argc and argv[] arguments are passed similarly to command-line arguments
// (IMPLEMENT THIS FUNCTION IN commands.c)
int go(int argc, char **argv);

// cast() handles spellcasting
// (IMPLEMENT THIS FUNCTION IN commands.c)
int cast(int argc, char **argv);

// This is some gross macro magic to allow
// for a bunch of convenient synonyms of go
#define MAKE_GO_CMD(dir)                                 \
    static inline int go_##dir (int argc, char**argv) {  \
        char *command_line[] = {                         \
            "go",                                        \
            #dir                                         \
        };                                               \
        return go(2, command_line);                      \
    }
MAKE_GO_CMD(north);
MAKE_GO_CMD(south);
MAKE_GO_CMD(east);
MAKE_GO_CMD(west);
MAKE_GO_CMD(up);
MAKE_GO_CMD(down);
#undef MAKE_GO_CMD // using #undef to delete your macros when you're done with them is a great idea

#endif
