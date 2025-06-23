#include "hash_table.h"
#include <math.h>

// h1(k) = k mod m
int h1 (int k, int m) {
    return (k % m);
}

// h2(k) = ⌊m * (k * 0.9 − ⌊k * 0.9⌋)⌋
int h2 (int k, int m) {
    int res;
    res = (int) floor(m * (k * 0.9f - floor(k * 0.9f)));
    return res;
}


