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


char *capitalize(char *new, const char *line) {
    strcpy(new, line);
    if (*new >= _ASCII_LOWER_MIN && *new <= _ASCII_LOWER_MAX)
        *new = *new - _ASCII_LOWER_MIN + _ASCII_UPPER_MIN;
    return new;
}


char *expandtabs(char *new, const char *line, int tabsize) {
    char *start = new;
    int count;

    while (*line) {
        if (*line == '\t')
            for (count = 0; count < tabsize; count++)
                *new++ = ' ';
        else
            *new++ = *line;
        line++;
    }

    *new = '\0';
    return start;
}


int find(const char *str, const char *sub) {
    const char *start_str = str;
    const char *start_sub = sub;
    int index = -1;

    while (*str) {
        if (*str == *sub) {
            index = index < 0 ? str - start_str : index;
            sub++;
        } else {
            index = -1;
            sub = start_sub;
        }

        if (!*sub)
            return index;

        str++;
    }

    return *sub ? -1 : index;
}


int rfind(const char *str, const char *sub) {
    int str_index = strlen(str) - 1;
    int sub_index = strlen(sub) - 1;
    int index = -1;

    while (str_index >= 0) {
        if (*(str + str_index) == *(sub + sub_index)) {
            index = str_index;
            sub_index--;
        } else {
            index = -1;
            sub_index = strlen(sub) - 1;
        }

        if (sub_index < 0) {
            return index;
        }

        str_index--;
    }

    return sub_index < 0 ? index : -1;
}
