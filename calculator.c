/* calculator.c -- calculations and management functions */
#include <stdio.h>
#include "calculator.h"
#pragma warning(disable: 4996)
int menu(void)
{
	int c, status;

	puts("Amortization!\n");
	puts("A Sampe Program written by Scott Little");
	puts("\nPlease Select a Menu Option.");
	puts("\n\t1. Calculate (P)ayment Size");
	puts("\t2. Calculate (L)oad Size");
	puts("\t3. Calculate (N)umber of Payments");
	puts("\t4. Calculate (I)nterest (APR)");
	puts("\t5. (Q)uit\n");
	printf("Enter a menu option: ");
	//scanf("%d", &c);
	c = getche(stdin);
	c = toupper(c);
/* while ((status = scanf("%d", &c)) != 1 || (c < 1 || c > 5) )
	{
		if (status != 1)
			scanf("%s");	// dispose of non-integer input
		printf("Enter a number, please.\n");
	}
*/
	return c;
}

double monthly_payment(double get_payment_amount)
{
	double get_interest_rate = 0.00;
//	double get_payment_amount = 0.00;
	double get_loan_amount = 0.00;
	int get_number_of_months = 0;
	printf("\nPlease enter the interest rate (APR) you will be paying (nearest 1/8 point): ");
	scanf("%lf", &get_interest_rate);
	printf("Interest %.3lf%%", get_interest_rate);
	printf("\nPlease enter the amount of money to be borrowed: $");
	scanf("%lf", &get_loan_amount);
	printf("Principal: $%.2lf", get_loan_amount);
	printf("\nPlease enter the number of months you will be making payments: ");
	scanf("%d", &get_number_of_months);
	printf("Number of Months to pay: %d\n", get_number_of_months);
	get_payment_amount = (((get_interest_rate / 1200) + ((get_interest_rate / 1200) / (pow((1 + (get_interest_rate / 1200)), get_number_of_months) - 1)))*get_loan_amount);

	return get_interest_rate;
}

double loan_amount(double get_loan_amount, double get_interest_rate, double get_payment_amount, int get_number_of_months)
{
	//double get_interest_rate = 0.00;
	//double get_payment_amount = 0.00;
//	double get_loan_amount = 0.00;
	//int get_number_of_months = 0;
	printf("\nPlease enter the interest rate (APR) you will be paying (nearest 1/8 point): ");
	scanf("%lf", &get_interest_rate);
	printf("Interest %.3lf%%", get_interest_rate);
	printf("\nPlease enter the amount of the monthly payment: $");
	scanf("%lf", &get_payment_amount);
	printf("Monthly Payment: $%.2lf", get_payment_amount);
	printf("\nPlease enter the number of months you will be making payments: ");
	scanf("%d", &get_number_of_months);
	printf("Number of Months to pay: %d\n", get_number_of_months);
	get_loan_amount = ((((pow(1 + (get_interest_rate / 1200)) ^ get_number_of_months) - 1), get_payment_amount) / ((get_interest_rate / 1200)*(pow(1 + (get_interest_rate / 1200)), get_number_of_months)));

	return get_loan_amount;
}

int number_of_months(int get_number_of_months)
{
	double get_interest_rate = 0.00;
	double get_payment_amount = 0.00;
	double get_loan_amount = 0.00;
//	int get_number_of_months = 0;
	printf("\nPlease enter the interest rate (APR) you will be paying (nearest 1/8 point): ");
	scanf("%lf", &get_interest_rate);
	printf("Interest %.3lf%%", get_interest_rate);
	printf("\nPlease enter the amount of money to be borrowed: $");
	scanf("%lf", &get_loan_amount);
	printf("Principal: $%.2lf", get_loan_amount);
	puts("\n\tmonthly payment mus be greater than $25.00 ;");
	printf("Please enter the amount of the monthly payment: $");
	scanf("%lf", &get_payment_amount);
	printf("Monthly Payment: $%.2lf", get_payment_amount);
	get_number_of_months = ((-log(1 - (((get_interest_rate / 1200) * get_loan_amount) / get_payment_amount))) / (log(1 + (get_interest_rate / 1200))));

	return get_number_of_months;
}
void showprice(double rate, int nights)
{
	int n;
	double total = 0.0;
	double factor = 1.0;

/*	for (n = 1; n <= nights; n++, factor *= DISCOUNT)
		total += rate * factor;
	printf("The total cost will be $%0.2f.\n", total);
*/
}
