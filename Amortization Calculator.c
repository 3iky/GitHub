/* Source.c -- Amortization calculator*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calculator.h"
#pragma warning(disable:4996)
#define OUT_FILE_NAME "AmTable.txt"

double get_interest_rate = 0.0;
double get_payment_amount = 0.0;
double get_loan_amount = 0.0;
int get_number_of_months = 0;

double principal_paid = 0.0;
double interest_paid = 0.0;
double loan_balance = 0.0;
int i = 0;

double payment_amount(void);
double loan_amount(void);
int number_of_months(void);
void file_handle(FILE * fp);
double round_double(void);

double interest_rate_read(void);
double 	loan_amount_read(void);
double payment_amount_read(void);
int number_of_months_read(void);

void safe_read_int(int* number_ptr, const char * prompt);
void safe_read_double(double* number_ptr, const char * prompt);

int main(void)
{
	int c;
	FILE * fp = NULL;

	while ((c = menu()) != QUIT)
	{
		switch (c)
		{
		case 80 :
		case 49: payment_amount();
			printf("\nDo you wish to print an Amortization Table(Y/N)?");
			c = getche(stdin);
			c = tolower(c);
			if (c = 'y')
				file_handle(fp);
			printf("Payment: $%.2lf per month\n\n", get_payment_amount);
			break;
		case 76 :
		case 50: loan_amount();
			printf("\nDo you wish to print an Amortization Table(Y/N)?");
			c = getche(stdin);
			c = tolower(c);
			if (c = 'y')
				file_handle(fp);
			printf("Total loan amount: $%.2lf\n\n", get_loan_amount);
			break;
		case 78 :
		case 51: number_of_months();
			printf("\nDo you wish to print an Amortization Table(Y/N)?");
			c = getche(stdin);
			c = tolower(c);
			if (c = 'y')
				file_handle(fp);
			printf("Number of months: %d\n\n", get_number_of_months);
			break;
		default: 
			return EXIT_SUCCESS;
		}
	}
}

double payment_amount(void)
{
	interest_rate_read();
	loan_amount_read();
	number_of_months_read();
	get_payment_amount = payment_amount_calc(get_loan_amount, get_interest_rate, get_number_of_months);
	printf("\nPayment: $%.2lf per month\n\n", get_payment_amount);
}

double loan_amount(void)
{
	interest_rate_read();
	number_of_months_read();
	payment_amount_read();
	get_loan_amount = loan_amount_calc(get_loan_amount, get_payment_amount, get_interest_rate, get_number_of_months);
	printf("\nLoan Amount: $%.2lf\n\n", get_loan_amount);
}

int number_of_months(void)
{
	interest_rate_read();
	loan_amount_read();
	payment_amount_read();
	get_number_of_months = number_of_months_calc(get_number_of_months, get_payment_amount, get_loan_amount, get_interest_rate);
	printf("\nNumber of Months to pay: %d\n\n", get_number_of_months);
}

void file_handle(FILE * fp)
{
	if ((fp = fopen(OUT_FILE_NAME, "w")) == NULL)
	{
		fclose(fp);
		return EXIT_FAILURE;
	}
	fprintf(fp, "Amortization Table for $%.2lf Loan at %.3lf%% interest for %d months\n", get_loan_amount, get_interest_rate, get_number_of_months);
	fprintf(fp, "Payments	 Principal paid  Interest Paid   Loan Balance\n");
	loan_balance = get_loan_amount;
	for (i = 0; i < get_number_of_months; i++)
	{
		interest_paid = ((get_interest_rate / 1200) * loan_balance);
		principal_paid = (get_payment_amount - interest_paid);
		loan_balance -= principal_paid;
		fprintf(fp, "%-3d (%9.2lf) $%14.2lf $%14.2f $%14.2lf\n", (i + 1), get_payment_amount, principal_paid, interest_paid, loan_balance);
	}
	system("cls");
}

double interest_rate_read(void)
{
	safe_read_double(&get_interest_rate, "\nPlease enter the interest rate (APR) you will be paying (nearest 1/8 point): ");
	get_interest_rate = round(get_interest_rate * 8) / 8.0;
	printf("Interest %.3lf%%", get_interest_rate);
}

double loan_amount_read(void)
{
	safe_read_double(&get_loan_amount, "\nPlease enter the amount of money to be borrowed: $");
	get_loan_amount = floor(get_loan_amount * 100.0 + 0.9999) / 100.0;
	printf("Principle: $%.2lf\n", get_loan_amount);
}	

double payment_amount_read(void)
{
	puts("\n\tmonthly payment mus be greater than $25.00 ;");
	safe_read_double(&get_payment_amount, "Please enter the amount of the monthly payment: $");
	get_payment_amount = floor(get_payment_amount * 100.0 + 0.9999) / 100.0;
	printf("Monthly Payment: $%.2lf\n", get_payment_amount);
}

int number_of_months_read(void)
{
	safe_read_int(&get_number_of_months, "Please enter the number of months you will be making payments: ");
	printf("Number of Months to pay: %d\n", get_number_of_months);
}

void safe_read_int(int* number_ptr, const char * prompt)
{
	printf(prompt);
	scanf("%d", number_ptr);
	while (getchar() != '\n');
}
void safe_read_double(double* number_ptr, const char * prompt)
{
	printf(prompt);
	scanf("%lf", number_ptr);
	while (getchar() != '\n');
}
