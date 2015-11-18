/* Amort.c -- calculations and management functions */
#include <stdio.h>
#include <stdlib.h>
#include "Amort.h"
#include <math.h>

double get_payment_amount(double loan_amount, double interest_rate, int number_of_months)
{
	return (((pow((1.0 + (interest_rate)), (double)number_of_months) / (pow((1.0 + (interest_rate )), (double)number_of_months) - 1.0)) * loan_amount) * (interest_rate ));
}

double get_loan_amount(double payment_amount, double interest_rate, int number_of_months)
{
	return ((pow((1.0 + interest_rate), (double)number_of_months) - 1.0) / (interest_rate * (pow((1.0 + interest_rate), (double)number_of_months))) * payment_amount);
}

int get_number_of_months(double payment_amount, double loan_amount, double interest_rate)
{
	return ((log(payment_amount) - log(payment_amount - (loan_amount * interest_rate))) / log(1.0 + interest_rate));

}
