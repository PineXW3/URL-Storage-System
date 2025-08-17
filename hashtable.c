//
// Created by Xiangtao Wu on 2025/8/12.
//

#include "hashtable.h"
#include <stdlib.h>
#include <string.h>

//Create and Destory functions
Hashtable * create_hashtable(int capacity) {
    if (capacity <= 0) return NULL; //safety check

    //Allocate hashtable and check if it successfully allocated
    Hashtable *hashtable = (Hashtable *) malloc(sizeof(Hashtable));
    if (hashtable == NULL) return NULL;

    //Initialize members
    hashtable->capacity = capacity;
    hashtable->size = 0;

    //Allocate table and check if it successfully allocated
    hashtable->table = (Item_List **) malloc(sizeof(Item_List *) * capacity);
    if (hashtable->table == NULL) {
        free(hashtable);
        return NULL;
    }

    //Initialize table's elements with NULL
    for (int i = 0; i < capacity; i++) {
        hashtable->table[i] = NULL;
    }

    //Successfully create hashtable and return
    return hashtable;
}

void destroy_hashtable(Hashtable *hashtable) {
    if (hashtable == NULL) return; //safety check

    //Free members
    for (int i = 0; i < hashtable->capacity; i++) {
        if (hashtable->table[i] != NULL)
            destroy_list(hashtable->table[i]);
    }
    free(hashtable->table);

    //free hashtable
    free(hashtable);
}

//Operations
void insert_hashtable(Hashtable *hashtable, Item *the_item) {
    if (hashtable == NULL || the_item == NULL || hashtable->size == hashtable->capacity) return;

    int index = hash(hashtable, the_item->key); //Get hash value

    Item_List **table = hashtable->table; //Create table for shorter and cleaner typing

    //If table[index] has no item, create a list
    if (table[index] == NULL) {
        table[index] = create_list();
        if (table[index] == NULL) return;
    }

    //insert the person into the list and return 1 or 0 to indicate result
    hashtable->size += insert_linkedlist(table[index], the_item);
}

Item * search_hashtable(Hashtable *hashtable, char *key) {
    if (hashtable == NULL || key == NULL) return NULL;

    int index = hash(hashtable, key); //Get hash value

    Item_List **table = hashtable->table; //for shorter and cleaner typing
    if (table[index] == NULL) return NULL; //The item does not exist

    return search_linkedlist(table[index], key); //Return the search result
}

void delete_hashtable(Hashtable *hashtable, char *key) {
    if (hashtable == NULL || key == NULL || hashtable->size == 0) return;

    int index = hash(hashtable, key); //Get hash value

    Item_List **table = hashtable->table; //for shorter and cleaner typing
    if (table[index] == NULL) return; //The item does not exist

    hashtable->size -= delete_linkedlist(table[index], key); //Delete the item and return 1 or 0 depends on result
}

unsigned int hash(Hashtable *hashtable, const char *key) {
    if (hashtable == NULL || key == NULL) return 0;

    unsigned int value = 0; //Create value to modify and return

    unsigned int length = strlen(key); //Get length of the key
    for (int i = 0; i < length; i++) {
        value = value * 31 + key[i]; //hashing
    }

    //return value within the size of capacity
    return value % hashtable->capacity;
}