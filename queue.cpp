#include "queue.h"

//Colton Vitkoczy
// CS 163-009 Karla Fant

// The purpose of this file is to build all the functions contained in the queue.h file
// First, it starts with the constructor and destructor functions, then we have the enqueu
// function this builds out the queue, next theres the dequeue function which is calle on 
// to destory a node form the queue. Finally, there's the display and peek funcitons, 
// Display displays everything in the queue and peek looks at whats next in the queue 

// Constructor
queue::queue()
{

	rear = NULL;
}

// Destructor
queue::~queue()
{
	if (!rear) return;
       
        if (!rear->next) 
	{
            delete rear;
	    rear = NULL;
            return;
        }

        q_node * temp = rear->next;
        
	while (temp->next != rear) 
	{
            temp = temp->next;
            delete rear;
            rear = temp;
        }
        delete temp;
	rear = NULL;		
}

// Function to take in entrys and build up a queue starts by checking that
// rear is empty then copies an entry into the queue, after this is done
// the else statement adds a new node and copies the passed in information into the queue 
int queue::enqueue(billing_entry & to_add)
{
	q_node * temp = NULL;

	if (!rear)
	{
		rear = new q_node;
		rear->next = rear;
		rear->entry.copy_entry(to_add);
	}
	else
	{
		temp = rear->next; //hold onto the front 
		rear->next = new q_node; //add new rear node 
		rear = rear->next; //traverse to it 
		rear->entry.copy_entry(to_add);
		rear->next = temp; //reconnect 
	}
	return 1;
}

// Fucntion to delete a node from the queue returns 0 if the queue is empty.
// Next, checks for a one node list and deletes that node. After this, it geos
// into the else statement and deletes the node. 
int queue::dequeue()
{
	if(!rear) return 0;

	if(rear->next == rear)
	{
		delete rear;
		rear = NULL;
	}
	else
	{
		q_node * temp = rear->next;
		rear->next = temp->next;
		delete temp;
	}
	return 1;
}

//Displays everythign in the queue
int queue::display_all()
{
	q_node * current = rear;

	if(!rear) return 0;

	do
	{
		current->entry.display();
		current = current->next;
	}while(current != rear);

	return 1;
}

/*
int queue::display_all(q_node * rear)
{
	if(!rear) return 0;
	
	rear->entry.display();
	display_all(rear->next);
	return 1;
}
*/

// Peeks at the queue to let the client know what is next
int queue::PeekQueue()
{
	if(!rear) return 0;
	std::cout << rear->entry.display() << std::endl;
	return 0;
}




