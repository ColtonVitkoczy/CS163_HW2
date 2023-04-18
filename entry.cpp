#include "entry.h"

//Colton Vitkoczy
// CS163-009 Karla Fant

// The purpos of this file is to build all of the protoype in the enty.h file
// which contains the billing_entry class. First it goes through and builds a constructor and destructor
// Then is has an arra yhelper function which is a simplified code for handling dynamically allocated arrays
// the next function creates each entry and passes it to the array helper. After this we have a copy_entry function
// this does the same thing as the cuntion above only it takes a billing entry class as an argument. This is so main
// can pass in the entire entry as one. Finally there's a display function that just grabs every entry in the
// billing entry, this is for the stacj and queue display functions. 

// Constructor
billing_entry::billing_entry(void)
{
	payee_name = NULL;    // Who we're paying
	bill_description = NULL; // 
	expense_type = NULL; //Think there will be only three?
	payment_method = NULL; //How we payeed the bill
	bill_amount = 0;       // amounbt of bill
}	

// Destructor
billing_entry::~billing_entry(void)
{
	delete [] payee_name;
	delete [] bill_description;
	delete [] expense_type;
	delete [] payment_method;

	payee_name = bill_description = expense_type = payment_method = NULL;
	bill_amount = 0;	
}

// Array helper, passes in a char array and a pointer variable by referemce
// Then, it allocates new memory for the pointer and strcpys, it into the array.
void billing_entry::array_helper(char array[], char * & ptr)
{
	ptr = new char[strlen(array)+1];
	strcpy(ptr, array);
}

//Creates an entry by reading in billing information and passing it to the array helper
int billing_entry::create_entry(char a_payee_name[], char a_bill_description[], char a_expense_type[], char a_payment_method[], int a_bill_amount)
{
	array_helper(a_payee_name, payee_name);
	array_helper(a_bill_description, bill_description);
	array_helper(a_expense_type, expense_type);
	array_helper(a_payment_method, payment_method);
	bill_amount = a_bill_amount;
	
	return 1;
}

// Does the same thing as the function above only now uses a billing entry object as the
// funciton parameter
int billing_entry::copy_entry(billing_entry & to_add)
{
	array_helper(to_add.payee_name, payee_name);
	array_helper(to_add.bill_description, bill_description);
	array_helper(to_add.expense_type, expense_type);
	array_helper(to_add.payment_method, payment_method);
	bill_amount = to_add.bill_amount;

	return 1;
}

// function that can be used to display all information in a billing entry
int billing_entry::display()
{
	std::cout << payee_name << std:: endl;
	std::cout << bill_description << std:: endl;
	std::cout << expense_type << std:: endl;
	std::cout << payment_method << std:: endl;
	std::cout << bill_amount << std:: endl;
	return 1;
}
























