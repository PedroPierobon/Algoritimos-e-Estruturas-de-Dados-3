#include "hash_table.h"
#include <math.h>
#include <stdio.h>

// h1(k) = k mod m
int h1 (int k, int m) {
    return (k % m);
}

// h2(k) = ⌊m * (k * 0.9 − ⌊k * 0.9⌋)⌋
int h2 (int k, int m) {
    int res;
    res = (int) floor(m * (k * 0.9 - floor(k * 0.9)));
    return res;
}

void init_hash_table(struct CuckooHashTable* ht) {
    ht->m = TABLE_SIZE;
    for (int i = 0; i < ht->m; i++) {
        ht->T1[i].key = 0;
        ht->T1[i].table = 1;
        ht->T1[i].pos = i;
        ht->T1[i].state = EMPTY;
        ht->T2[i].key = 0;
        ht->T2[i].state = EMPTY;
        ht->T2[i].table = 2;
        ht->T2[i].pos = i;
    }
}

void insert_key(struct CuckooHashTable* ht, int key) {
    if (ht->m == 0) return;
    int pos1 = h1(key, ht->m);
    // Se a posição em T1 é diferente de ocupado
    if (ht->T1[pos1].state != OCCUPIED) {
        ht->T1[pos1].key = key;
        ht->T1[pos1].state = OCCUPIED;
        return;
    }//else if (ht->T1[pos1].key == key) return;
    int pos2 = h2(ht->T1[pos1].key, ht->m);
    int ki = ht->T1[pos1].key;
    //if (ht->T2[pos2].key == key) return;
    ht->T2[pos2].key = ki;
    ht->T2[pos2].state = OCCUPIED;
    ht->T1[pos1].key = key;
}


int search_key(struct CuckooHashTable* ht, int key){
    int pos1, pos2;
    pos1 = h1(key, ht->m);
    pos2 = h2(key, ht->m);
    if(ht->T1[pos1].state == EMPTY) return -1;
    else if (ht->T1[pos1].key == key) return pos1;
    else return pos2;
}

void remove_key(struct CuckooHashTable* ht, int key) {
    int pos1 = h1(key, ht->m);
    int pos2 = h2(key, ht->m);
    if (ht->T2[pos2].key == key) {
        ht->T2[pos2].state = DELETED;
    } else {
        ht->T1[pos1].state = DELETED;
    }
}

void print_hash_teste(struct CuckooHashTable* ht){
    printf("T1:\n");
    for(int i = 0; i < ht->m; i++){
        printf("%d: %d state:%d\n", i, ht->T1[i].key, ht->T1[i].state);
    }

    printf("T2:\n");
    for(int i = 0; i < ht->m; i++){
        printf("%d: %d state:%d\n", i, ht->T2[i].key, ht->T2[i].state);
    }

}

void print_hash(struct CuckooHashTable* ht){
    struct HashSlot v[ht->m * 2 + 1];
    int tam = 0;
    for(int i = 0; i < ht->m; i++){
        if(ht->T1[i].state == OCCUPIED){
            tam++;
            v[tam] = ht->T1[i];
        }
        if (ht->T2[i].state == OCCUPIED){
            tam++;
            v[tam] = ht->T2[i];
        }
    }
    int j;
    struct HashSlot aux;
    for(int i = 2; i <= tam; i++){
        aux = v[i];
        j = i - 1;
        v[0] = aux;
        while(aux.key < v[j].key){
            v[j+1] = v[j];
            j = j - 1;
        }
        v[j+1]= aux;
    }

    for(int i = 1; i < tam + 1; i++){
        printf("%d,T%d,%d\n", v[i].key, v[i].table, v[i].pos);
    }
}