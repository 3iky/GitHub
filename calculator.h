/* calculator.h -- constants and declrations for calculator.c */
#define QUIT		5


// shows list of choices
int menu(void);

double payment_amount(double get_payment_amount);

//
double loan_amount(double get_loan_amount, double get_interest_rate, double get_payment_amount, int get_number_of_months);

int number_of_months(int get_number_of_months);

// returns number of nights desired
int getnights(void);

// calculates price from rate, nights
// and displays result
void shsowprice(double rate, int nights);
