#include <stdio.h>
#include "pyc/string.h"

int main() {
    char output[20];
    printf("-%s-\n", pyc_string.strip(output, "  hello, world  "));
    return 0;
}
