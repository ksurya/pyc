//
// Python string methods implementation in C
//


char *_strcopy(char *new, const char *str) {
    char *start = new;
    while ((*new++ = *str++) != '\0');
    return start;
}


int _strlength(const char *s) {
    int i = 0;
    while (*s++ != '\0') i++;
    return i;
}


char *_capitalize(char *new, const char *line) {
    _strcopy(new, line);
    if (*new >= 'a' && *new <= 'z')
        *new = 'A' + *new - 'a';
    return new;
}


char *_swapcase(char *new, const char *line) {
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


char *_expandtabs(char *new, const char *line, int tabsize) {
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


int _startswith(const char *str, const char *sub) {
    if (!*sub || !*str)
        return 0;

    while (*sub && *str)
        if (*str++ != *sub++)
            return 0;

    return !*sub;
}


int _endswith(const char *str, const char *sub) {
    int i = _strlength(str);
    int j = _strlength(sub);

    if (!*sub || !*str)
        return 0;

    while (i >= 0 && j >= 0)
        if (*(str + i--) != *(sub + j--))
            return 0;

    return j < 0;
}


int _find(const char *str, const char *sub) {
    int pre;

    for (pre = 0; pre < _strlength(str); pre++)
        if (_startswith(str + pre, sub))
            return pre;

    return -1;
}


int _rfind(const char *str, const char *sub) {
    int str_len = _strlength(str);
    int sub_len = _strlength(sub);
    int pre;

    for (pre = str_len - sub_len; pre >= 0; pre--)
        if (_startswith(str + pre, sub))
            return pre;

    return -1;
}


int _count(const char *str, const char *sub) {
    int sub_len = _strlength(sub);
    int count = 0;
    int pre;

    for (pre = 0; pre < _strlength(str); pre += sub_len)
        count += _startswith(str + pre, sub);

    return count;
}


char *_ljust(char *jst, const char *str, int width, char fill) {
    char *start = jst;
    int len = _strlength(str);
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


char *_rjust(char *jst, const char *str, int width, char fill) {
    char *start = jst;
    int len = _strlength(str);
    int cnt = 0;

    while ((*jst++ = *str++) != '\0');

    if (len >= width)
        return start;

    for (jst--; cnt < width - len; cnt++, *++jst = '\0')
        *jst = fill;

    return start;
}


char *_zfill(char *new, const char *str, int width) {
    return _ljust(new, str, width, '0');
}


char *_replace(char *new, const char *str, const char *old_sub, 
              const char *new_sub,
              int max_replace) {
    int i = 0;
    int pos = 0;
    char *start = new;
    int new_sub_len = _strlength(new_sub);
    int old_sub_len = _strlength(old_sub);
    
    while (max_replace-- && (pos = _find(str, old_sub)) >= 0) {        
        for (i = 0; i < pos; i++)
            *new++ = *(str + i);

        for (i = 0; i < new_sub_len; i++)
            *new++ = *(new_sub + i);
        
        str += pos + old_sub_len;
    }

    while ((*new++ = *str++) != '\0');

    return start;
}


char *_lstrip(char *new, const char *str) {
    char *start = new;

    while (*str && (*str == '\t' || *str == '\r' || *str == '\n' || *str == ' '))
        str++;
    while ((*new++ = *str++) != '\0');

    return start;
}


char *_rstrip(char *new, const char *str) {
    char *start = new;
    const char *end = str + _strlength(str) - 1;

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


char *_strip(char *new, const char *str) {
    return _rstrip(new, _lstrip(new, str));
}


char *_join(char *new, char **str, char sep) {
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


typedef struct {
    char * (*copy) (char *, const char *);
    char * (*swapcase) (char *, const char *);
    char * (*capitalize) (char *, const char *);
    char * (*expandtabs) (char *, const char *, int);
    char * (*ljust) (char *, const char *, int, char);
    char * (*rjust) (char *, const char *, int, char);
    char * (*zfill) (char *, const char *, int);
    char * (*replace) (char *, const char *, const char *, const char *, int);
    char * (*lstrip) (char *, const char *);
    char * (*rstrip) (char *, const char *);
    char * (*strip) (char *, const char *);
    char * (*join) (char *, char **, char);

    int (*startswith) (const char *, const char *);
    int (*endswith) (const char *, const char *);
    int (*find) (const char *, const char *);
    int (*rfind) (const char *, const char *);
    int (*count) (const char *, const char *);
    int (*length) (const char *);

    int (*isalpha) (const char *);
    int (*isdigit) (const char *);
    int (*isalnum) (const char *);
    int (*islower) (const char *);
    int (*isupper) (const char *);
    int (*isspace) (const char *);

} pyc_string_t;


pyc_string_t string = { 
    _strcopy,
    _swapcase,
    _capitalize,
    _expandtabs,
    _ljust,
    _rjust,
    _zfill,
    _replace,
    _lstrip,
    _rstrip,
    _strip,
    _join,

    _startswith,
    _endswith,
    _find,
    _rfind,
    _count,
    _strlength,

    _isalpha,
    _isdigit,
    _isalnum,
    _islower,
    _isupper,
    _isspace,
};
