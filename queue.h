#include "entry.h"

//Colton Vitkoczy
//CS163-009

//The purpose of this file is to contain the q node object as well as the queue class object
// the q_node contains the billing entries along with a next, and teh queue class object 
//contains a display all and function to check if and object is in the queue


//node for a LLL
struct q_node
{
	billing_entry entry;
	q_node * next;
};



// Queue class
class queue
{
		public:
			queue(void); //constructor
			~queue(void);//destructor
//			int display_all();
			int enqueue(billing_entry & to_add);
			int dequeue();
			int PeekQueue();
			int display_all(q_node * head);
		private:
			q_node * rear; // tail/rear pointer
};	
