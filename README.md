DATA STRUCTURES IN C

General Linked List:

Usage: gcc -o link link.c 
       ./link

Structure of linked list:

info part - an integer which holds the data to be inserted in the linked list.
next pointer - a pointer pointing to the next node in the list.

Functions

INSERTION
1. insert_beg(int) - Take an integer argument and inserts it at the beginning.
2. insert_end(int) - Take an integer argument and inserts it at the beginning.
3. insert_at_loc(int,int) - Takes two integer arguments (1. number to insert 2. location of node) 
4. insert_after_value(int,int) - Takes two integer arguments (1. number to insert 2. location of value after which to insert)

DELETION
1. delete_beg() - Delete the first node of a list
2. delete_end() - Delete the last node of a list
3. delete_node(int) - Delete any particular node in any location
4. delete_value(int) - Detete any particular value from the list
5. delete_dup_vals() - Delete all duplicate values from the list.

REPLACE
1. replace_node(int,int) - Replace a particular node(2nd arg) with the value passed as first argument.

REVERSE
1. reverse() - Reverse the linked list

SORT
1. sortlist() - Sorts the list using bubble sort in ascending order

DISPLAY
1. display() - Display the linked list.

clear() - Clears the screen usin C ANSI escape sequences.
