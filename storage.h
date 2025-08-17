//
// Created by Xiangtao Wu on 2025/8/14.
//

#ifndef STORAGE_OPERATIONS_H
#define STORAGE_OPERATIONS_H

#include "hashtable.h"
#include <stdio.h>

#define MAXIMUM_URL_LENGTH 2000
#define MAXIMUM_NAME_LENGTH 256

//Open Storage
FILE * open_write(const char* filename); //Build storage
FILE * open_read(const char* filename); //Read storage

void save_hashtable(Hashtable *hashtable, const char *file_name); //Store hashtable items to a file
Hashtable * load_hashtable(const char *file_name); //Load items in a file to hashtable

#endif //STORAGE_OPERATIONS_H
