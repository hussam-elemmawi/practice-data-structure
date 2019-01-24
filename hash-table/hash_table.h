//
// Created by hussamelemmawi on 25/07/17.
//

#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#ifndef HASH_TABLE_HASH_TABLE_H
#define HASH_TABLE_HASH_TABLE_H

const int kTableSize = 100;
char *kDummy = "<dummy>"; // deleted flag

typedef struct KeyValue {
    char *key;
    char *value;
} key_value;

typedef struct HashTable {
    key_value **data;
    int size;
} hash_table;

// Create a new hash table with size slots
hash_table *create_table(int size);

// Frees memory associated with given hash
void destroy_table(hash_table *table);

// Universal string hashing algorithm
int hash(const char *ket, const int m);

// Outputs the content of the hash table
void print_debug(hash_table *table);

// Returns true if a given KEY exists in the table
bool exists(hash_table *table, const char *key);

// Add the given key and object to hash table. if key exists, update the value.
void add(hash_table *table, const char *key, const key_value *object);

// Returns the value associated with the given key, or NULL if not exists.
char *get(const hash_table *table, const char *key);

// Removes the value associated with key from the table.
void delete(hash_table *table, const char *key);

#endif //HASH_TABLE_HASH_TABLE_H
