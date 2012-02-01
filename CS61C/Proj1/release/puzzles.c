#include "common.h"
#include "puzzles.h"

#define PUZZ_FAIL_TIME    15
#define PUZZ_SUCCESS_TIME 15

// DATA
int cardkey = 0;
int bytes_taken = 0;
int *empty_pizza_box = NULL;

bool solved_puzzles[] = {
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false
};

// UTIL
int get_int_answer(void) {
    char buf[256];
    while(1) {
        printf("? ");
        fgets(buf,256,stdin);
        char *tmp = buf;
        while(*tmp < '0' && *tmp > '9' && *tmp != '\0') tmp++;
        if(*tmp != '\0') {
            return atoi(tmp);
        } else {
            printf("Please enter a number.\n");
        }
    }
}

int solver_generator(int puzz_id, char *first_print, char *fail_print, char *success_print, char *already_solved_print, int answer, direction to_unlock) {
    if (solved_puzzles[puzz_id] == true) {
        assert(the_player.current_room->exits[to_unlock].locked == false);
        printf("%s\n", already_solved_print);
        return PUZZ_FAIL_TIME;
    }
    assert(the_player.current_room->exits[to_unlock].locked == true);
    printf("%s\n",first_print);
    int response = get_int_answer();
    if (response != answer) {
        printf("%s\n",fail_print);
        return PUZZ_FAIL_TIME;
    } else {
        printf("%s\n",success_print);
        the_player.current_room->exits[to_unlock].locked = false;
        solved_puzzles[puzz_id] = true;
        return PUZZ_SUCCESS_TIME;
    }
}


// PUZZLES

// PUZZLE 0 IS FOR TESTING
int desc0(int argc, char **argv) {
    printf("There is a switch on the wall.\n");
    return 0;
}

int solve0(int argc, char **argv) {
   return solver_generator(
           0,
           "You walk up to the switch. Do you flip it? (1 or 0)",
           "Dude, you fail!",  
           "A metallic clanging sound echoes through the corridors. That means this project is working.",
           "You already pressed this switch.",
           1,
           SOUTH);
}


// Evans puzzle 1
int desc1(int argc, char **argv) {
    if (solved_puzzles[1]) {
        printf("The door to the stairs is open.\n");  
    } else {
        printf("The door to the stairs is shut tight. You see a keypad with something scrawled to the side.\n");
    }
    return 0;
}

int solve1(int argc, char **argv) {
    return solver_generator(
            1,
            "The buttons on the keypad are faintly glowing. The numbers are practically worn off. The writing on the wall is only partially decipherable:\n"
            "\t\"~~~ bits ~~ ind~x 387 days ~~~ ...\n\""
            "What do you press on the keypad?",
            "Nothing happens...",
            "A metallic clang echoes through the room. The door swings open.",
            "The door has already opened. The keypad is dark.",
            9,
            UP);
        
}

// evans puzzle 2
int desc2(int argc, char **argv) {
    if (solved_puzzles[2]) {
   
    } else {
        printf("A large, strange contraption blocks your ascent. Hanging from it is a dumbwaiter with a pile of rocks on it. Each rock has the number 1000 carved into it. A tattered note hangs off the chain.\n");
    }
    return 0;
}

int solve2(int argc, char **argv) {
    return solver_generator(
            2,
            "The note is in the same scrawled handwriting as was next to the keypad:\n"
            "\t\"You must remove the HEX or you will be DEAD minus 5!\"\n"
            "How many stones do you take from the pile?",
            "Nothing happens. You replace the stones.",
            "A sudden tremor causes you to drop the stones. The contraption jerks upwards, flying away into the darkness.",
            "The blocking contraption is gone. Only a few stones are left scattered at your feet.",
            57,
            UP);
}

// evans puzzle 3: last puzzle, lobby
int desc3(int argc, char**argv) {
    if (solved_puzzles[3]) {
        printf("A slow breeze is coming through the double doors.\n");
    } else { 
        printf("The double doors are shut tight. Another keypad flickers on the adjacent wall with more of the familiar handwriting.\n");
    }
    return 0;
}

int solve3(int argc, char **argv) {
    return solver_generator(
            3,
            "\t\"~~~~~ alm~st r~ady ~~ order th~se, th~r~ wi~l be a sign\"\n"
            "X: 11110110  Y: 01011010  Z: 10010001\n"
            "\t0: X<Y<Z    3: Y<Z<X\n"
            "\t1: X<Z<Y    4: Z<X<Y\n"
            "\t2: Y<X<Z    5: Z<Y<X\n"
            "What do you press on the keypad?",
            "Silence...",
            "The doors swing open. You are greeted with misty, cold air.",
            "The doors are open.",
            4,
            EAST);
}

// pimentel puzzle 1: outside
int desc6(int argc, char **argv) {
    if (solved_puzzles[6]) {
        
    } else {
        printf("The computer terminal has some text and a blinking prompt.\n");
    }   
    return 0;
}

int solve6(int argc, char **argv) {
    return solver_generator(
            6,
            "\tFirst-fit ##:\n"
            "\t#---#---###--#---#-----\n"
            "\t 1   2     3  4   5\n"
            "What do you type on the keyboard?",
            "The terminal buzzes and re-prints the screen.",
            "The terminal chimes happily and the doors slide open.",
            "The doors are open.",
            1,
            EAST);
}

// pimentel puzzle 2: lobby
int desc7(int argc, char **argv) {
    if (solved_puzzles[7]) {
        printf("There is a hastily-made blockade blocking your path\n");
    } else {
        printf("The computer terminal has some text and a blinking prompt.\n");
    }   
    return 0;
}

int solve7(int argc, char **argv) {
    return solver_generator(
            7,
            "\tBest-fit ##:\n"
            "\t###-#---###--#---#-----\n"
            "\t 1   2     3  4   5\n"
            "What do you type on the keyboard?",
            "The terminal buzzes and re-prints the screen.",
            "The terminal chimes happily and the blockade slides open.",
            "The doors are open.",
            3,
            DOWN);
}

// pimentel puzzle 3: stairs down in auditorium
int desc8(int argc, char **argv) {
    if (solved_puzzles[8]) {
        printf("There is a hastily-made blockade blocking your path\n");
    } else {
        printf("The computer terminal has some text and a blinking prompt.\n");
    }   
    return 0;
}

int solve8(int argc, char **argv) {
    return solver_generator(
            8,
            "\tNext-fit ##:\n"
            "\t###-#---######---#-----\n"
            "\t 1   2     3  4   5\n"
            "What do you type on the keyboard?",
            "The terminal buzzes and re-prints the screen.",
            "The terminal chimes happily and the blockade slides open.",
            "The doors are open.",
            4,
            DOWN);
}

// pimentel brian harvey room
int desc9(int argc, char **argv) {
    if (solved_puzzles[9]) {
        printf("The man doesn't want to be disturbed.\n");
    } else {
        printf("The man turns to you and says: \n\t\"Oh, hi. I hope no monsters followed you here. This is all Microsoft's fault, you know.\"\n");
    }
    return 0;
}

int solve9(int argc, char **argv) {
    if (solved_puzzles[9]) {
        printf("The man ignores you, favoring his parentheses.\n");
        return 0;
    }
    printf("\t\"Oh, you must not have cardkey access. Unfortunately I only have half my cardkey... well, maybe you could find another half somewhere. Here you go!\"\n");
    printf("He gives you half a cardkey!\n");
    cardkey++;
    solved_puzzles[9] = true;
    return PUZZ_SUCCESS_TIME;
}

// level check room before citris
int desc10(int argc, char **argv) {
    if (the_player.level < 2) {
        printf("Looks like you need to be at least level 2 to cross...\n");
    } else {
        printf("You can easily jump across.\n");
        the_player.current_room->exits[NORTH].locked = false;
    }
    return 0;
}

// first citris puzzle
int desc11(int argc, char **argv) {
    if (solved_puzzles[11]) {
        printf("A rope extends from one of the rafters down to the floor.\n");
    } else {
        printf("One of the rafters has a winch with a rope dangling out of reach. Several black cords snake down from the winch and into an Apple laptop on a nearby crate.\n");
    }
    return 0;
}

int solve11(int argc, char **argv) {
    return solver_generator(
            11,
            "The laptop has a colorful display, but an ugly emacs X11 window is open. It has C code:\n"
            "\tint x, *y, z;\n\tx = 10;\n\tz = 9;\n\ty = &x;\n\tx = z;\n\t(*y)++;\n\tz++;\n\tprintf(\"%d\\n\",x); // what prints?\n"
            "Another terminal window is open with a command prompt. What do you type?",
            "The mouse turns into a colorful, spinning beachball for several minutes.",
            "The lights flicker as the winch switches on and lowers the rope to the ground.",
            "The rope is already down. You can climb up.",
            10,
            UP);
}

// second citris puzzle
int desc13(int argc, char **argv) {
    if (solved_puzzles[13]) {
        printf("The metal printing machine is silent.\n");
    } else {
        printf("In the middle of the room is a large, metal machine which is quickly printing out tickets. Hundreds of the tickets litter the floor. You see a slot in the wall. Above the slot is a printed label:\n\t\"To lower the ladder, solve:\"\n\t\t 1101\n\t\t+____\n\t\t=0010\n");
    }
    return 0;
} 

int solve13(int argc, char **argv) {
    if(solved_puzzles[13]) {
        printf("The machine is off.\n");
        return 0;
    }

    char buf[256];
    int generated = rand() % 16;
    printf("You pick up a ticket that reads \"%x\". Do you (p)ut it in the slot, (t)hrow it away, or (w)alk away?\n", generated); 
    while(1) {
    printf("? ");
    fgets(buf,256,stdin);
    char *tmp = buf;
    while((*tmp == ' ' || *tmp == '\t') && *tmp != '\0') tmp++;
    switch (*tmp) {
        case 'p':
        case 'P':
            if (generated == 0x5) {
                printf("With a clang, a hatch opens above you and a ladder slides down into place. The machine spins down and grows quiet.\n");
                solved_puzzles[13] = true;
                the_player.current_room->exits[UP].locked = false;
                return PUZZ_SUCCESS_TIME;
            } else {
                printf("You hear a crackle as arcs of electricity jump from the floor. You lose 5 hp!");
                the_player.hp -= 5;
                return PUZZ_FAIL_TIME;
            }
            break;
        case 't':
        case 'T':
            printf("You throw away the ticket and pick up another that reads \"%x\". (P)ut it in, (t)hrow away, or (w)alk?\n", generated = rand() % 16);
            break;
        case 'w':
        case 'W':
            printf("You walk away...\n");
            return PUZZ_FAIL_TIME;
        default:
            printf("Please enter either 'put in', 'throw away', or 'walk away'.\n");
    }   
    }
            
}

// top of citris with dan
int desc14(int argc, char **argv) {
    if (solved_puzzles[14]) {
        printf("The man looks too busy playing with his gadgets.\n");
    } else {
        printf("The man turns to you and speaks very quickly: \n\t\"You made it through the puzzles! Hmm... I should make those harder next time. Want to know how much this 8.2 Zebipixel camera cost?\"\n"); 
    }
    return 0;
}

int solve14(int argc, char **argv) {
    if (solved_puzzles[9]) {
        printf("It's hard to get his attention...\n");
        return 0;
    }
    printf("He talks so quickly you have a hard time following:\n\t\"Oh, you want cardkey access? Well, I had to sell half of mine to get more storage space. Zebipixel images take up many Yobibytes, you know. Well, here's the other half for solving the puzzles!\"\n");
    printf("He gives you half a cardkey!\n");
    cardkey++;
    solved_puzzles[9] = true;
    return PUZZ_SUCCESS_TIME;
}



// cardkey check before cory 
int desc15(int argc, char **argv) {
    if (cardkey == 2) {
        printf("You flash your cardkey in front of the reader. It beeps and the door unlocks.\n");
        the_player.current_room->exits[NORTH].locked = false;
    } else {
        printf("Looks like you'll need to get cardkey access...\n");
    }
    return 0;
}

// torches puzzle! first room inside cory!
int desc16(int argc, char **argv) {
    if(solved_puzzles[16]) {
        printf("The torches cast an orange glow through the corridor.\n");
    } else {
        printf("Above the torches is an engraving:\n\t\"There is a lock,\n\twhere is the ke_?\"\n");
    }
    return 0;
}

int solve16(int argc, char **argv) {
    if (solved_puzzles[16]) {
        printf("Better not light any more torches...\n");
        return 0;
    }

    if (get_spell("fireball") == NULL || the_player.level < get_spell_level("fireball")) {
        printf("You need some way to light these torches...\n");
        return PUZZ_FAIL_TIME;
    }


    bool torches[] = {false, false, false, false, false, false, false, false};
    char buf[256];
    while (1) {
        for (int i = 0; i < 8; i++) {
            printf(" %s  ",torches[i] ? "*" : " ");
        }
        printf("\n");
        for (int i = 0; i < 8; i++) {
            printf("%s ",torches[i] ? "***" : "   ");
        }
        printf("\n");
        for(int i = 0; i < 8; i++) {
            printf("\\_/ ");
        }
        printf("\n");
        for (int i = 0; i < 8; i++) {
            printf(" |  ");
        }
        printf("\n");
        for (int i = 0; i < 8; i++) {
            printf("=== ");
        }
        printf("\n");
        for (int i = 0; i < 8; i++) {
            printf(" %d  ",i);
        }
        printf("\n\n"); 
        printf("Which torch do you light with your fireball spell? Or do you (w)alk away?\n");
        printf("? ");
        fgets(buf,256,stdin);
        char *tmp = buf;
        while((*tmp == ' ') || (*tmp == '\t')) tmp++;
        if (*tmp == 'w' || *tmp == 'W') {
            printf("You walk away and the torches snuff out.\n");
            return PUZZ_FAIL_TIME;
        } else if (*tmp >= '0' && *tmp <= '9') {
            int idx = atoi(tmp);
            if (idx < 0 || idx > 8) {
                printf("Enter a valid index.\n");
                continue;
            }
            torches[idx] = true;
            if (
                    torches[0] == false &&
                    torches[1] == true &&
                    torches[2] == true &&
                    torches[3] == true &&
                    torches[4] == true &&
                    torches[5] == false &&
                    torches[6] == false &&
                    torches[7] == true
                ) 
            {
                for (int i = 0; i < 8; i++) {
                    printf(" %s  ",torches[i] ? "*" : " ");
                }
                printf("\n");
                for (int i = 0; i < 8; i++) {
                    printf("%s ",torches[i] ? "***" : "   ");
                }
                printf("\n");
                for(int i = 0; i < 8; i++) {
                    printf("\\_/ ");
                }
                printf("\n");
                for (int i = 0; i < 8; i++) {
                    printf(" |  ");
                }
                printf("\n");
                for (int i = 0; i < 8; i++) {
                    printf("=== ");
                }
                printf("\n");
                for (int i = 0; i < 8; i++) {
                    printf(" %d  ",i);
                }
                printf("\n\n"); 
                
                printf("The elevator doors creak open.\n");
                solved_puzzles[16] = true;
                the_player.current_room->exits[UP].locked = false;
                return PUZZ_SUCCESS_TIME;
            }
        } else {
            printf("Please enter a number or w.\n");
        }
    }
}

// dumbwaiter puzzle!
int desc21(int argc, char **argv) {
    if (solved_puzzles[21]) {
    
    } else {
        printf("Next to the door there is a dumbwaiter built into the wall. On the dumbwaiter is a scrap of paper.\n");
    }       
    return 0;
}

int solve21(int argc, char **argv) {
    if (solved_puzzles[21]) {
        printf("The dumbwaiter has retracted. The door to the stairs is unlocked.\n");
        return PUZZ_FAIL_TIME;
    }

    printf("The scrap of paper has writing:\n\t\"sizeof(struct {int x; char a;});\"\n");

    if (bytes_taken == 0) {
        printf("You don't have anything to put on the dumbwaiter.\n");
        return PUZZ_FAIL_TIME;
    }

    char buf[256];
    while(1) {
        printf("Do you want to put the %d stones on the dumbwaiter?\n",bytes_taken);
        printf("? ");
        fgets(buf,256,stdin);
        char *tmp = buf;
        while(*tmp == ' ' || *tmp == '\t') tmp++;
        switch (*tmp) {
            case 'y':
            case 'Y':
                if (bytes_taken == 8) {
                    printf("With a creak, the dumbwaiter retracts. A loud clang informs you the door has unlocked.\n");
                    the_player.current_room->exits[UP].locked = false;
                    solved_puzzles[21] = true;
                    bytes_taken = 0;
                    return PUZZ_SUCCESS_TIME;
                } else {
                    printf("Nothing happens. You take the stones off the dumbwaiter.\n");
                    return PUZZ_FAIL_TIME;
                }
                break;
            case 'n':
            case 'N':
                printf("You do nothing.\n");
                return PUZZ_FAIL_TIME;
                break;
            default:
                printf("Please answer (y)es or (n)o.\n");
        }
    }
}


// heap room
int desc22(int argc, char **argv) {
    return 0;
}

int solve22(int argc, char **argv) {
    char buf[256];
    while(1) {
        printf("How many stones do you take?\n");
        printf("? ");
        fgets(buf,256,stdin);
        char *tmp = buf;
        while (*tmp == '0' || *tmp == '\t') tmp++;
        if (*tmp < '0' || *tmp > '9') {
            printf("Please enter a number\n");
        } else {
            printf("You take %d stones in your pocket.\n",bytes_taken = atoi(tmp));
            return PUZZ_SUCCESS_TIME;
        }
    }
}

// NIM!
int *board, num_piles;

int indicator(int game[]) {
    int indicator = 0;
    for(int i = 0; i < num_piles; i++) indicator ^= game[i];
    return indicator;
}

bool flat_solver(int game[]) {
    bool win = indicator(game);
    if(win) {
        // It's a win, so print the winning moves
        for(int i = 0; i < num_piles; i++) {
            for(int j = 1; j <= game[i]; j++) {
                game[i] -= j;
                int nimber = indicator(game);
                game[i] += j;
                if(nimber == 0)
                    printf("winning move: remove %d from the %d pile\n", j, game[i]);
            }
        }
    }
    return win;
}

void print_board(void) {
    int max = 0;
    for (int i = 0; i < num_piles; i++) {
        max = (board[i] > max) ? board[i] : max;
    }   
    for (int i = max; i > 0; i--) {
        printf("\t");
        for (int j = 0; j < num_piles; j++) {
            printf(" %c    ", (board[j] >= i) ? '*' : ' ');
        }   
        printf("\n");
    }   
    printf("\t");
    for(int i = 0; i < num_piles; i++) {
        printf("%d:%d%s",i,board[i],(board[i] > 9) ? "  ":"   ");
    }   
    printf("\n");
}

int desc24(int argc, char **argv) {
    num_piles = 3 + (rand() % 5);
    board = malloc(num_piles *sizeof(int));
    for (int i = 0; i < num_piles; i++) {
        board[i] = 1 + (rand() % 4);
    }
    
    printf("There is a hideous, bulbous monster sitting in front of several piles of stones:\n");
    printf("\n");
    print_board();

    return 0;
}

int solve24(int argc, char **argv) {
    printf("The monster howls in a deep voice:\n\t\"You! Shall not! Pass!!\n\tI won't let you leave...\"\n");

    while(1) {
        int num_left = 0;
        for (int i = 0; i < num_piles; i++) {
            num_left += board[i];
        }
        if (num_left == 1) {
            printf("\tNoooooo!\nWith a howl, the monster jumps out the window.\n");
            solved_puzzles[24] = true;
            the_player.current_room->exits[UP].locked = false;
            break;
        } else if (num_left == 0) {
            printf("\tHahaha! I shall make a withdrawal from your health account...\n"
                    "The monster bites you for 10HP!\n");
            the_player.hp -= 10;
            if (the_player.hp <= 0) {
                printf("That last bite was too much for you. You die.\n");
                exit(0);
            }
            break;
        }
        print_board();
        printf("\n");
        printf("What pile do you take from?\n");
        int response = get_int_answer();
        if (response >= num_piles || response < 0) {
            printf("Fool! That pile lies within you!\n"
                    "The monster reaches inside you and takes 10HP\n");
            the_player.hp -= 10;
            if (the_player.hp <= 0) {
                printf("That hideous monster was too much for you. You die.\n");
                exit(0);
            }    
        } else {
            printf("How many do you take?\n");
            int response2 = get_int_answer();
            if (response2 <= 0 || response > board[response]) {
                printf("\tInsolent fool! I will show you what it is like to take too many!\n"
                        "The monster swipes 10HP\n");
                the_player.hp -= 10;
                if (the_player.hp <= 0) {
                    printf("That last swipe was too much for you. You die.\n");
                    exit(0);
                }

            } else {
                board[response] -= response2;
                if (indicator(board)) {
                    // we can win!
                    bool done = false;
                    for(int i = 0; i < num_piles; i++) {
                        for(int j = 1; j <= board[i]; j++) {   
                            board[i] -= j;
                            int nimber = indicator(board);
                            if(nimber == 0) {
                                printf("\tHaha! I like this game...\n");
                                done = true;
                                break;
                            }
                        }
                        if (done == true) break;
                    }
                } else {
                    //We're screwed! move randomly!
                    int idx = 0;
                    while (!board[idx = (rand() % num_piles)]); 
                    board[idx] -= (board[idx] == 1) ? 1 : (1 + (rand() % (board[idx] - 1)));
                    printf("\tHmm... can we start over?\n");
                }                
            }  
        }
    }
    return 0;
}

// matt and casey at top of soda!
int desc25(int argc, char **argv) {
    printf("But what's this?! Casey and Matt are still working on the proj1 spec, and they're about to dereference that empty_pizza_box! Quick, stop them!\n");
    return 0;
}

int solve25(int argc, char **argv) {
    *empty_pizza_box = 42;
    printf("Nice job! Now you're a 61C master!\n");
    printf("The end!\n");
    printf("Credits: Matt and Casey!\n");
    return 0;
}

// MORE DATA
typedef struct {
    cmd_fxn_t desc;
    cmd_fxn_t solve;
} puzzle_entry_t;

// 26 entries
puzzle_entry_t puzzles[] = {
    {NULL, NULL},
    {desc1, solve1},
    {desc2, solve2},
    {desc3, solve3},
    {NULL, NULL},
    {NULL, NULL},
    {desc6, solve6}, 
    {desc7, solve7},
    {desc8, solve8},
    {desc9, solve9},    
    {desc10, NULL},
    {desc11, solve11},
    {NULL, NULL},
    {desc13, solve13},
    {desc14, solve14},
    {desc15, NULL},
    {desc16, solve16},
    {NULL, NULL},
    {NULL, NULL},
    {NULL, NULL},
    {NULL, NULL},
    {desc21, solve21},
    {desc22, solve22},
    {NULL, NULL},
    {desc24, solve24},
    {desc25, solve25}
};

int num_puzzles = sizeof(puzzles) / sizeof(puzzle_entry_t);





// GENERAL
cmd_fxn_t get_puzzle_description(int idx) {
    if (num_rooms != num_puzzles) {
        printf("Corrupted level file for main game.\n");
        assert(false);
    }

    if (idx >= 0 && idx < num_puzzles) {
        return puzzles[idx].desc;
    } else {
        return NULL;
    }

}

cmd_fxn_t get_puzzle_solver(int idx) {
    if (num_rooms != num_puzzles) {
        printf("Corrupted level file for main game.\n");
        assert(false);
    }


    if (idx >= 0 && idx < num_puzzles) {
        return puzzles[idx].solve;
    } else {
        return NULL;
    }


}

void i_love_additional_status_its_so_bad(void) {
    if (cardkey == 1) {
        printf("You also have this strange half-cardkey...\n");
    } else if (cardkey == 2) {
        printf("You have a full cardkey!\n");
    }

    if (bytes_taken != 0) {
        printf("You have %d stones in your pocket.\n",bytes_taken);
    }
}



