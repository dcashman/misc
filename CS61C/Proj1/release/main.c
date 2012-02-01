#include "common.h"
#include "util.h"

char *default_level = "cs61c-world.lvl";

char *usage =
    "usage: %s [LEVEL_FILE]\n"
    "LEVEL_FILE will be loaded if provided, otherwise \"%s\" will be used.\n"
;

void init_player(room_t *starting_room) {
    the_player.current_room  = starting_room;
    the_player.experience    = 0;
    the_player.level         = get_level(the_player.experience);
    the_player.hp            = 10;
    the_player.max_hp        = 10;
}

void tick_world(int elapsed_time, bool player_vulnerable) {
    static int time = 0;
    static int last_attack_time = 0;
    const int attack_period = 15;

    time += elapsed_time;

    while(time - last_attack_time > attack_period) {
        // monsters attack every attack_period seconds
        if(player_vulnerable) {
            monster_t *attacker;
            mob_iterator_t *iter = make_mob_iterator(&the_player.current_room->mob);
            while((attacker = next_monster(iter))) {
                // does monster attack? 75% chance...
                if (rand() % 4 <= 0) {
                    printf("The %s tries to %s you, but misses\n",
                            attacker->name,attacker->attack);   
                    continue;
                }

                printf("The %s %ss you for %d points of damage\n",
                        attacker->name, attacker->attack, attacker->damage);
                the_player.hp -= attacker->damage;
                if(the_player.hp <= 0) {
                    printf("that %s was too much for you. you die.\n", attacker->attack);
                    exit(0);
                }
            }
            delete_mob_iterator(iter);
        }

        last_attack_time += attack_period;
    }

    static int last_spawn_time = 0;
    const int spawn_period = 120;
    while(time - last_spawn_time > spawn_period) {
        if(rand() % MONSTER_RARITY == 0) {
            for(int i = 0; i < NUM_DIRECTIONS; i++) {
                exit_t *exit = (the_player.current_room->exits + i);
                if(exit->dest != NULL && !exit->locked) {
                    spawn_new_monster(&exit->dest->mob);
                }
            }
        }
        last_spawn_time += spawn_period;
    }
}

void print_border(char a, char b, int length) {
    for(int i = 0; i < length; i++)
        putchar(i % 2 == 0 ? a : b);
    putchar('\n');
}

int main(int argc, char **argv) {
    //load level from cmd line arg
    if(argc > 2) {
        printf(usage, argv[0], default_level);
        exit(1);
    }

    char *welcome_message = "Welcome to %s, the CS 61C adventure extravaganza!\n";
    int border_length = strlen(welcome_message) + strlen(argv[0]) - 3;

    print_border('-', '=', border_length);
    printf(welcome_message, argv[0]);
    print_border('-', '=', border_length);

    room_t *initial_room = NULL;
    if(argc == 1) {
        initial_room = load_level(default_level);
        assert(initial_room != NULL);
        for (int i = 0; i < num_rooms; i++) {
            room_array[i].puzzle.description_fxn = get_puzzle_description(i);
            room_array[i].puzzle.interact_fxn = get_puzzle_solver(i);
        }
    } else {
        initial_room = load_level(argv[1]); // returns a room array or null         
    }

    assert(initial_room != NULL);

    init_player(initial_room);
    
    printf("You wake up.\n");
    
    look(0, NULL);

    // Read-eval-print loop
    for(;;) {
        char buf[256];
        char *words[32];
        int num_words;
        char delimiters[] = " \t\n";
        printf("> "); fflush(stdout);
        fgets(buf, 256, stdin);
        if(feof(stdin)) {
            printf("\n");
            break;
        }

        num_words = tokenizer(buf, words, delimiters);
        char *command_name = words[0];
        if(command_name == NULL) continue;
        
        // try to find a command to do
        cmd_fxn_t cmd_to_do = lookup_command(command_name);
        
        if(cmd_to_do != NULL) {
            // and do it
            int elapsed_time = cmd_to_do(num_words, words);
            tick_world(elapsed_time, is_player_vulnerable(command_name));
        } else {
            printf("Huh?\n");
        }
    }
}

