//
// Python string methods implementation in C
//


/**
    Copy string to a character array

    Arguments
        new: outputpointer to the start of the character array
        str: pointer to the start of the string or char array
    Returns
        new
 */
char *_strcopy(char *new, const char *str) {
    char *start = new;
    while ((*new++ = *str++) != '\0');
    return start;
}


/**
    Computes length of the string. Stops after a NULL pointer is found.

    Arguments
        str: pointer to the start of the string or char array
    Returns
        length
 */
int _strlength(const char *s) {
    int i = 0;
    while (*s++ != '\0') i++;
    return i;
}


/**
    Returns a copy of the string with first char capitalized

    Arguments
        new: output, pointer to the start of the char array
        str: pointer to the start of the string
    Returns
        new
 */
char *_capitalize(char *new, const char *line) {
    _strcopy(new, line);
    if (*new >= 'a' && *new <= 'z')
        *new = 'A' + *new - 'a';
    return new;
}


/**
    Returns a copy of the string inverting lowercase to uppercase and
    vice versa.

    Arguments
        new: output, pointer to the start of the char array
        str: pointer to the start of the string
    Returns
        new
 */
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


/**
    Returns a copy of the string replacing tabs with spaces

    Arguments
        new: output, pointer to the start of the char array
        str: pointer to the start of the string
        tabsize: size of a tab in spaces
    Returns
        new
 */
char *_expandtabs(char *new, const char *str, int tabsize) {
    char *start = new;
    int count;

    while (*str) {
        if (*str == '\t')
            for (count = 0; count < tabsize; count++)
                *new++ = ' ';
        else
            *new++ = *str;
        str++;
    }

    *new = '\0';
    return start;
}


/**
    Returns 1 if str starts with sub, otherwise 0

    Arguments
        str: output, pointer to the start of the char array
        sub: pointer to the start of the string
    Returns
        1 or 0
 */
int _startswith(const char *str, const char *sub) {
    if (!*sub || !*str)
        return 0;

    while (*sub && *str)
        if (*str++ != *sub++)
            return 0;

    return !*sub;
}


/**
    Returns 1 if str ends with sub, otherwise 0

    Arguments
        str: output, pointer to the start of the char array
        sub: pointer to the start of the string
    Returns
        1 or 0
 */
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


/**
    Returns the lowest starting index in str where sub is found.
    Returns -1 if sub is not found in str.

    Arguments
        str: output, pointer to the start of the char array
        sub: pointer to the start of the string
    Returns
        lowest starting index
 */
int _find(const char *str, const char *sub) {
    int pre;

    for (pre = 0; pre < _strlength(str); pre++)
        if (_startswith(str + pre, sub))
            return pre;

    return -1;
}


/**
    Returns the highest starting index in str where sub is found.
    Returns -1 if sub is not found in str.

    Arguments
        str: output, pointer to the start of the char array
        sub: pointer to the start of the string
    Returns
        highest starting index
 */
int _rfind(const char *str, const char *sub) {
    int str_len = _strlength(str);
    int sub_len = _strlength(sub);
    int pre;

    for (pre = str_len - sub_len; pre >= 0; pre--)
        if (_startswith(str + pre, sub))
            return pre;

    return -1;
}


/**
    Returns number of non-overlapping occurrences of sub in str

    Arguments
        str: output, pointer to the start of the char array
        sub: pointer to the start of the string
    Returns
        integer >= 0
 */
int _count(const char *str, const char *sub) {
    int sub_len = _strlength(sub);
    int count = 0;
    int pre;

    for (pre = 0; pre < _strlength(str); pre += sub_len)
        count += _startswith(str + pre, sub);

    return count;
}


/**
    Returns a copy of left justtified str

    Arguments
        jst: output, pointer to the left justified char array
        str: pointer to the start of the string
        width: left justified width
        fill: filling character
    Returns
        jst
 */
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


/**
    Returns a copy of right justtified str

    Arguments
        jst: output, pointer to the right justified char array
        str: pointer to the start of the string
        width: right justified width
        fill: filling character
    Returns
        jst
 */
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


/**
    Returns a copy of left justtified str with zeros.
    str is typically expected to be a char array of numbers.

    Arguments
        jst: output, pointer to the left justified char array
        str: pointer to the start of the string
        width: left justified width
        fill: filling character
    Returns
        jst
 */
char *_zfill(char *new, const char *str, int width) {
    return _ljust(new, str, width, '0');
}


/**
    Returns a copy of str with all non-overlapping occurrences of old_sub
    replaced with new_sub.

    Arguments
        new: output, pointer to the copy of the replaced char array
        str: pointer to the start of the string
        old_sub: pointer to the start of substring to be replaced
        new_sub: pointer to the start of substring to be replaced with
        max_replace: max number of substrings to replace
    Returns
        new
 */
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


/**
    Returns a copy of str with leading whitespace removed

    Arguments
        new: output, pointer to the copy of string
        str: pointer to the start of the string
    Returns
        new
 */
char *_lstrip(char *new, const char *str) {
    char *start = new;

    while (*str && (*str == '\t' || *str == '\r' || *str == '\n' || *str == ' '))
        str++;
    while ((*new++ = *str++) != '\0');

    return start;
}


/**
    Returns a copy of str with tailing whitespace removed

    Arguments
        new: output, pointer to the copy of string
        str: pointer to the start of the string
    Returns
        new
 */
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


/**
    Returns a copy of str with tailing and leading whitespace removed

    Arguments
        new: output, pointer to the copy of string
        str: pointer to the start of the string
    Returns
        new
 */
char *_strip(char *new, const char *str) {
    return _rstrip(new, _lstrip(new, str));
}


/**
    Returns an array which is concatenation of character arrays 
    separated by a character.

    Arguments
        new: output, pointer to the concatenated array
        str: pointer to the char array(s)
        sep: character that seperates two arrays
    Returns
        new
 */
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


char **_split(char **arr, const char *str, const char *sep) {
    int i, j;
    char *next;
    char **start = arr;

    while((i = _find(str, sep)) != -1) {
        next = *arr++;

        for (j = 0; j < i && *str++; j++);

        *next = '\0';
        str++;
    }

    return start;
}


/**
    Returns 1 if all elements in the array are alphabetic and there
    exists at least one element, 0 otherwise.

    Arguments
        str: pointer to the start of the string
    Returns
        1 or 0
 */
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


/**
    Returns 1 if all elements in the array are digits and there
    exists at least one element, 0 otherwise.

    Arguments
        str: pointer to the start of the string
    Returns
        1 or 0
 */
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


/**
    Returns 1 if all elements in the array are alphabetic or digits 
    and there exists at least one element, 0 otherwise.

    Arguments
        str: pointer to the start of the string
    Returns
        1 or 0
 */
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


/**
    Returns 0 if there exists at least one uppercase alphabetic, otherwise 1

    Arguments
        str: pointer to the start of the string
    Returns
        1 or 0
 */
int _islower(const char *s) {
    while (*s) {
        if (*s >= 'A' && *s <= 'Z')
            return 0;
        s++;
    }
    return 1;
}


/**
    Returns 0 if there exists at least one lowercase alphabetic, otherwise 1

    Arguments
        str: pointer to the start of the string
    Returns
        1 or 0
 */
int _isupper(const char *s) {
    while (*s) {
        if (*s >= 'a' && *s <= 'z')
            return 0;
        s++;
    }
    return 1;
}


/**
    Returns 0 if there exists at least one non-whitespace char, otherwise 1

    Arguments
        str: pointer to the start of the string
    Returns
        1 or 0
 */
int _isspace(const char *s) {
    while (*s) {
        if (*s != '\t' || *s != '\n' || *s != '\r' || *s != ' ')
            return 0;
        s++;
    }
    return 1;
}
