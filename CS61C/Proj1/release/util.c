#include <stdio.h>
#include <string.h>

#include "util.h"

// tests if char c appears in string s
bool member(char c, char *s) {
    while (*s != '\0') {
        if (*s++ == c) {
            return true;
        }
    }
    return false;
}

// removes and discards leading characters in stream that are also in skip_list
void skip_characters(FILE *stream, char *skip_list) {
    while(true) {
        char c = getc(stream);
        if(!member(c, skip_list)) {
            ungetc(c, stream);
            return;
        }
    }
}

// turns a string into an argc, argv implementation by "cutting" at the delimiters specified
int tokenizer(char *string, char **argv, char *delims) {
    int num_tokens = 0;

    char *token = strtok(string, delims);
    argv[0] = token;
    for(num_tokens = 1; (token = strtok(NULL, delims)); num_tokens++) {
        argv[num_tokens] = token;
    }

    return num_tokens;
}
