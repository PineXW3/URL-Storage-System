//
// Created by Xiangtao Wu on 2025/8/12.
//

#include "linked_list.h"

#include <stdlib.h>
#include <string.h>


//Create and Destroy functions
Item_List * create_list(void) {
    //Allocating memory
    Item_List *list = (Item_List *)malloc(sizeof(Item_List));
    if (list == NULL) return NULL;

    //Initializing member
    list->head = NULL;

    //Return
    return list;
}

void destroy_list(Item_List *list) {
    if (list == NULL) return; //Check if list is valid

    //Create pointers for traversing
    Item *prev = NULL;
    Item *curr = list->head;

    //Traversing the list and free the previous item
    while (curr != NULL) {
        prev = curr;
        curr = curr->next;
        free_item(prev);
    }

    //Free the list at the end
    free(list);
}

//Operations
int insert_linkedlist(Item_List *list, Item *the_item) {
    if (list == NULL || the_item == NULL) return 0; //safety check

    //If list is empty
    if (list->head == NULL) {
        list->head = the_item;
        return 1; //Successfully inserted
    }

    //Traverse to the end of the list
    Item *head = list->head;
    while (head->next != NULL) {
        head = head->next;
    }

    //Link the item to the end of the list
    head->next = the_item;
    return 1; //Successfully inserted
}

Item * search_linkedlist(Item_List *list, char *key) {
    if (list == NULL || key == NULL) return NULL; //safety check

    //Traverse the list to the end and return the item if exist
    Item *head = list->head;
    while (head != NULL) {
        if (strcmp(key, head->key) == 0) return head;
        head = head->next;
    }

    //The item does not exist in the list
    return NULL;
}

int delete_linkedlist(Item_List *list, char *key) {
    if (list == NULL || key == NULL) return 0; //safety check

    //Create pointers for traversing purpose
    Item *prev = NULL;
    Item *curr = list->head;


    //Traverse the list and delete the person if found
    while (curr != NULL) {
        if (strcmp(key, curr->key) == 0) {
            if (prev == NULL) //if item at head
                list->head = curr->next;
            else //else prev is not null
                prev->next = curr->next;

            free_item(curr);
            return 1; //Successfully delete it
        }

        //Move a step forward
        prev = curr;
        curr = curr->next;
    }

    return 0; //Did not delete
}

//Helper Functions
void free_item(Item *item) {
    if (item == NULL) return; //safety check

    //free members
    free(item->key);
    free(item->value);

    //free the person
    free(item);
}

Item * create_item(char *key, char *value) {
    //Allocate memory for item
    Item *item = (Item *)malloc(sizeof(Item));
    if (item == NULL) return NULL;

    //Initializing the members
    item->key = allocate_string(key);
    item->value = allocate_string(value);
    item->next = NULL;

    //return the item
    return item;
}

char * allocate_string(char *the_string) {
    if (the_string == NULL) return NULL; //safety check

    //Get the size of the string and allocate memory of the size of the string
    unsigned int length = strlen(the_string) + 1;
    char * return_string = (char *) malloc(sizeof(char) * length);
    if (return_string == NULL) return NULL;

    //Copy the_string value to return_string
    strcpy(return_string, the_string);

    //return the allocated string
    return return_string;
}
