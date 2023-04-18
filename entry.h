#include <iostream>
#include <cstring>
#include <cctype>

//Colton Vitkoczy
//CS163-009

//The puprose of thsi file is to have a class object that contains billing information
//along with the function prototypes to create, retrieve, copy, and display


//Got these from lab 3, have them commented out until I do some digging on the concepts
//#define BILLING
//#ifndef BILLING 	

//Class for the billing entry's
class billing_entry
{
	public:
		billing_entry(void); //constructor
		~billing_entry(void);//destructor
		int create_entry(char a_payee_name[], char a_bill_description[], char a_expense_type[], char a_payment_method[], int a_bill_amount);
		//int create_entry(billing_entry & to_add);
		int copy_entry(billing_entry & to_add);
		int retrieve(char * payee_name, char * bill_description, char * expense_type, char * payment_method, int bill_amount)const;
		int retrieve(billing_entry & found) const;
		int display();
		void array_helper(char array[], char * & ptr);

	private:
		char * payee_name;    // Who we're paying
		char * bill_description; // 
		char * expense_type; //Think there will be only three?
		char * payment_method; //How we payeed the bill
	       	int bill_amount;       // amounbt of bill
};
//#endif
//bool again();

