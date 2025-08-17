//
// Created by Xiangtao Wu on 2025/8/12.
//

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Item {
    char *key;
    char *value;
    struct Item *next;
} Item;

typedef struct Item_List {
    struct Item *head;
} Item_List;

//Create and Destroy List
Item_List * create_list(void);
void destroy_list(Item_List *list);

//Operations of Linked List
int insert_linkedlist(Item_List *list, Item *the_item); //Insert items and return 1 or 0 to indicate result
Item * search_linkedlist(Item_List *list, char *key); //Search items and return the Item or NULL
int delete_linkedlist(Item_List *list, char *key); //Delete items and return 1 or 0 to indicate result

//Helper Function
void free_item(Item *item); //Free a single item and its members
Item * create_item(char *key, char *value); //Create an item
char * allocate_string(char *the_string); //Allocate memory for string

#endif //LINKED_LIST_H
