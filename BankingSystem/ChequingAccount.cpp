#include "ChequingAccount.h"

ChequingAccount::ChequingAccount() {}

ChequingAccount::ChequingAccount(const string &account_number, 
	const string &account_type, const double &account_balance) : 
		Account(account_number, account_type, account_balance) {}

double ChequingAccount::account_withdraw(double account_balance,
	double withdraw_amount) {

	return account_balance - withdraw_amount;
}

double ChequingAccount::account_deposit(double account_balance,
	double deposit_amount) {

	return account_balance + deposit_amount;
}

ostream &operator << (ostream &output, ChequingAccount &ca) {
	output << "Account Number: " << ca.get_account_number() << endl;
	output << "Account Type: " << ca.get_account_type() << endl;
	output << "Account Balance: $" << ca.get_account_balance() << endl;
	return output;
}
