/* Amort.h -- constants and declrations for Amort.c */
#ifndef ARRAYS_H
#define QUIT 5
#define OUT_FILE_NAME "AmTable.txt"
#define MONTHLY_INTEREST_RATE 1200.0

double interest_rate;
double payment_amount;
double loan_amount;
int number_of_months;
double interest_rate_holder;

double principal_paid;
double interest_paid;
double loan_balance;

FILE * fp;
int c;

double get_payment_amount(double interest_rate, double loan_amount, int number_of_months);

double get_loan_amount(double payment_amount, double interest_rate, int number_of_months);

int get_number_of_months(double payment_amount, double interest_rate, double loan_amount);

#endif
