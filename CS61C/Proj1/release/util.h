#ifndef UTIL_H
#define UTIL_H

#include <stdbool.h>

// tests if c is in s
bool member(char c, char *s);
// removes and discards leading characters in stream that are also in skip_list
void skip_characters(FILE *stream, char *skip_list);
// turns a string into an argc, argv implementation by "cutting" at the delimiters specified
int tokenizer(char *string, char **argv, char *delims);

#endif
