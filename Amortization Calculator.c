/* usehotel.c -- room rate program */
/* compile with Listing 9.10 */
#include <stdio.h>
#include "calculator.h" /* defines constants, declares functions */

int main(void)
{
	int nights;
	double hotel_rate;
	int c;
	double get_interest_rate = 0.00;
	double get_payment_amount = 0.00;
	double get_loan_amount = 0.00;
	int get_number_of_months = 0;

	while ((c = menu()) != QUIT)
	{
		switch (c)
		{
		case 80 :
		case 49 : monthly_payment();
			printf("\nPayment: $%.2lf per month\n\n", get_payment_amount);
			break;
		case 76 :
		case 50: loan_amount(get_loan_amount, get_interest_rate, get_payment_amount, get_number_of_months);
			printf("\nLoan Amount: $%.2lf", get_loan_amount);
			break;
		case 78 :
		case 51: number_of_months(get_number_of_months);
			printf("\nNumber of Months to pay: $%d\n", get_number_of_months);
			break;
		//case 4: hotel_rate = HOTEL4;
			break;
		default: hotel_rate = 0.0;
			printf("\nOops!\n");
			break;
		}
//		nights = getnights();
//		showprice(hotel_rate, nights);
	}
	printf("Thank you and goodbye.\n");

	return 0;
}
