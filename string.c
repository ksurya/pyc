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


int startswith(const char *str, const char *sub) {
    if (!*sub || !*str)
        return 0;

    while (*sub)
        if (*str++ != *sub++)
            return 0;
    
    return 1;
}


int find(const char *str, const char *sub) {
    int pre;

    for (pre = 0; pre < strlen(str); pre++)
        if (startswith(str + pre, sub))
            return pre;

    return -1;
}


int rfind(const char *str, const char *sub) {
    int str_len = strlen(str);
    int sub_len = strlen(sub);
    int pre;

    for (pre = str_len - sub_len; pre >= 0; pre--)
        if (startswith(str + pre, sub))
            return pre;

    return -1;
}
