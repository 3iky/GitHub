/* calculator.h -- constants and declrations for calculator.c */
#define QUIT		5
#define MAX 256

int menu(void);

double payment_amount(double get_interest_rate, double get_loan_amount, int get_number_of_months);

double loan_amount(double get_loan_amount, double get_interest_rate, double get_payment_amount, int get_number_of_months);

int number_of_months(int get_number_of_months);
