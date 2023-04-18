#include "bill_structs.h"
//#include "queue.h"
using namespace std;

//Colton Vitkoczy
// CS 163-009 Karla Fant

// This is the clieant program that is used to test the code. The first section is used
// to test the stack and the next section is used to test out the queue. They are commented
// out separately for testing purposes

int main()
{
	stack my_list;
//	queue my_listq;
	billing_entry to_add;

	node * head = NULL;
//	q_node * rear = NULL;

	char payee_name[50];    // Who we're paying
	char bill_description[150]; // 
	char expense_type[100]; //Think there will be only three?
	char payment_method[50]; //How we payeed the bill
	int bill_amount = 0;       // amounbt of bill

	char response = 'Y';
	char response_2 = 'Y';

	// Loops through getting user response	
	while(toupper(response) == 'Y')
	{
		cout<< "enter a payee name: " << endl;
		cin.get(payee_name, 100, '\n');
		cin.ignore(100, '\n');

		cout<< "enter a bill description: " << endl;
		cin.get(bill_description, 100, '\n');
		cin.ignore(100, '\n');

		cout<< "enter a expense type: " << endl;
		cin.get(expense_type, 100, '\n');
		cin.ignore(100, '\n');

		cout<< "enter a payment method: " << endl;
		cin.get(payment_method, 100, '\n');
		cin.ignore(100, '\n');
		
		cout << "enter a bill amount: " << endl;
		cin >> bill_amount;
		cin.ignore(100, '\n');

		// Creates a entry
		to_add.create_entry(payee_name, bill_description, expense_type, payment_method, bill_amount);
		// Pushes that entry onto the stack
		my_list.push(to_add);

		cout << "Would you like to enter another? "; // Allows the user to repeat the previuos steps
		cin >>(response);
		cin.ignore(100, '\n');
	}

	my_list.display_all();
	
	
	while(toupper(response_2) == 'Y')
	{
		if(my_list.pop())
		{
            		cout <<"\n\nAfter removing this is what we have: ";
         		my_list.display_all();
		}
        	else cout <<"\nNothing could be removed, the stack is empty! " <<endl;
	
		cout << "Would you like to delete another? "; // Allows the user to repeat the previuos steps
		cin >>(response_2);
		cin.ignore(100, '\n');
	}	

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/*	
	while(toupper(response) == 'Y')
	{
		cout<< "enter a payee name: " << endl;
		cin.get(payee_name, 100, '\n');
		cin.ignore(100, '\n');

		cout<< "enter a bill description: " << endl;
		cin.get(bill_description, 100, '\n');
		cin.ignore(100, '\n');

		cout<< "enter a expense type: " << endl;
		cin.get(expense_type, 100, '\n');
		cin.ignore(100, '\n');

		cout<< "enter a payment method: " << endl;
		cin.get(payment_method, 100, '\n');
		cin.ignore(100, '\n');
		
		cout << "enter a bill amount: " << endl;
		cin >> bill_amount;
		cin.ignore(100, '\n');

		to_add.create_entry(payee_name, bill_description, expense_type, payment_method, bill_amount);
		my_listq.enqueue(to_add);

		cout << "Would you like to enter another? "; // Allows the user to repeat the previuos steps
		cin >>(response);
		cin.ignore(100, '\n');
	}

	my_listq.display_all(rear);

	while(toupper(response_2) == 'Y')
	{
		if(my_listq.dequeue())
		{
            		cout <<"\n\nAfter removing this is what we have: ";
         		my_listq.display_all(rear);
		}
        	else cout <<"\nNothing could be removed, the stack is empty! " <<endl;
	
		cout << "Would you like to delete another? "; // Allows the user to repeat the previuos steps
		cin >>(response_2);
		cin.ignore(100, '\n');
	}	
	
	my_listq.PeekQueue();
*/	
	return 0;
}




