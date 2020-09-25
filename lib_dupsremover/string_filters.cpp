#include "string_filters.h"


void RemoveDups(char* str) {
    if (!str) {
        // just ignore
        return;
    }

    int i = 0;
    int next_idx = 1;
    while (str[i] != '\0') {
        while (str[i] == str[i + 1]) {
            i++;
        }

        str[next_idx] = str[i + 1];
        next_idx++;
        i++;
    }
}