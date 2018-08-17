#include "SavingsAccount.h"

SavingsAccount::SavingsAccount() {}

SavingsAccount::SavingsAccount(const string &account_number,
	const string &account_type, const double &account_balance,
	const double &account_interest) : Account(account_number,
		account_type, account_balance) {

	set_account_interest(account_interest);
}

const double SavingsAccount::get_account_interest() {
	return m_account_interest;
}

/*
Sets the account interest and validates the interest is not less then 0
@throws exception if interest is less then 0
*/
void SavingsAccount::set_account_interest(const double &account_interest) {
	try {
		if (account_interest < 0) {
			throw 1;
		}
		m_account_interest = account_interest;
	}
	catch (int e) {
		cout << "Account interest can not be less then 0, ERR NUMBER: " << e << endl;
	}
}

//void SavingsAccount::calculate_interest() {
//
//}

double SavingsAccount::account_withdraw(double account_balance,
	double withdraw_amount) {

	return account_balance - withdraw_amount;
}

double SavingsAccount::account_deposit(double account_balance,
	double deposit_amount) {

	return account_balance + deposit_amount;
}

ostream &operator << (ostream &output, SavingsAccount &sa) {
	output << "Account Number: " << sa.get_account_number() << endl;
	output << "Account Type: " << sa.get_account_type() << endl;
	output << "Account Balance: $" << sa.get_account_balance() << endl;
	output << "Account Interest: " << sa.get_account_interest() << endl;
	return output;
}