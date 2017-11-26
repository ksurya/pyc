//
// Python string methods implementation in C
//


char *strcopy(char *new, const char *str) {
    char *start = new;
    while ((*new++ = *str++) != '\0');
    return start;
}


int strlength(const char *s) {
    int i = 0;
    while (*s++ != '\0') i++;
    return i;
}


char *capitalize(char *new, const char *line) {
    strcopy(new, line);
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

    while (*sub && *str)
        if (*str++ != *sub++)
            return 0;

    return !*sub;
}


int endswith(const char *str, const char *sub) {
    int i = strlength(str);
    int j = strlength(sub);

    if (!*sub || !*str)
        return 0;

    while (i >= 0 && j >= 0)
        if (*(str + i--) != *(sub + j--))
            return 0;

    return j < 0;
}


int find(const char *str, const char *sub) {
    int pre;

    for (pre = 0; pre < strlength(str); pre++)
        if (startswith(str + pre, sub))
            return pre;

    return -1;
}


int rfind(const char *str, const char *sub) {
    int str_len = strlength(str);
    int sub_len = strlength(sub);
    int pre;

    for (pre = str_len - sub_len; pre >= 0; pre--)
        if (startswith(str + pre, sub))
            return pre;

    return -1;
}


int scount(const char *str, const char *sub) {
    int sub_len = strlength(sub);
    int count = 0;
    int pre;

    for (pre = 0; pre < strlength(str); pre += sub_len)
        count += startswith(str + pre, sub);

    return count;
}


char *ljust(char *jst, const char *str, int width, char fill) {
    char *start = jst;
    int len = strlength(str);
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
    int len = strlength(str);
    int cnt = 0;

    while ((*jst++ = *str++) != '\0');

    if (len >= width)
        return start;

    for (jst--; cnt < width - len; cnt++, *++jst = '\0')
        *jst = fill;

    return start;
}


char *zfill(char *new, const char *str, int width) {
    return ljust(new, str, width, '0');
}


char *replace(char *new, const char *str, const char *old_sub, 
              const char *new_sub,
              int max_replace) {
    int i = 0;
    int pos = 0;
    char *start = new;
    int new_sub_len = strlength(new_sub);
    int old_sub_len = strlength(old_sub);
    
    while (max_replace-- && (pos = find(str, old_sub)) >= 0) {        
        for (i = 0; i < pos; i++)
            *new++ = *(str + i);

        for (i = 0; i < new_sub_len; i++)
            *new++ = *(new_sub + i);
        
        str += pos + old_sub_len;
    }

    while ((*new++ = *str++) != '\0');

    return start;
}


char *lstrip(char *new, const char *str) {
    char *start = new;

    while (*str && (*str == '\t' || *str == '\r' || *str == '\n' || *str == ' '))
        str++;
    while ((*new++ = *str++) != '\0');

    return start;
}


char *rstrip(char *new, const char *str) {
    char *start = new;
    const char *end = str + strlength(str) - 1;

    while (end >= str) {
        if (*end != '\t' && *end != '\r' && *end != '\n' && *end != ' ')
            break;
        end--;
    }

    while (str <= end)
        *new++ = *str++;
    *new = '\0';

    return start;
}


char *strip(char *new, const char *str) {
    return rstrip(new, lstrip(new, str));
}


char *join(char *new, char **str, char sep) {
    char *chr;
    char *start = new;

    while (*str) {
        chr = *str;
        while((*new++ = *chr++) != '\0');
        *(new - 1) = *(str + 1) ? sep : '\0';
        str++;
    }

    return start;
}


int _isalpha(const char *s) {
    if (!*s)
        return 0;
    while (*s) {
        if (!(*s >= 'A' && *s <= 'Z') && !(*s >= 'a' && *s <= 'z'))
            return 0;
        s++;
    }
    return 1;
}


int _isdigit(const char *s) {
    if (!*s)
        return 0;
    while (*s) {
        if (!(*s >= '0' && *s <= '9'))
            return 0;
        s++;
    }
    return 1;
}


int _isalnum(const char *s) {
    if (!*s)
        return 0;
    while (*s) {
        if (!(*s >= '0' && *s <= '9') && 
            !(*s >= 'A' && *s <= 'Z') && 
            !(*s >= 'a' && *s <= 'z'))
            return 0;
        s++;
    }
    return 1;
}


int _islower(const char *s) {
    while (*s) {
        if (*s >= 'A' && *s <= 'Z')
            return 0;
        s++;
    }
    return 1;
}


int _isupper(const char *s) {
    while (*s) {
        if (*s >= 'a' && *s <= 'z')
            return 0;
        s++;
    }
    return 1;
}


int _isspace(const char *s) {
    while (*s) {
        if (*s != '\t' || *s != '\n' || *s != '\r' || *s != ' ')
            return 0;
        s++;
    }
    return 1;
}
