#include <iostream>
#include <fstream>
#include <cstring>
#include "groclist.h"
using namespace std;

//------------------------------------------------------------
// Function Name:  insert_item
// Purpose: inserts an item to a linked list
//
// Details: the function inserts a single item into a linked list. If 
// the item is already in the list, then the quantity is added to
// the item's quantity. 
//
// Inputs: head - the grocery linked list
//         quantity - the item's quantity
//         name - the item's name
//    
//------------------------------------------------------------
void insert_item(Grocery_Item_Ptr &head, int quantity, const char name[]) {

    Grocery_Item_Ptr succ = head;
    Grocery_Item_Ptr pred = NULL;
    Grocery_Item_Ptr temp = new Grocery_Item;

    temp->quantity = quantity;
    strcpy(temp->name, name);
    temp->next = NULL;

    while (succ != NULL && strcmp(name, succ->name) > 0) {
        pred = succ;
        succ = succ->next;
    }
    if (succ != NULL && strcmp(name, succ->name) == 0) {
        succ->quantity += quantity;
        delete temp;
    }
    else if (pred == NULL) {
        temp->next = head;
        head = temp;
    }
    else {
        temp->next = succ;
        pred->next = temp;
    }
}

//------------------------------------------------------------
// Function Name:  remove_item
// Purpose: to remove items from a linked list
//
// Details: the function remove a single item from a linked list. 
// If the quantity of an item is less than zero, the item is 
// completely removed from the list. The list remain sorted.
//
// Inputs: head - the grocery linked list
//         quantity - the item's quantity
//         name - the item's name
//    
//------------------------------------------------------------
void remove_item(Grocery_Item_Ptr &head, int quantity, const char name[]) {

    Grocery_Item_Ptr pred = NULL;
    Grocery_Item_Ptr current = head;

    while (current != NULL and strcmp(name, current->name) != 0) {
        pred = current;
        current = current->next;
    }
    if (current != NULL) {
        current->quantity -= quantity;
        if (current->quantity <= 0) {
            if (pred == NULL) {
                head = current->next;
            }
            else {
                pred->next = current->next;
            }
            delete current;
	}
    }
}

//------------------------------------------------------------
// Function Name:  remove_all_items
// Purpose: to remove all items a linked list
//
// Details: the function sets the head node to NULL and deletes 
// all items from the linked list.
//
// Inputs: head - the grocery linked list
//         
//------------------------------------------------------------
void remove_all_items(Grocery_Item_Ptr &head) {
    Grocery_Item_Ptr temp = head;
    head = NULL;
    delete temp;
}

//------------------------------------------------------------
// Function Name:  write_list
// Purpose: writes a sorted grocery list
//
// Details: the function writes a sorted grocery list to an output file.
//
// Inputs: head - the grocery linked list
//         out - the grocery list output file
//    
//------------------------------------------------------------
void write_list(Grocery_Item_Ptr head, ofstream &out) {

    Grocery_Item_Ptr current = head;

    while (current != NULL) {
        out << current->quantity << " " << current->name << endl;
        current = current->next;
    }
}
