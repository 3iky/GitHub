/* usehotel.c -- room rate program */
/* compile with Listing 9.10 */
#include <stdio.h>
#include <stdlib.h>
#include "calculator.h" /* defines constants, declares functions */
#pragma warning(disable:4996)
#define OUT_FILE_NAME "AmTable.dat"

void file_handle(FILE * fp);

int main(void)
{
	int nights;
	double hotel_rate;
	int c;
	double get_interest_rate = 0.00;
	double get_payment_amount = 0.00;
	double get_loan_amount = 0.00;
	int get_number_of_months = 0;
	FILE * fp = NULL;

	while ((c = menu()) != QUIT)
	{
		switch (c)
		{
		case 80 :
		case 49 : monthly_payment();
			printf("\nPayment: $%.2lf per month\n\n", get_payment_amount);
			file_handle(fp);
			break;
		case 76 :
		case 50: loan_amount(get_loan_amount, get_interest_rate, get_payment_amount, get_number_of_months);
			printf("\nLoan Amount: $%.2lf", get_loan_amount);
			file_handle(fp);
			break;
		case 78 :
		case 51: number_of_months(get_number_of_months);
			printf("\nNumber of Months to pay: $%d\n", get_number_of_months);
			file_handle(fp);
			break;
		default: hotel_rate = 0.0;
			printf("\nOops!\n");
			break;
		}
	}
	printf("Thank you and goodbye.\n");

	return 0;
}

void file_handle(FILE * fp)
{
	double payment = 429.82;
	double get_interest_rate = 0.00;
	double get_payment_amount = 0.00;
	double get_loan_amount = 0.00;
	int get_number_of_months = 0;
	if ((fp = fopen(OUT_FILE_NAME, "w")) == NULL)
	{
		fclose(fp);
		return EXIT_FAILURE;
	}
	fprintf(fp, "Amortization Table for $%.2lf Loan at %.3lf%% interest for %d months\n", get_payment_amount, get_loan_amount, get_interest_rate, get_number_of_months);
	fprintf(fp, "Payments	 Principal paid  Interest Paid   Loan Balance\n");
	while (fprintf(fp, "1   (%9.2lf) $%14.2lf $%14.2f $%14.2lf", payment, payment, payment, payment) == 0);
	 
}
