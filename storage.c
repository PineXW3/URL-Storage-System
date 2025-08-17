//
// Created by Xiangtao Wu on 2025/8/14.
//

#include "storage.h"
#include "hashtable.h"
#include "linked_list.h"

FILE * open_write(const char* filename) {
    FILE *file = fopen(filename, "w"); //open file
    if (file == NULL) {
        perror("Failed to open"); //safety check
        return NULL;
    }

    return file; //safely return
}

FILE * open_read(const char* filename) {
    FILE *file = fopen(filename, "r"); //open file
    if (file == NULL) {
        perror("Failed to open"); //safety check
        return NULL;
    }

    return file; //safely return
}

void save_hashtable(Hashtable *hashtable, const char *file_name) {
    if (hashtable == NULL || file_name == NULL) return; //safety check

    FILE *storage = open_write(file_name); //Open a file for storing purposes
    if (storage == NULL) return; //Stop if file failed to open

    fprintf(storage, "%d\n", hashtable->capacity); //Write the capacity of the hashtable at the first line

    //Iterate the whole Hashtable
    for (int i = 0; i < hashtable->capacity; i++) {
        Item_List *list = hashtable->table[i];
        if (list != NULL) { //if the table exist item in the current index
            Item *item = list->head;
            while (item != NULL) { //write all items in the list to the file
                fprintf(storage, "%s\n%s\n", item->key, item->value);
                item = item->next;
            }
        }
    }

    fclose(storage); //close file
}

Hashtable * load_hashtable(const char *file_name) {
    if (file_name == NULL) return NULL; //safety check

    FILE *storage = open_read(file_name); //open file in read mode
    if (storage == NULL) return NULL; //stop if failed to open

    int capacity;
    fscanf(storage, "%d", &capacity); //reads the capacity

    Hashtable *hashtable = create_hashtable(capacity); //create hashtable based on the capacity



    char attribute[2][MAXIMUM_URL_LENGTH]; //Array to store name and url

    int i = 0;
    while (fscanf(storage,"%s", attribute[i]) != EOF) { //While the file does not end
        i++;
        if (i == 2) { //Create item when we read both name and url from the file
            Item * item = create_item(attribute[0], attribute[1]);
            if (item != NULL) //If item successfully created
                insert_hashtable(hashtable, item);
            i = 0;
        }
    }

    fclose(storage); //close file
    return hashtable; //return the table
}