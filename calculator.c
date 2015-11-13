/* calculato.c -- calculations and management functions */
#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"
#include <math.h>

int menu(void)
{
	int c = 0;

	puts("\nAmortization!\n");
	puts("A Sampe Program written by Scott Little");
	puts("\nPlease Select a Menu Option.");
	puts("\n\t1. Calculate (P)ayment Size");
	puts("\t2. Calculate (L)oan Size");
	puts("\t3. Calculate (N)umber of Payments");
	puts("\t4. Calculate (I)nterest (APR)");
	puts("\t5. (Q)uit\n");
	printf("Enter a menu option: ");
	c = getche(stdin);
	c = toupper(c);
	return c;
}


double payment_amount_calc( double get_loan_amount, double get_interest_rate, int get_number_of_months)
{
	return (((pow((1.0 + (get_interest_rate / 1200.0)), (double)get_number_of_months) / (pow((1.0 + (get_interest_rate / 1200.0)), (double)get_number_of_months) - 1.0)) * get_loan_amount) * (get_interest_rate / 1200.0));
}

double loan_amount_calc(double get_loan_size, double get_payment_amount, double get_interest_rate, int get_number_of_months)
{
	get_loan_size = ((pow((1 + (get_interest_rate / 1200)), get_number_of_months) - 1), get_payment_amount) / (get_interest_rate / 1200)*(pow((1 + (get_interest_rate / 1200)), get_number_of_months));
	return get_loan_size;
}

int number_of_months_calc(int get_number_of_months, double get_payment_amount, double get_loan_amount, double get_interest_rate)
{
get_number_of_months = ((-log(1 - (((get_interest_rate / 1200) * get_loan_amount) / get_payment_amount))) / (log(1 + (get_interest_rate / 1200))));
return get_number_of_months;
}
