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

void init_hash_table(struct CuckooHashTable* ht) {
    ht->m = TABLE_SIZE;
    for (int i = 0; i < ht->m; i++) {
        ht->T1[i].state = EMPTY;
        ht->T2[i].state = EMPTY;
    }
}

void insert_key(struct CuckooHashTable* ht, int key) {
    if (ht->m == 0) return;
    int pos1 = h1(key, ht->m);
    // Se a posição em T1 é diferente de ocupado
    if (ht->T1[pos1].state != OCCUPIED) {
        ht->T1[pos1].key = key;
        return;
    } else if (ht->T1[pos1].key == key) return;
    int pos2 = h2(key, ht->m);
    int ki = ht->T1[pos1].key;
    if (ht->T2[pos2].key == key) return;
    ht->T2[pos2].key = ki;
    ht->T1[pos1].key = key;
}

void remove_key(struct CuckooHashTable* ht, int key) {

}
