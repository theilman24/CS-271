/*
Taylor Heilman
Stack class using linked lists
Stack2.cc
*/


#include "Stack2.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

//==========================================
//			Default Constructor
//==========================================
Stack::Stack ( void )
{
    Link * head = NULL;        
    top = 0;

}

//==========================================
//				Destructor
//==========================================

Stack::~Stack   ( void )
{
    Link * temp = head;
	while( temp != 0 ) {
    	Link* next = temp->next;
    	delete temp;
   		temp = next;
}
	head = 0;
}

//==========================================
//				Push
//==========================================
void        Stack::push    ( int item )
{
	Link * temp;
    temp = new Link;
    temp -> item = item;
    temp -> next = head;
    head = temp;
    top++;
}

//==========================================
//				Pop
//==========================================
int         Stack::pop     ( void )
{
    if ( head == NULL )
    {
        cout << "Error: cannot pop from empty stack\n";
        exit(1);
    }
    
    else
    	{
    
    	Link * temp = head;
   		head = head -> next;
  	  	int x = temp -> item;
  	  	delete temp;
  	  	top--;
  	  	return x;
    	}

    
}

//==========================================
//				Size
//==========================================
int         Stack::size    ( void )
{
    return top;
}


