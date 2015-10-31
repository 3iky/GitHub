#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_INPUT 2
#define FILE_NAME MAX 256
#pragma warning(disable: 4996) 
//Heading
int main(void)
{
	FILE * outFileHandle = NULL;	// handles output file
	char out_file_name[FILENAME_MAX] = "MyTable.txt";
	//char out_file_name;	// holds output file filename
	char c = '\0';
	int n = 0;
	double get_interest_rate = 0.00;
	double get_payment_amount = 0.00;
	double get_loan_amount = 0.00;
	int get_number_of_months = 0;
	puts("Amortization!\n");
	puts("A Sampe Program written by Scott Little");
	puts("\nPlease Select a Menu Option.");
	puts("\n\t1. Calculate (P)ayment Size");
	puts("\t2. Calculate (L)oad Size");
	puts("\t3. Calculate (N)umber of Payments");
	/*	puts("\t4. Calculate (I)nterest (APR)"); */
	puts("\t5. (Q)uit\n");
	printf("Enter a menu option: ");
	c = getche(stdin);
	c = toupper(c);
	if (c == 'P' || c == '1') // get payment amount
	{
		printf("\nPlease enter the interest rate (APR) you will be paying (nearest 1/8 point): ");
		scanf("%lf", &get_interest_rate);
		printf("Interest %.3lf%%", get_interest_rate);
		printf("\nPlease enter the amount of money to be borrowed: $");
		scanf("%lf", &get_loan_amount);
		printf("Principal: $%.2lf", get_loan_amount);
		printf("\nPlease enter the number of months you will be making payments: ");
		scanf("%d", &get_number_of_months);
		printf("Number of Months to pay: %d\n", get_number_of_months);
		get_payment_amount = (((get_interest_rate / 1200) + ((get_interest_rate / 1200) / (pow((1 + (get_interest_rate / 1200)),get_number_of_months) - 1)))*get_loan_amount);
		printf("\nPayment: $%.2lf per month\n", get_payment_amount);
		printf("\nDo you wsh to print an Amortization Table(Y/N)? ");
		c = getche(stdin);
		c = toupper(c);

		switch (c)
		{
		case 89:
			outFileHandle = fopen(out_file_name, "w");
			fprintf(outFileHandle, "Amortization Table for $%.2lf loan at %.3lf% interest for %d months\n",get_loan_amount, get_interest_rate, get_number_of_months);
			fprintf(outFileHandle, "\Payments\tPrincipal Paid\tInterest Paid\tLoan Balance\n");
				for (int i = 0; i < get_number_of_months; i++)
				{
					fprintf(outFileHandle, "%_3d (%3lf) $%_5lf $_5lf $_5lf\n", i, get_payment_amount / get_number_of_months);
				}
			break;
		case 78: puts("HI");
			break;
		default: puts("NO");
		}
	} 
	if (c == 'L' || c == '2') // get money borrowed
	{
		printf("\nPlease enter the interest rate (APR) you will be paying (nearest 1/8 point): ");
		scanf("%lf", &get_interest_rate);
		printf("Interest %.3lf%%", get_interest_rate);
		printf("\nPlease enter the amount of the monthly payment: $");
		scanf("%lf", &get_payment_amount);
		printf("Monthly Payment: $%.2lf", get_payment_amount);
		printf("\nPlease enter the number of months you will be making payments: ");
		scanf("%d", &get_number_of_months);
		printf("Number of Months to pay: %d\n", get_number_of_months);
		get_loan_amount = (((pow((1 + (get_interest_rate / 1200)), get_number_of_months) - 1) * get_payment_amount) / ((get_interest_rate / 1200)*(pow(1 + (get_interest_rate / 1200), get_number_of_months))));
		printf("\nLoan Amount: $%.2lf", get_loan_amount);
		printf("\nDo you wsh to print an Amortization Table(Y/N)? ");
	}
	if (c == 'N' || c == '3') // get number of months
	{
		printf("\nPlease enter the interest rate (APR) you will be paying (nearest 1/8 point): ");
		scanf("%lf", &get_interest_rate);
		printf("Interest %.3lf%%", get_interest_rate);
		printf("\nPlease enter the amount of money to be borrowed: $");
		scanf("%lf", &get_loan_amount);
		printf("Principal: $%.2lf", get_loan_amount);
		puts("\n\tmonthly payment mus be greater than $25.00 ;");
		printf("Please enter the amount of the monthly payment: $");
		scanf("%lf", &get_payment_amount);
		printf("Monthly Payment: $%.2lf\n", get_payment_amount);
		get_loan_amount = ((pow((1 + (get_interest_rate / 1200)), get_number_of_months) - 1) * get_payment_amount) / ((get_interest_rate / 1200)*(pow(1 + (get_interest_rate / 1200), get_number_of_months)));
		printf("\nNumber of Months to pay the loan: %d\n", get_number_of_months);
		printf("\nDo you wsh to print an Amortization Table(Y/N)? ");
	}
	/*	if (c == 'I' || c == '4') // get interest rate
	{
		printf("\nPlease enter the amount of money to be borrowed: $");
		scanf("%lf", &get_loan_amount);
		printf("Principal: $%.2lf", get_loan_amount);
		printf("\nPlease enter the amount of the monthly payment: $");
		scanf("%lf", &get_payment_amount);
		printf("Monthly Payment: $%.2lf", get_payment_amount);
		printf("\nPlease enter the number of months you will be making payments: ");
		scanf("%d", &get_number_of_months);
		printf("Number of Months to pay: %d\n", get_number_of_months);
		
		printf("\nAnnual Percentage Rate: %.3lf\%\n");
		printf("\nDo you wsh to print an Amortization Table(Y/N)? ");
	}	*/


	fclose(outFileHandle);
	getchar();
	getchar();
}
