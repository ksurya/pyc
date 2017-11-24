//
// Python string library implementation in C
//

#include <stdio.h>
#include <string.h>

// globals
const char _ASCII_LOWER_MIN = 'a';
const char _ASCII_LOWER_MAX = 'z';
const char _ASCII_UPPER_MIN = 'A';
const char _ASCII_UPPER_MAX = 'Z';


char *capitalize(const char *word, char *new) {
    strcpy(new, word);
    if (*new >= _ASCII_LOWER_MIN && *new <= _ASCII_LOWER_MAX)
        *new = *new - _ASCII_LOWER_MIN + _ASCII_UPPER_MIN;
    return new;
}
