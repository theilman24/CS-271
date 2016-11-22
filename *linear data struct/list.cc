/*
Taylor Heilman
list class using doubly linked lists
list.cc
*/

//#include "list.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

//==========================================
//	Default Constructor
//==========================================
template<class T>
List<T>::List ( void )
{
	head = NULL; 
	tail = NULL;
	size = 0;

}

//==========================================
//	Destructor       
//==========================================
template<class T>
List<T>::~List ( void )
{
	dealloc();
}

//==========================================
//	Copy Constructor
//==========================================
template<class T>
List<T>::List ( const List<T>& source )
{	
	copy(source);
		
}

//==========================================
//	Assignment Operator
//==========================================
template<class T>
List<T> & List<T>:: operator=   (const List<T>& source)
{
	if(this != &source)
	{
		dealloc();
		copy(source);
	}
	
	return *this;
}



 //=========================================
 //	Append
 //=========================================
template<class T>
void List<T>::append  (const T& x)
  {
  	  Node<T> * temp;
  	  temp = new Node<T>;
  	  
  	 if (head == NULL)		// appending to empty list
  	 {
  	 	 head = temp;
  	 	 tail = temp;
  	 	 temp -> item = x;
  	 	 temp -> next = NULL;
  	 	 temp -> prev = NULL;
  	 	 size++;
  	 }
  	 
  	 else				// apending to end of list
  	 {
  	 	tail->next = temp;
  	 	temp->item = x;
  	 	temp->prev = tail;
  	 	temp->next = NULL;
  	 	tail = temp;
  	 	size++;
  	 	
  	 }
 
  }
  
  
  
  
//==========================================
//	Insert
//==========================================
template<class T>
void List<T>::insert   (int index, const T & x)      
{
	Node<T> * temp;
	temp = new Node<T>;

	if (index < 0 or index > size)		//indes out of bounds
	{
		delete temp;
		throw IndexError();

	}
	
	else if (size == 0)			// empty list
	{ 	
		temp->item = x;
		temp->prev = NULL;
		temp->next = NULL;
		head = temp;
		tail = temp;
		size++;
			
	}
	
	else if (index == 0 )			// inserting to first spot
	{ 
		 temp->item = x;
		 temp->prev = NULL;
		 temp->next = head;
		 head->prev = temp;
		 head = temp;
  	 	 size++;
		
	}
	else if (index == size)			// inserting to last spot
	{
		append(x);
	}
	
	else					// inserting in middle
	{
		temp = head;
		
		for(int i=0; i < index; i++) 	
		{
			temp = temp-> next;		
		}
		
		Node<T> * temp2;
		temp2 = new Node<T>;
		temp2->next = temp;
		temp2->prev = temp->prev;
		temp2->item = x;
		temp->prev = temp2;
		temp2->prev->next = temp2;
  	 	size++;
		
	}
	
}



//==========================================
//	String
//==========================================
template<class T>
string	List<T>::str()
 {
 	 
 	 string str = "";
 	 Node<T>*temp = head;
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
 }

//==========================================
//	Index
//==========================================
template<class T>
int List<T>::index  ( const T & x )
 {
 	 
 	 Node<T> * temp = head;
 	 int place = 0;	
 	 
 	 while (temp != NULL and temp->item != x)		
 	 {
 	 	 temp = temp->next;
 	 	 place++;
 	 }
 	 
 	 if (temp == NULL)	// if list is empty or item isn't in list
 	 	 return -1;
 	 else
 	 	 return place;	// return index of the item
 	
}
 

//==========================================
//	Pop
//==========================================
template<class T>
T   List<T>::pop (int index)       
{
	T x;
	int y = size -1;
	
	if ( head == NULL)				//empty list
	{
		throw IndexError();
		
	}
	else if (index == y)			// popping last item
	{
		Node<T> * temp = tail;
		x = tail->item;
		tail = tail->prev;
		tail->next = NULL;
		delete temp;
		size--;
		return x;
		
	}
	
	else if( index == 0)			// popping first item
	{
		Node<T> * temp = head;
		x = head -> item;
		head = head-> next;
		head->prev = NULL;
		delete temp;
		size--;
		return x;
	}

	
	else if(index > 0 and index < y)	// poppoing from middle of list
	{
		Node<T> * temp = head;
		for(int i=0; i<index; i++)
		{
			 temp = temp->next;
		}
		x = temp->item;
		(temp->prev)->next = temp->next;
		(temp->next)->prev = temp->prev;
		delete temp;
		size--;
		return x;
		
		
	}
		
	else					// no index given
	{
		Node<T> * temp = tail;
		x = tail->item;
		tail = tail  ->prev;
		tail->next = NULL;
		delete temp;
		size--;
		return x;
		
	}
	
}
 



//==========================================
//	Indexing Operator
//==========================================
template<class T>
T &  List<T>::operator[]  (int index)
{
	if (index < 0 or index > size-1)	//index out of bounds
		throw IndexError();
	else
	{	
		Node<T> * temp = _find(index);	
		return temp->item;
		
	}
}


//==========================================
//	resetForward
//==========================================
template<class T>
void   List<T>::resetForward(void)  
{
	currentFwd = head;
	
}
  
//==========================================
//	next
//==========================================
template<class T>
T    List<T>::next()     
{
	Node<T> * temp = currentFwd;
	if (temp == NULL)
		throw StopIteration();
	else
	{
		T z = currentFwd->item;
		currentFwd = currentFwd->next;
		return z;
	}
}
                                    
//==========================================
//	resetReverse
//==========================================  
template<class T>
void  List<T>::resetReverse(void) 
{
	currentRev = tail;	
}
  
//==========================================
//	prev
//==========================================
template<class T>
T    List<T>::prev  (void)  
{
	Node<T> * temp = currentRev;
	if (temp == NULL)
		throw StopIteration();
	else
	{
		T z = currentRev->item;
		currentRev = currentRev->prev;
		return z;
	}
}
 


//==========================================
//	copy
//==========================================
template<class T>
void  List<T>::copy  (const List<T>& source)
{
	Node<T> *snode, *node;			// deep copy
	
	snode = source.head;
	if (snode)
	{
		node = head = new Node<T>(snode->item);
		snode = snode->next;
	}
	else
		head = NULL;
	while(snode)
	{
		node->next = new Node<T>(snode->item);
		node = node->next;
		snode = snode->next;
	}
	size = source.size;
}




//==========================================
//	dealloc
//==========================================
template<class T>
void   List<T>::dealloc     ()
{
	Node<T> * temp = head;
	
	while( temp != NULL ) 
	{
		head = head->next;
		delete temp;
		temp = head;
	}

	delete temp;
}



//==========================================
//	_find
//==========================================
template<class T>
Node<T>*  List<T>:: _find  (int index)
{
	Node<T> * temp = head;
	for(int i=0; i<index; i++)		
		temp = temp->next;
	
	return temp;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
