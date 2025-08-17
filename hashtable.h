//
// Created by Xiangtao Wu on 2025/8/12.
//

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "linked_list.h"

typedef struct Hashtable {
    struct Item_List **table;
    int capacity;
    int size;
} Hashtable;

//Create and Destroy Hashtable
Hashtable * create_hashtable(int capacity); //Create an empty hashtable
void destroy_hashtable(Hashtable *hashtable); //Destroy the whole hashtable

//Operations of Hashtable
void insert_hashtable(Hashtable *hashtable, Item *the_item); //Insert item to the hashtable
Item * search_hashtable(Hashtable *hashtable, char *key); //Search item from the hashtable and return
void delete_hashtable(Hashtable *hashtable, char *key); //Delete item from the hashtable

//Hash Function
unsigned int hash(Hashtable *hashtable, const char *key); //Hashing string to hash value
#endif //HASHTABLE_H
