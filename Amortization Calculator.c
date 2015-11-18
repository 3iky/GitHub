//----------------------------------------------------
//	File:		Source.c
//
//	Functions:
//				menu()
//				safe_read_int()
//				safe_read_double()
//				interest_rate_read
//				loan_amount_read()
//				payment_amount_read()
//				number_of_months_read()
//				payment_amount_calc()
//				loan_amount_calc()
//				number_of_months_calc()
//				file_handle()
//				file_output_prompt()
//				main()
//				
//----------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Amort.h"
#pragma warning(disable:4996)
//---------------------------------------------------------------------- 
// Function: menu( ) 
// 
//    Title: Initial menu funtion 
// 
// Description:  Prompts user at program statup gives
//    user options on what they want to calculate
// 
//    Programmer: Scott Little
//                  
//    Date:  11/18/2015
//	Version: 1.0
// 
// Environment: 
//   Hardware: Intel Core i7
//   Software:  MS Windows 10 for execution; 
//   Compiles under Microsoft Visual Studio 2013
// 
// Input:      int c to select menu option
// 
// Output:     Amortization!
//			   Program witten by Scott Little
//			   Please Select a Menu Option
//			   1. Calculate (P)ayment Size
//			   2. Calculate (L)oan Size
//			   3. Calculate (N)umber of Payments
//			   4. Calculate (I)nterest (APR)
//			   5. (Q)uit
//			   Enter a menu option:
// 
// Called By: main() 
// 
// Calls: None
// 
// Parameters:
//  c: int; handles menu option from user input
//            
//    Returns: integer from user input
// 
// History Log: 
//            11/18/2015 completed version
//----------------------------------------------------------------------
int menu(void)
{
	puts("\nAmortization!\n");
	puts("Program written by Scott Little");
	puts("\nPlease Select a Menu Option.");
	puts("\n\t1. Calculate (P)ayment Size");
	puts("\t2. Calculate (L)oan Size");
	puts("\t3. Calculate (N)umber of Payments");
	puts("\t4. Calculate (I)nterest (APR)");
	puts("\t5. (Q)uit\n");
	printf("Enter a menu option: ");
	c = getche(stdin);
	c = toupper(c);
	puts("");
	return c;
}
//---------------------------------------------------------------------- 
// Function: safe_read_int()
// 
//    Title: Safe Read Integer
// 
// Description:  Reads integer from user input
//    if input not within parameters, reprompt user
// 
//    Programmer: Scott Little
//                  
//    Date:  11/18/2015
//	Version: 1.0
// 
// Environment: 
//   Hardware: Intel Core i7
//   Software:  MS Windows 10 for execution; 
//   Compiles under Microsoft Visual Studio 2013
// 
// Input:      scanf to get user input
// 
// Output:     reprompt if char is \n or not an integer 
// 
// Called By: number_of_months_read()
//			  
// 
// Calls: None
// 
// Parameters: 
//  n: int; holds true or false that scanf returns
//            
//    Returns: continues function if false
//			   repromt if true
// 
// History Log: 
//            11/18/2015 completed version
//----------------------------------------------------------------------
void safe_read_int(int* number_ptr, const char * prompt)
{
	int n = 0;

	do
	{
		printf(prompt);
		n = scanf("%d", number_ptr);
		while (getchar() != '\n');
	} while
		(n != 1);
}
//---------------------------------------------------------------------- 
// Function: safe_read_double()
// 
//    Title: Safe Read Double
// 
// Description:  Reads double from user input
//    if input not within parameters, reprompt user
// 
//    Programmer: Scott Little
//                  
//    Date:  11/18/2015
//	Version: 1.0
// 
// Environment: 
//   Hardware: Intel Core i7
//   Software:  MS Windows 10 for execution; 
//   Compiles under Microsoft Visual Studio 2013
// 
// Input:      scanf to get user input
// 
// Output:     reprompt if char is \n or not a double
// 
// Called By: interest_rate_read()
//			  loan_amount_read()
//			  payment_amount_read()
// 
// Calls: None
// 
// Parameters: 
//  n: int; holds true or false that scanf returns
//            
//    Returns: continues function if false
//			   repromt if true
// 
// History Log: 
//            11/18/2015 completed version
//----------------------------------------------------------------------
void safe_read_double(double* number_ptr, const char * prompt)
{
	int n = 0;

	do
	{
		printf(prompt);
		n = scanf("%lf", number_ptr);
		while (getchar() != '\n');
	} while
		(n != 1);
}
//---------------------------------------------------------------------- 
// Function: interest_rate_read()
// 
//    Title: reads interest rate
// 
// Description:  gets interest rate input from user
//    assigns it to get_intere_rate variable
//	  checks not 0, if not rounds to nearest .250
//    prints out adjusted double, assigns adjusted double
//    to interest_rate_holder
//    converts interest_rate to monthly interest rate as decimal
// 
//    Programmer: Scott Little
//                  
//    Date:  11/18/2015
//	Version: 1.0
// 
// Environment: 
//   Hardware: Intel Core i7
//   Software:  MS Windows 10 for execution; 
//   Compiles under Microsoft Visual Studio 2013
// 
// Input:      interest_rate
// 
// Output:     reprompt if 0
//			   adjustest interest rate to .025
//			   assigns adjusted interest rate to holder variable
//			   converts interest_rate to monthly as decimal
// 
// Called By: payment_amount_calc()
//			  loan_amount_calc()
//			  number_of_months_calc()
// 
// Calls: safe_read_double()
// 
// Parameters: 
//  interest_rate: double; holds user input for interest rate
//  interest_rate_holder: double; holds rounded interest rate
//  MONTHLY_INTEREST_RATE: constant; adjustment to convert to 
//					monthly interest rate as decimal
//            
//    Returns: adjusted interest rate for calculations
// 
// History Log: 
//            11/18/2015 completed version
//----------------------------------------------------------------------
void interest_rate_read(void)
{
	do
		safe_read_double(&interest_rate, "Please enter the interest rate (APR) you will be paying (nearest 1/8 point): ");
	while 
		(interest_rate < 0);
	interest_rate = round(interest_rate * 8) / 8.0;
	printf("Interest %.3lf%%\n", interest_rate);
	interest_rate_holder = interest_rate;
	interest_rate /= MONTHLY_INTEREST_RATE;
}
//---------------------------------------------------------------------- 
// Function: loan_amount_read()
// 
//    Title: reads loan amount
// 
// Description:  gets loan amount input from user
//    assigns it to loan_amount
//	  checks <= 0, if true reprompt
//	  round loan_amount to nearest cent
//    output adjusted amount
// 
//    Programmer: Scott Little
//                  
//    Date:  11/18/2015
//	Version: 1.0
// 
// Environment: 
//   Hardware: Intel Core i7
//   Software:  MS Windows 10 for execution; 
//   Compiles under Microsoft Visual Studio 2013
// 
// Input:      loan_amount
// 
// Output:     reprompt if <= 0
//			   rounds to nearest cent
//			   prints out rounded double
// 
// Called By: payment_amount_calc()
//			  number_of_months_calc()
// 
// Calls: safe_read_double()
// 
// Parameters: 
//  loan_amount: double; holds user input for loan amount
//            
//    Returns: adjusted loan amount for calculations
// 
// History Log: 
//            11/18/2015 completed version
//----------------------------------------------------------------------
void loan_amount_read(void)
{
	do 
		safe_read_double(&loan_amount, "Please enter the amount of money to be borrowed: $");
	while 
		(loan_amount <= 0);
	loan_amount = floor(loan_amount * 100.0 + 0.9999999) / 100.0;
	printf("Principle: $%.2lf\n", loan_amount);
}
//---------------------------------------------------------------------- 
// Function: payment_amount_read()
// 
//    Title: reads payment amount
// 
// Description:  gets monthly payment amount input from user
//    assigns it to payment_amount
//	  checks <= 0, if true reprompt
//	  round payment_amount to nearest cent
//    output adjusted amount
// 
//    Programmer: Scott Little
//                  
//    Date:  11/18/2015
//	Version: 1.0
// 
// Environment: 
//   Hardware: Intel Core i7
//   Software:  MS Windows 10 for execution; 
//   Compiles under Microsoft Visual Studio 2013
// 
// Input:      payment_amount
// 
// Output:     reprompt if <= 0
//			   rounds to nearest cent
//			   prints out rounded double
// 
// Called By: loan_amount_calc()
//			  number_of_months_calc()
// 
// Calls: safe_read_double()
// 
// Parameters: 
//  payment_amount: double; holds user input for payment amount
//            
//    Returns: adjusted payment amount for calculations
// 
// History Log: 
//            11/18/2015 completed version
//----------------------------------------------------------------------
void payment_amount_read(void)
{
	puts("\tmonthly payment must be greater than $25.00;");
	do
		safe_read_double(&payment_amount, "Please enter the amount of the monthly payment: $");
	while 
		(payment_amount <= 0);
	payment_amount = floor(payment_amount * 100.0 + 0.99999999) / 100.0;
	printf("Monthly Payment: $%.2lf\n", payment_amount);
}
//---------------------------------------------------------------------- 
// Function: number_of_months_read()
// 
//    Title: reads number of months
// 
// Description:  gets length of loan in months
//    assigns it to number_of_months
//	  checks not <= 0, if true reprompt
//    output inputed amount
// 
//    Programmer: Scott Little
//                  
//    Date:  11/18/2015
//	Version: 1.0
// 
// Environment: 
//   Hardware: Intel Core i7
//   Software:  MS Windows 10 for execution; 
//   Compiles under Microsoft Visual Studio 2013
// 
// Input:      number_of_months
// 
// Output:     reprompt if <= 0
//			   rounds to nearest cent
//			   prints out rounded double
// 
// Called By: loan_amount_calc()
//			  payment_amount_calc()
// 
// Calls: safe_read_int()
// 
// Parameters: 
//  number_of_months: int; holds user input for length
//				    of loan in months
//            
//    Returns: amount of months for calculations
// 
// History Log: 
//            11/18/2015 completed version
//----------------------------------------------------------------------
void number_of_months_read(void)
{
	do
	{
		safe_read_int(&number_of_months, "Please enter the number of months you will be making payments: ");
	}
		while (number_of_months <= 0);
	printf("Number of Months to pay: %d\n", number_of_months);
}
//---------------------------------------------------------------------- 
// Function: payment_amount()
// 
//    Title: payments to fill loan
// 
// Description:  prompts user for
//			interest rate
//			loan amount
//			length of loan in months
//			calculates payments needed to complete loan
//			outputs payments needed
// 
//    Programmer: Scott Little
//                  
//    Date:  11/18/2015
//	Version: 1.0
// 
// Environment: 
//   Hardware: Intel Core i7
//   Software:  MS Windows 10 for execution; 
//   Compiles under Microsoft Visual Studio 2013
// 
// Input:      interest, loan amount, length of loan
// 
// Output:     calculated payment amount
// 
// Called By: main()
//			  file_handle()
// 
// Calls: interest_rate_read()
//		  loan_amount_read()
//		  number_of_months_read()
//		  get_payment_amount()
//
// Parameters: 
//  payment_amount: double; holds calculated amount of
//				payment needed to satisfy loan
//            
//    Returns: calculated payment amount
// 
// History Log: 
//            11/18/2015 completed version
//----------------------------------------------------------------------
void payment_amount_calc(void)
{
	interest_rate_read();
	loan_amount_read();
	number_of_months_read();
	if (interest_rate == 0)
		payment_amount = (loan_amount / number_of_months);
	else 
		payment_amount = get_payment_amount(loan_amount, interest_rate, number_of_months);
	printf("\nPayment: $%.2lf per month\n\n", payment_amount);
}
//---------------------------------------------------------------------- 
// Function: loan_amount()
// 
//    Title: total loan amount
// 
// Description:  prompts user for
//			interest rate
//			length of loan in months
//			payment amount
//			calculates loan size
//			outputs loan size
// 
//    Programmer: Scott Little
//                  
//    Date:  11/18/2015
//	Version: 1.0
// 
// Environment: 
//   Hardware: Intel Core i7
//   Software:  MS Windows 10 for execution; 
//   Compiles under Microsoft Visual Studio 2013
// 
// Input:      interest rate, number of months, payment amount
// 
// Output:     calculated loan amount
// 
// Called By: main()
//			  file_handle()
// 
// Calls: interest_rate_read()
//		  number_of_months_read()
//		  payment_amount_read()
//		  get_loan_amount()
//
// Parameters: 
//  loan_amount: double; holds calculated amount of
//				loan needed to satisfy terms
//            
//    Returns: calculated loan amount
// 
// History Log: 
//            11/18/2015 completed version
//----------------------------------------------------------------------
void loan_amount_calc(void)
{
	interest_rate_read();
	number_of_months_read();
	payment_amount_read();
	if (interest_rate == 0.0)
		loan_amount = (payment_amount * number_of_months);
	else
		loan_amount = get_loan_amount(payment_amount, interest_rate, number_of_months);
	printf("\nLoan Amount: $%.2lf\n\n", loan_amount);
}
//---------------------------------------------------------------------- 
// Function: number_of_months()
// 
//    Title: months to satisfy loan
// 
// Description:  prompts user for
//			interest rate
//			loan amount
//			payment amount
//			calculates length in months needed to complete loan
//			outputs months to payoff loan
// 
//    Programmer: Scott Little
//                  
//    Date:  11/18/2015
//	Version: 1.0
// 
// Environment: 
//   Hardware: Intel Core i7
//   Software:  MS Windows 10 for execution; 
//   Compiles under Microsoft Visual Studio 2013
// 
// Input:      interest, loan amount, length of loan
// 
// Output:     calculated payment amount
// 
// Called By: main()
//			  file_handle()
// 
// Calls: interest_rate_read()
//		  loan_amount_read()
//		  payment_amount_read()
//		  get_number_of_months()
//
// Parameters: 
//  number_of_months: int; holds calculated length of
//				loan
//            
//    Returns: length of loan in months
// 
// History Log: 
//            11/18/2015 completed version
//----------------------------------------------------------------------
void number_of_months_calc(void)
{
	interest_rate_read();
	loan_amount_read();
	payment_amount_read();
	if (interest_rate == 0)
		number_of_months = (loan_amount / payment_amount);
	else
		number_of_months = get_number_of_months(payment_amount, loan_amount, interest_rate);
	printf("\nNumber of Months to pay: %d\n\n", number_of_months);
}
//---------------------------------------------------------------------- 
// Function: file_handle()
// 
//    Title: output to txt file
// 
// Description:  writes inputs/outputs to external txt file
// 
//    Programmer: Scott Little
//                  
//    Date:  11/18/2015
//	Version: 1.0
// 
// Environment: 
//   Hardware: Intel Core i7
//   Software:  MS Windows 10 for execution; 
//   Compiles under Microsoft Visual Studio 2013
// 
// Input:      loan amount, interest rate, payment amount, number of months
// 
// Output:     to text file
//			   payment amount
//			   principal paid
//			   interest paid
//			   loan balance	   
// 
// Called By: main()
// 
// Calls: None
//
// Parameters: 
//		loan_balance: double; loan size after each payment
//		interest_paid: double; amount of interest paid each payment
//		principal_paid: double; payment each month with interest
//            
//    Returns:  output to file calculating payments per month
//				AmTable.txt
//				closes file
//				clears console
// 
// History Log: 
//            11/18/2015 completed version
//----------------------------------------------------------------------
void file_handle(FILE * fp)
{
	int i = 0;

	if ((fp = fopen(OUT_FILE_NAME, "w")) == NULL)
	{
		fclose(fp);
		return EXIT_FAILURE;
	}
	fprintf(fp, "Amortization Table for $%.2lf Loan at %.3lf%% interest for %d months\n", loan_amount, interest_rate_holder, number_of_months);
	fprintf(fp, "Payments	 Principal paid  Interest Paid   Loan Balance\n");
	loan_balance = loan_amount;
	for (i = 0; i < number_of_months; i++)
	{
		interest_paid = (interest_rate * loan_balance);
		principal_paid = (payment_amount - interest_paid);
		loan_balance -= principal_paid;
		if (loan_balance < 0)
			loan_balance = 0.00;
		fprintf(fp, "%-3d (%9.2lf) $%14.2lf $%14.2f $%14.2lf\n", (i + 1), payment_amount, principal_paid, interest_paid, loan_balance);
	}
	fclose(fp);
	system("cls");
}
//---------------------------------------------------------------------- 
// Function: file_output_prompt()
// 
//    Title: ask user for table
// 
// Description:  asks if user wants to output calcuations
//			to external txt file
// 
//    Programmer: Scott Little
//                  
//    Date:  11/18/2015
//	Version: 1.0
// 
// Environment: 
//   Hardware: Intel Core i7
//   Software:  MS Windows 10 for execution; 
//   Compiles under Microsoft Visual Studio 2013
// 
// Input:      char c
// 
// Output:     char c
// 
// Called By: main()
// 
// Calls: file_handle
//
// Parameters: 
//		c: char; holds integer value for user input
//            
//    Returns:  yes or no to create and write txt file
// 
// History Log: 
//            11/18/2015 completed version
//----------------------------------------------------------------------
void file_output_prompt(void)
{
	do
	{
		printf("\nDo you wish to print an Amortization Table(Y/N)?");
		c = getche(stdin);
		c = tolower(c);
	} 
	while (c != 121 && c != 110);
	if (c = 'y')
		file_handle(fp);
}
//---------------------------------------------------------------------- 
// Function: main()
// 
//    Title: Amortization calculator
// 
// Description:  prompts user for
//			type of calculation needed
//			calculates needed information
//			requests to output information to file
//			if yes, sends information to txt file
// 
//    Programmer: Scott Little
//                  
//    Date:  11/18/2015
//	Version: 1.0
// 
// Environment: 
//   Hardware: Intel Core i7
//   Software:  MS Windows 10 for execution; 
//   Compiles under Microsoft Visual Studio 2013
// 
// Input:      user chosen menu options
// 
// Output:     payment amount
//			   loan amount
//			   number of months
//			   calculations to txt file
// 
// Called By: 
// 
// Calls: payment_amount()
//		  loan_amount()
//		  number_of_months()
//		  file_output_prompt()
//
// Parameters: 
//  case 80: int; numberical for p
//  case 49: int; for 1
//	case 76: int; numberical for l
//	case 50: int; for 2
//	case 78: int; numberical for n
//	case 51: int; for 3
//  case 73: int; numberical for i
//  case 52: int; for 4
//	case 81: int; numberical for q
//	case 53: int; for 5
//            
//    Returns: 
// 
// History Log: 
//            11/18/2015 completed version
//----------------------------------------------------------------------
int main(void)
{
	while ((c = menu()) != QUIT)
	{
		switch (c)
		{
		case 80 :
		case 49: payment_amount_calc();
			file_output_prompt();
			printf("Payment: $%.2lf per month\n\n", payment_amount);
			break;
		case 76 :
		case 50: loan_amount_calc();
			file_output_prompt();
			printf("Total loan amount: $%.2lf\n\n", loan_amount);
			break;
		case 78 :
		case 51: number_of_months_calc();
			file_output_prompt();
			printf("Number of months: %d\n\n", number_of_months);
			break;
		case 73 :
		case 52: puts("placeholder");
			file_output_prompt();
			printf("Interest rate: %d\n\n", c);
		case 81 :
		case 53 : 
			return EXIT_SUCCESS;
		default: 
			puts("Please enter a valid menu choice.");
			break;
		}
	}
}
