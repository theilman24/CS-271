//==========================================
// Matt Kretchmar
// March 9, 2015
// Stack.h
//==========================================

#include <iostream>
using namespace std;

#ifndef STACK_H
#define STACK_H

#define DEFAULT_CAPACITY 5

class Stack
{
private:
    int top;        // index of top (empty) item
    int capacity;   // size of array for stack
    int *stack;     // dynamically allocated array
                    // to hold stack
public:
                Stack   ( void );
               ~Stack   ( void );
    void        push    ( int item );            
    int         pop     ( void );
    int         size    ( void );
};

#endif



