/* calculator.c -- calculations and management functions */
#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"

int menu(void)
{
	int c, status;

	puts("\nAmortization!\n");
	puts("A Sampe Program written by Scott Little");
	puts("\nPlease Select a Menu Option.");
	puts("\n\t1. Calculate (P)ayment Size");
	puts("\t2. Calculate (L)oad Size");
	puts("\t3. Calculate (N)umber of Payments");
	puts("\t4. Calculate (I)nterest (APR)");
	puts("\t5. (Q)uit\n");
	printf("Enter a menu option: ");
	c = getche(stdin);
	c = toupper(c);
	return c;
}


double payment_amount_calc(double get_interest_rate, double get_loan_amount, int get_number_of_months)
{
	(((get_interest_rate / 1200) + ((get_interest_rate / 1200) / (pow((1 + (get_interest_rate / 1200)), (double)get_number_of_months) - 1)))*get_loan_amount);
}
