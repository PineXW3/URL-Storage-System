//
// Created by Xiangtao Wu on 2025/8/14.
//

#include "linked_list.h"
#include "hashtable.h"
#include "storage.h"
#include <stdio.h>
#include <string.h>

#define STORAGE_FILE "storageFile.txt"
#define RESULT_FILE "resultFile.txt"

//Operations
void insert(Hashtable *hashtable); //Inserting url
void search(Hashtable *hashtable); //Search url
void delete(Hashtable *hashtable); //Delete url
void display_urls(Hashtable *hashtable); //Display all urls

//Helper functions
void print_menu(void); //Print the options
void print_url(Item *url); //Print the name and url
Item * prompt_url(void); //Prompt user and return item or NULL
void prompt_string(char *str, const int MAX_LENGTH); //Help to prompt string
void trim_enter(char *word); //Delete '\n' in the word
void clear_buffer(); //Clear the remaining inputs

int main(void) {
    Hashtable *hashtable = load_hashtable(STORAGE_FILE); //Load the storage if exist
    if (hashtable == NULL) { //Create a hash table if the storage does not exist
        int capacity;
        printf("Storage not found, create a new storage\n");
        printf("Please give storage capacity: ");
        scanf("%d", &capacity);
        hashtable = create_hashtable(capacity);
    }

    int exit = 5;
    int choice = 0;
    while (choice != exit) {
        print_menu();
        scanf("%d", &choice); //store user choice
        clear_buffer();

        switch (choice) { //Execution based on user choice
            case 1: { //Insert
                insert(hashtable);
                break;
            }
            case 2: { //Search
                search(hashtable);
                break;
            }
            case 3: { //Delete
                delete(hashtable);
                break;
            }
            case 4: { //Display
                display_urls(hashtable);
                break;
            }
            case 5: { //Exit
                printf("Exiting...\n");
                break;
            }
            default: { //Not in the options
                printf("Invalid choice\n");
            }
        }
    }

    save_hashtable(hashtable, STORAGE_FILE); //Save the data
    destroy_hashtable(hashtable);
    return 0;
}

void insert(Hashtable *hashtable) {
    Item *url = prompt_url();
    int size = hashtable->size; //Store table size
    insert_hashtable(hashtable, url);
    if (size != hashtable->size) //Table size changed means insertion succeeded
        printf("Insertion succeeded\n");
    else
        printf("Insertion failed\n");
}

void search(Hashtable *hashtable) {
    char name[MAXIMUM_NAME_LENGTH];

    do { //Ask for a non-empty name
        printf("Enter the name: ");
        prompt_string(name, sizeof(name));
    } while (strcmp(name, "") == 0);

    Item *url = search_hashtable(hashtable, name);
    if (url) //If such name exist, print it's url
        printf("The url found is: %s\n", url->value);
    else
        printf("The url is not found\n");
}

void delete(Hashtable *hashtable) {
    char name[MAXIMUM_NAME_LENGTH];

    do { //Ask for a non-empty name
        printf("Enter the name: ");
        prompt_string(name, sizeof(name));
    } while (strcmp(name, "") == 0);

    int size = hashtable->size; //Store size of the table
    delete_hashtable(hashtable, name);
    if (size != hashtable->size) //Size changed means such name exist and it's deleted from the table
        printf("Deleted successfully\n");
    else
        printf("Deleted failed\n");
}

void display_urls(Hashtable *hashtable) {
    if (hashtable == NULL) return;

    for (int i = 0; i < hashtable->capacity; i++) {
        Item_List *list = hashtable->table[i];
        if (list != NULL) { //If current index exist a list
            Item *head = list->head;
            while (head != NULL) { //Traverse the list and print all its items
                print_url(head);
                head = head->next;
            }
        }
    }
}

void print_menu(void) {
    printf("\n---URL Storage ---\n");
    printf("1. Insert URL\n");
    printf("2. Search an URL by name\n");
    printf("3. Delete an URL by name\n");
    printf("4. Display all URLs\n");
    printf("5. Exit\n");
    printf("Enter your choice : ");
}

void print_url(Item *url) {
    printf("Name: %s\n", url->key);
    printf("url: %s\n", url->value);
}

Item * prompt_url(void) {
    char name[MAXIMUM_NAME_LENGTH];
    char url[MAXIMUM_URL_LENGTH];

    do { //Ask for a non-empty name
        printf("Enter url name : ");
        prompt_string(name, sizeof(name));
    } while (strcmp(name, "") == 0);

    do { //Ask for a non-empty url
        printf("Enter the url : ");
        prompt_string(url, sizeof(url));
    } while (strcmp(url, "") == 0);

    return create_item(name, url); //Return item or NULL
}

void prompt_string(char *str, const int MAX_LENGTH) {
        fgets(str, MAX_LENGTH, stdin);
        trim_enter(str);
}

void trim_enter(char *word) {
    unsigned int length = strlen(word);
    if (length > 0 && word[length - 1] == '\n')
        word[length-1] = '\0';
}

void clear_buffer() {
    int c;
    while ( (c = getchar() != '\n') && c != EOF);
}
