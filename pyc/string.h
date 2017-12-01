// string library

#ifndef PYC_STRING_H
#define PYC_STRING_H

char * _strcopy (char *, const char *);
char * _swapcase (char *, const char *);
char * _capitalize (char *, const char *);
char * _expandtabs (char *, const char *, int);
char * _ljust (char *, const char *, int, char);
char * _rjust (char *, const char *, int, char);
char * _zfill (char *, const char *, int);
char * _replace (char *, const char *, const char *, const char *, int);
char * _lstrip (char *, const char *);
char * _rstrip (char *, const char *);
char * _strip (char *, const char *);
char * _join (char *, char **, char);

int _startswith (const char *, const char *);
int _endswith (const char *, const char *);
int _find (const char *, const char *);
int _rfind (const char *, const char *);
int _count (const char *, const char *);
int _strlength (const char *);

int _isalpha (const char *);
int _isdigit (const char *);
int _isalnum (const char *);
int _islower (const char *);
int _isupper (const char *);
int _isspace (const char *);


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


// expose string functions through a structure
// to *not* corrupt namespace
const pyc_string_t pyc_string = { 
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

#endif
