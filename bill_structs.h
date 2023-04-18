#include "entry.h"

// Colton Viktoczy
// CS163-009

// The purpose of this file is to contain the stack along with a node
// that containes a dynamically allocated array of billing entries .


struct node
{
	billing_entry * entries; //Dynamically allocated array of billing entries
	node * next;  //next pointer
};

const int MAX = 5;

class stack
{
	public:
		stack(); // Constructor for the stack
		~stack();// destructor for the stack
//		int display_all(node * head); // display all onjects in t he stack
		int display_all();
		int peek(const billing_entry & found_at_top); // peek function to peek at the stack
		int push(billing_entry & to_add);	
		int pop(void); //function to take the top object off the stack

	private:
		node * head;     // head pointer
		int top_index;   // index object
};




