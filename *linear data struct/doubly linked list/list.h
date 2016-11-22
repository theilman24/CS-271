//==============================================================================
// Matt Kretchmar
// April 1, 2015
// list.h
//
// This file contains the class definition for a List ADT class.
// ** Do not modify the Node<T> or List classes. **
// ** You will modify the StopIteration class at the bottom **
//
//==============================================================================
// List ADT
//
// The List class implements a sequence of stored items all of the same datatype.
// There are methods to add and remove items from the List, to query the List for
// an item, to index into the list at a specific location, and to iterate through
// the list.
//
// Default Constructor: creates an empty List (no items)
// Copy Constructor:    creates a new List that is an exact copy of an existing List.
// Destructor:          cleans up the memory for an existing List to be deleted.
// Assignment Operator: makes a copy of an existing List for the assigned List.
//
// length():            returns the number of items in the List.
// append(ItemType &x): adds item x to the end of the existing List.  Note that
//                      duplicate items are permitted.
// insert(i,x):         inserts item x at location i in the List.  The existing
//                      items are moved towards the end of the List to make room
//                      for the new item.  Valid values for i are 0 to length().
//                      If length() is the index, this will add the new item to the
//                      end of the list (such as in append).
// pop(i):              removes and returns item at index i from the list.  Valid
//                      values for i are 0 to length()-1.  The argument is optional
//                      will default to removing the last item in the list if i is not given.
// operator[i]:         access (by reference) the item at index i.  Valid values
//                      for i are 0 to length()-1.  The access by reference allows
//                      the user to change the value at this index.
// index(x):            returns the index of the first occurrence of item x in
//                      the List, returns -1 if x is not in the list.
// resetForward():      resets the forward iterator to the front of the list.
// resetReverse():      resets the backward iterator to the end of the list.
// next()               returns the value of the next item in the list using the
//                      forward iterator location.  The forward iterator is then
//                      moved to the next item.
// prev()               returns the value of the next item in the list using the
//                      backward iterator location.  The backward iterator is then
//                      moved to the next (previous) item.
// str()                Converts the List into a string, follows Python format.
//                      Example: "[1, 2, 3]" or "[]"
// cout <<              Overloads the cout << operator for printing. Follows the
//                      same format as in str().
//==============================================================================



#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#ifndef LIST_H
#define LIST_H

template <class T>        // where you can change the type of item stored in the list
struct Node
{
    T   	   item;                                       // data item stored in this link
    Node *      next;                                       // pointer to next link in list
    Node *      prev;                                       // pointer to previous link in list
    
    Node () { next = prev = NULL; }                         // default constructor
    Node (const T & x) { next = prev = NULL;         // constructor with item
                                item = x; }
};

template <class T>   
class List
{
  public:
    List();                                                 // default constructor
    List(const List<T>& source);                               // copy constructor
    ~List();                                                // destructor
 
    List<T> &      operator=   (const List<T>& source);           // assignment operator
    int         length      ()    const { return size; }    // return the length of the list
    void        append      (const T& x);            // append an item to the end of the list
    void        insert      (int index, const T& x); // insert an item in position index
    T    pop         (int index = -1);               // delete item at position index (or last
                                                            // item if no index given)
    T &  operator[]  (int index);                    // indexing operator
    int         index       ( const T &x );          // return the index of the first occurrence of x
    string      str();					    // return the string representation
 
    void        resetForward(void);                         // reset forward iterator to the head of the list
    T    next();                                     // return the next item in the list and advance
                                                            // forward iterator pointer
    void        resetReverse(void);                         // reset reverse iterator to the tail of the list
    T    prev        (void);                         // return the prev item in the list and advance
                                                            // reverse iterator pointer
 private:
    Node<T>     *head,                                      // head of the linked list
                *tail,                                      // tail of the linked list
                *currentFwd,                                // current pointer for the forward iterator
                *currentRev;                                // current pointer for the reverse iterator
    int         size;                                       // length of the list
                      

    void        copy        (const List<T>& source);           // copy source list to this list
    void        dealloc     ();                             // deallocate the list
    Node<T>*       _find       (int index);                    // return a pointer to the node in position index
    
 
    friend ostream&    operator<<  (ostream& os, const List<T>& l)
    {	
    	/*     	 
 	 string str = "";
 	 Node<T> * temp = head;
 	 char Reason [50];
 	 str += "[";
 	 while (temp != NULL)
 	 {
 	 	 if (temp -> next != NULL)
 	 	 {
 	 	 	 sprintf(Reason,"%d", temp -> item);
 	 	 	 str+= Reason;
 	 	 	 str += ", ";
 	 	 }
 	 	 
 	 	 else
 	 	 	 if(temp -> next == NULL)
 	 	 	 {
 	 	 	 	 sprintf(Reason, "%d", temp -> item);
 	 	 	 	 str+= Reason;
 	 	 	 }
 	 	 	 temp = temp -> next;
 	 }
 	 str += "]";
 	 return str;
 	 */				//Returns error
    }
    
};

//==============================================================================
// IndexError
// This class implements an exception for an indexing error.
//==============================================================================
class IndexError {                                          // index error exception
public:
    IndexError() {};
    ~IndexError() {};
    const char *Reason () const { return "Index out of bounds."; }
};


//==============================================================================
// StopIteration
// This class implements an exception for iterating (forward or backward) beyond
// the start/end of the list.
//==============================================================================
class StopIteration {
public:
	StopIteration() {};
	~StopIteration() {};
	const char *Reason () const { return "Iteration error \n System self destructing in\n 3... \n 2... \n 1...";}

};       // stop iteration exception


#endif
#include "list.cc"

































