//
// Python string library implementation in C
//

#include <stdio.h>
#include <string.h>


char *capitalize(char *new, const char *line) {
    strcpy(new, line);
    if (*new >= 'a' && *new <= 'z')
        *new = 'A' + *new - 'a';
    return new;
}


char *swapcase(char *new, const char *line) {
    char *start = new;

    while (*line) {
        if (*line >= 'A' &&  *line <= 'Z')
            *new = 'a' + *line - 'A';
        else if (*line >= 'a' && *line <= 'z')
            *new = 'A' + *line - 'a';
        else
            *new = *line;
        new++;
        line++;
    }

    return start;
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


int scount(const char *str, const char *sub) {
    int sub_len = strlen(sub);
    int count = 0;
    int pre;

    for (pre = 0; pre < strlen(str); pre += sub_len)
        count += startswith(str + pre, sub);

    return count;
}


char *ljust(char *jst, const char *str, int width, char fill) {
    char *start = jst;
    int len = strlen(str);
    int cnt;

    if (len >= width) {
        while ((*jst++ = *str++) != '\0');
        return start;
    }

    for (cnt = 0; cnt < width - len; cnt++)
        *(jst + cnt) = fill;

    while ((*(jst++ + cnt) = *str++) != '\0');

    return start;
}


char *rjust(char *jst, const char *str, int width, char fill) {
    char *start = jst;
    int len = strlen(str);
    int cnt = 0;

    while ((*jst++ = *str++) != '\0');

    if (len >= width)
        return start;

    for (jst--; cnt < width - len; cnt++, *++jst = 0)
        *jst = fill;

    return start;
}
