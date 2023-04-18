#include "bill_structs.h"

//Colton Vitkoczy
//CS 163-009- Karla Fant

// The purpose of this file is to build the functions used in the stack
// Firt we have the constructors and destructors, then there's a display all function
// below this is the recursive display that doesn't work. Next, we have the peek function
// allowing the user to look at the top of the stack. After this, theres a push function
// This funciton builds the stack frame. Finally, there's the pop function to pop
// or reomve each item from the stack 

//Constructor
stack::stack()
{
	head = NULL;
	top_index = 0;
}

//Destructor
stack::~stack()
{
	node * current = head;
       	
	while(current)
	{
		delete [] current->entries;
		delete head;
		head = NULL;
		current = current->next;
		head = current;
	}	
}

// Function goes through each node then loops into the dynamically allocated
// array of entries displaying all entries
int stack::display_all() 
{
	node * current = head;
	
	if(!head) return 0;

	while(current)
	{
		for(int i = top_index - 1; i > -1; --i)
		{
			current->entries[i].display();
		}
		current = current->next;
	}
	return 1;
}
// This is the broken recursive display that doesn't display
/*
int stack::display_all(node * head)
{
	if(!head) return 0;			
	for(int i = top_index - 1; i > -1; --i)
	{
		current->entries[i].display();
	}
	display_all(head->next);
	return 1;
}
*/

// The peek function allows the user to look at whats on top of the stack
int stack::peek(const billing_entry & found_at_top)
{
	// checks to see if list not empty or the top index is 0 and there
	// is no other node
	if(!head || top_index == 0 && !head->next) return 0;
	
	// Chcks if there's only one item
	if(top_index ==0 && head->next)
	{
		node * current = head->next;
		current->entries[MAX-1].display();
	}
	// else displays top item
	else
	{
		head->entries[top_index-1].display();
	}
	return 1;

}

// Function to push new billing entries onto the stack 
// Starts with the empty list, which is assumed we start empty, then adds the first node.
// Next, it has an if statment to add into the array contained in each node and ensure we 
// don't go out of bounds in memory, once top_index is greater than MAX it adds a new node
// with the pertinent information. 
int stack::push(billing_entry & to_add)
{
	if(!head)
	{
		head = new node;
		head->entries = new billing_entry[MAX];
		head->entries[top_index].copy_entry(to_add);
		head->next = nullptr;
		++top_index;
		return 0;
	}
	
	if (top_index < MAX)
	{
		head->entries[top_index].copy_entry(to_add);
		++top_index;
	}

	else
	{
		top_index = 0;
		node * temp = new node;
		temp->next = head;
		head = temp;

		head->entries = new billing_entry[MAX];
		head->entries[top_index].copy_entry(to_add);
		
		head = temp;
	}

	return 1;
}

// This function is designed to pop the top item off of the stack.
// First it check if the list is empty and returns since there is nothing to pop.
// Next, we create a hold pointer for the next node Checks to make sure top_index is
// not zero and if not the function dealete sthe entries head is pointing to.
int stack::pop(void)
{
	if(!head) return 0;

	node * hold = head->next;
	if(!top_index)
	{
		if(head->entries)
			delete [] head->entries;
		delete head;
		head = hold;
		top_index = MAX;
	}
	else
	{
		--top_index;
	}
	return 1;
}

