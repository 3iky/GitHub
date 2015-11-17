/* calculator.h -- constants and declrations for calculator.c */
#ifndef ARRAYS_H
#define QUIT		5
#define MAX 256

double payment_amount_calc(double adjusted_interest_rate, double get_loan_amount, int get_number_of_months);

double loan_amount_calc(double get_payment_amount, double get_interest_rate, int get_number_of_months);

int number_of_months_calc(double get_payment_amount, double get_interest_rate, double get_loan_amount);

#endif
