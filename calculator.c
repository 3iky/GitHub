/* calculato.c -- calculations and management functions */
#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"
#include <math.h>

double payment_amount_calc( double get_loan_amount, double get_interest_rate, int get_number_of_months)
{
	return (((pow((1.0 + (get_interest_rate)), (double)get_number_of_months) / (pow((1.0 + (get_interest_rate )), (double)get_number_of_months) - 1.0)) * get_loan_amount) * (get_interest_rate ));
}

double loan_amount_calc(double get_payment_amount, double get_interest_rate, int get_number_of_months)
{
	return ((pow((1.0 + get_interest_rate), (double)get_number_of_months) - 1.0) / (get_interest_rate * (pow((1.0 + get_interest_rate), (double)get_number_of_months))) * get_payment_amount);
}

int number_of_months_calc(double get_payment_amount, double get_loan_amount, double get_interest_rate)
{
	return  (((log(get_payment_amount) - log(get_payment_amount - (get_loan_amount * get_interest_rate))) / log(1.0 + get_interest_rate)) + 1);

}
