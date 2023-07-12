// Name: Abiola Raji
//
// Source File:  groc.cpp
//
// Purpose: to read a ingredients and inventory file and write a
// sorted grocery list to an output file.

#include <iostream>
#include <fstream>
#include <cstring>
#include "groclist.h"
using namespace std;

int main() {

    char ingredients[FILE_LENGTH + 1];
    char inventory[FILE_LENGTH + 1];
    char groc_list[FILE_LENGTH + 1];
    ifstream ingredients_file;
    ifstream inventory_file;
    ofstream grocery_file;
    Grocery_Item_Ptr head = NULL;
    
    cout << endl;
    cout << "enter ingredients file name               : ";
    cin >> ingredients;

    ingredients_file.open(ingredients);

    while (ingredients_file.fail()){
	cout << "couldn't open file " << ingredients << endl;
	cout << "enter ingredients file name               : ";
	cin >> ingredients;
	ingredients_file.open(ingredients);
    }

    cout << "enter inventory file name                 : ";
    cin >> inventory;

    inventory_file.open(inventory);

    while (inventory_file.fail()){
	cout << "couldn't open file " << inventory << endl;
	cout << "enter inventory file name                 : ";
	cin >> inventory;
	inventory_file.open(inventory);
    }

    cout << "enter name of grocery list file to create : ";
    cin >> groc_list;

    grocery_file.open(groc_list);

    if (grocery_file.fail())
	cout << "unable to open " << groc_list << " grocery list not saved" << endl;
    else{
	cout << endl;
	cout << "grocery list produced in file '" << groc_list << "'";
	cout << endl << endl;
	
	process_ingredients(ingredients_file, head);
	process_inventory(inventory_file, head);
	write_list(head, grocery_file);
	remove_all_items(head);
    }
    
    ingredients_file.close();
    inventory_file.close();
    grocery_file.close();
    
    return 0;
}

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
void process_ingredients(ifstream &in, Grocery_Item_Ptr &head){

    int quantity;
    char name[MAX_LENGTH + 1];
    bool success = true;
    
    read_input_line(in, quantity, name, success);
    while (success == true){
	insert_item(head, quantity, name);
	read_input_line(in, quantity, name, success);
    }
}

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
void process_inventory(ifstream &in, Grocery_Item_Ptr &head){
    
    int quantity;
    char name[MAX_LENGTH + 1];
    bool success = true;
    
    read_input_line(in, quantity, name, success);
    while (success == true){
	remove_item(head, quantity, name);
	read_input_line(in, quantity, name, success);
    }
}

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
void read_input_line(ifstream &in, int &quantity, char name[], bool &success){
    
    char ws;
    
    in >> quantity;
    in.get(ws);
    in.getline(name, MAX_LENGTH + 1);
    if (in.eof())
	success = false;
}
