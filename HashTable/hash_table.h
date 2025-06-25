#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define TABLE_SIZE 11

enum SlotState {
    EMPTY,
    OCCUPIED,
    DELETED
};

struct HashSlot {
    int key;
    enum SlotState state;
    int table;
    int pos;
};

struct CuckooHashTable {
    struct HashSlot T1[TABLE_SIZE];
    struct HashSlot T2[TABLE_SIZE];
    int m;
};

void init_hash_table(struct CuckooHashTable* ht);
void insert_key(struct CuckooHashTable* ht, int key);
void remove_key(struct CuckooHashTable* ht, int key);
void print_hash(struct CuckooHashTable* ht);
void print_hash_teste(struct CuckooHashTable* ht);


#endif
