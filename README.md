# URL Storage System

## Description
This program is a URL storage system that uses hashtable with linked list implementations to store, search, delete, and display URLs associated with user-defined names.
Data is saved to and loaded from a file, so that storage persisted across runs.

## Features
* Insert: able to insert a URL with its given name.
* Search: able to search a URL by the name.
* Delete: able to delete a URL by the name.
* Display all URLs.
* Persistent Storage: data is saved to a file on exit and reloaded on start.
* Hashtable-based with linked list implementation to handle collisions.

## How to use
The program may ask you for the capacity of your storage if the data file does not exist.  
Therefore:
1. Enter the amount of storage you want. (Only if storage file not exist)
2. Watch the options then enter the number of the corresponding option.
3. If you are inserting: enter the name you want for your url, then enter the url.
4. If you do search and delete: enter the name of the corresponding url.
5. Enter the corresponding exit value to exit the program, it will save the data for the next run.

## Caution
* The names and URLs should not contain space: it will cause unexpected behaviors.
* When inserting URLs, please don't give two identical names since search and delete requires unique names.
