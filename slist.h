/*

Header file for single linked list class library

*/


// add(value)				//Adds a new value to the end of this list.

// clear()					//Removes all elements from this list.

// equals(list)				//Returns true if the two lists contain the same elements in the same order.

//get(index)				//Returns the element at the specified index in this list.

//insert(index, value)		//Inserts the element into this list before the specified index.

//exchg(index1, index2)		//Switches the payload data of specified indexex.

// isEmpty()				//Returns true if this list contains no elements.

// mapAll(fn)				//Calls the specified function on each element of the linkedlist in ascending index order.

// remove(index)			//Removes the element at the specified index from this list.

// set(index, value)		//Replaces the element at the specified index in this list with a new value.

// size()					//Returns the number of elements in this list.

// subList(start, length)	//Returns a new list containing elements from a sub-range of this list.

// toString()				//Converts the list to a printable string representation.

#include "airport.h"

class Node
{
public:
    Node* next;
    Airport *d;
};

using namespace std;

class LinkedList
{
public:
    int length;
    Node* head;

    LinkedList();
    ~LinkedList();
    void add(Airport* data);           //Adds a new value to the end of this list.
    void clear();					//Removes all elements from this list.
    bool equals(LinkedList *list);  //Returns true if the two lists contain the same elements in the same order.
    Node* get(int index);
    void insert(int index, Airport *data);		//Inserts the element into this list before the specified index.
    void set(int index, Airport *value);		//Replaces the element at the specified index in this list with a new value.
    bool isEmpty();				//Returns true if this list contains no elements.
    int size();					//Returns the number of elements in this list.
    void exchg(int index1, int index2);		//Switches the payload data of specified indexex.
    int sum();
    void display();
};
