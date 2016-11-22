/*
Taylor Heilman
March 5, 2015

project6.cc
Project 6: Stacks With Dynamic Arrays
The goal of this project is to implement 
stack behavior using dynamically allocated arrays.
*/


#include <iostream>
using namespace std;

int main ( void) 
{
	int * list;  		// pointer
	list = new int[5];	// dynamically allocating 5 places
	int capacity = 5;	// initialize capacity of allocated memory
	int length = 0;		// initialize length of array
	int num;
	char letter;		// p,q,s,x 
	while (true)
	{	
		if (length == capacity)  // Array is full
		{ 
			int * tmp = new int [capacity + 5];  //Create a new, larger array
					
			for(int i=0; i < length; i++)
				tmp[i] = list[i];			// copy old array into new, larger array
			
			delete [] list;		// delete old array
			list = tmp;		// change pointer to new array		
			capacity = capacity + 5;   // add 5 to capacity of array
		}
			
	
		
		cin >> letter;   // p, q, s, or x 
		
		//==================================================================
		// Quit
		//==================================================================
		
		if (letter == 'q')  // Quit 
		{
			delete [] list;		// delete the allocated memory
			exit(1);			// quit program
		}
		
		//==================================================================
		// Push
		//==================================================================
			
		else if (letter == 'p')    // Push
		{
			cin >> num;				// value added to array
			list[length] = num;		// set array index to input number
			length  ++;				// size of array increases by 1, move pointer up
		}
		
		
		//==================================================================
		// Pop
		//==================================================================
		
		else if (letter == 'x')		// Pop
		{
			if (length == 0)   	// empty array
			{
				delete [] list;   	// delete the allocated memory
				exit(1);			// quit program
			}	
			cout << list[length-1] << '\n' ;	// print number at top of stack
			length--;							// length of array decreases by 1
		}
		
		
		//==================================================================
		// Size
		//==================================================================
		
		else if (letter == 's')		// Size
		{
			cout << length << endl;   // Print amount of items in array
		}
		
		
		
		//==================================================================
		// For Troubleshooting
		//==================================================================
		
		
		//for (int j=0;j<length;j++)         // Print out the array
		//	cout <<  list[j] << endl;
			
		//cout << "capacity: " << capacity << '\n' ;  //See the size of allocated memory
	}
	
	
	
	return 0;
	}
	
	
	
	
