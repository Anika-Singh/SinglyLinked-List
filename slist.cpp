#include <iostream>
#include <cstdlib>

#include "slist.h"

/*

Class Library File

*/


// Constructor

// Destructor

// add(value)				//Adds a new value to the end of this list.

// clear()					//Removes all elements from this list.

// equals(list)				//Returns true if the two lists contain the same elements in the same order.

//get(index)				//Returns the element at the specified index in this list.

//insert(index, value)		//Inserts the element into this list before the specified index.

//exchg(index1, index2)		//Switches the payload data of specified indexex.

// isEmpty()				//Returns true if this list contains no elements.

// remove(index)			//Removes the element at the specified index from this list.

// set(index, value)		//Replaces the element at the specified index in this list with a new value.

// size()					//Returns the number of elements in this list.

// subList(start, length)	//Returns a new list containing elements from a sub-range of this list.

using namespace std;

// Initialize the lists management information
LinkedList::LinkedList(){
    this->length = 0; // Your code here
    this->head = NULL;// Your code here
}

// Clear the list management information and release all allocated Nodes
LinkedList::~LinkedList(){
   Node* current = this->head;
    while(current){
        this->head = current->next;
        this->length -= 1;
		delete current;
		current = this->head;
    }
    std::cout << "LIST DELETED: " << this->length << std::endl;
}

// Add a new node that contains 'data'
void LinkedList::add(Airport * data){
     // find the last element
     Node* last = NULL;
     Node *current = this->head;
     while(current){
        last = current;
        current = current->next;
    }
    if ( last != NULL )
    {
      last->next = new Node();
      last->next->d = data;
    }
    else
    {
        this->head = new Node();
        this->head->d = data;
    }
    this->length += 1;
    //cout << this->length << endl;
}

void LinkedList::clear(){
    Node* current = this->head;
    while(current){
        this->head = current->next;
        this->length -= 1;
		delete current;
		current = this->head;
    }

}

bool LinkedList::equals(LinkedList *list){
    if ( list == NULL)
        return false;
    if ( this->length != list->length )
        return false;

    for ( int i=0; i < this->length; i++ )
    {
        Node *a1 = this->get(i);
        Node *a2 = list->get(i);
        if ( a1 != a2)
            return false;
    }
    return true;
}

Node * LinkedList::get(int index){
    //cout << index << endl;
    int i=0;
    Node *x = head;
    while(x){
        if ( i == index)
          return x;
        x = x->next;
        i++;
    }
    return NULL;
}

void LinkedList::insert(int index, Airport *data)
{
    Node *n = new Node();
    n->d = data;

    if ( index == 0) // if trying to add in the beginning
    {
        n->next = this->head;
        this->head = n;
        this->length += 1;
    }
    else if ( index > this->length -1 ) // then add in the end
    {
        Node *a = this->get(this->length-1);
        a->next = n;
        this->length += 1;
    }
    else
    {
        Node *a = this->get(index-1);
        Node *temp = a->next;
        a->next = n;
        n->next = temp;
        this->length += 1;
    }

}

void LinkedList::set(int index, Airport *value)
{
    Node *n = this->get(index);
    n->d = value;

}

bool LinkedList::isEmpty(){
    if ( this->head == NULL)
        return false;

    return true;
}

int LinkedList::size(){
    return this->length;
}

void LinkedList::exchg(int index1, int index2)
{
    Node *n1 = this->get(index1);
    Node *n2 = this->get(index2);

    Airport *tmp = n1->d;
    n1->d = n2->d;
    n2->d = tmp;
}


void LinkedList::display()
{
     for (int c=0; c < this->length; c++)
     {
        Node *n = this->get(c);
        if ( n != NULL )
           cout <<"Airport: " << ((Airport *)(n->d))->code << " Distance: " << ((Airport *)(n->d))->distance << endl;
     }
}

