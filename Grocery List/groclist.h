#ifndef GROCLIST
#define GROCLIST

#include <fstream>
using namespace std;

const int FILE_LENGTH = 30;
const int MAX_LENGTH = 50;

typedef struct Grocery_Item *Grocery_Item_Ptr;

struct Grocery_Item {
    int quantity;
    char name[MAX_LENGTH + 1];
    Grocery_Item_Ptr next;
};

void process_ingredients(ifstream &in, Grocery_Item_Ptr &head);
void process_inventory(ifstream &in, Grocery_Item_Ptr &head);
void read_input_line(ifstream &in, int &quantity, char name[], bool &success);
void insert_item(Grocery_Item_Ptr &head, int quantity, const char name[]);
void write_list(Grocery_Item_Ptr head, ofstream &out);
void remove_item(Grocery_Item_Ptr &head, int quantity, const char name[]);
void remove_all_items(Grocery_Item_Ptr &head);

//------------------------------------------------------------
// Function Name: process_ingredients
// Purpose: processes the ingredient file and returns a sorted list
//
// Details: the function reads each line from the ingredients and adds 
// its name and quantity to a linked list in alphabetical order. If 
// the item is already in the list, then the quantity is added to
// the item's quantity. 
//
// Inputs: in - ingredients input file
//         head - the grocery linked list
//    
//------------------------------------------------------------

//------------------------------------------------------------
// Function Name: process_inventory
// Purpose: processes the inventory file and removes items if needed
//
// Details: the function reads each line from the ingredients file and
// and removes items from a linked list. If the quantity of an item is
// less than zero, the item is completely removed from the list. The 
// list remain sorted.
//
// Inputs: in - ingredients input file
//         head - the grocery linked list
//    
//------------------------------------------------------------

//------------------------------------------------------------
// Function Name:  read_input_line
// Purpose: to read an individual line from a file
//
// Details: the function reads a line from either the ingredients
// or inventory file and returns the item quantity, name, and a 
// boolean which returns false if the last line of the file is 
// reached.
//
// Inputs: in - an input file (ingredients or inventory)
//         quantity - the item's quantity
//         name - the item's name
//         success - a boolean which checks for the end of a file
//    
//------------------------------------------------------------

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

#endif