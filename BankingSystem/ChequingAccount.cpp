#include "ChequingAccount.h"

ChequingAccount::ChequingAccount() {}

ChequingAccount::ChequingAccount(const string &account_number, 
	const string &account_type, const double &account_balance) {

	set_account_number(account_number);
	set_account_type(account_type);
	set_account_balance(account_balance);
}

const string ChequingAccount::get_account_number() {
	return m_account_number;
}

const string ChequingAccount::get_account_type() {
	return m_account_type;
}

const double ChequingAccount::get_account_balance() {
	return m_account_balance;
}

/*
	Sets the account number after validating the number is not empty
	@throws exception if account number is empty
*/
void ChequingAccount::set_account_number(const string &account_number) {
	try {
		if (account_number.length() < 1) {
			throw 1;
		}
		m_account_number = account_number;
	}
	catch (int e) {
		cout << "Account number can not be empty, ERR NUMBER: " << e << endl;
	}
}

/*
	Sets the account type after validating the type is not empty
	@throws exception if account type is empty
*/
void ChequingAccount::set_account_type(const string &account_type) {
	try {
		if (account_type.length() < 1) {
			throw 1;
		}
		m_account_type = account_type;
	}
	catch (int e) {
		cout << "Account type can not be empty, ERR NUMBER: " << e << endl;
	}
}

void ChequingAccount::set_account_balance(const double &account_balance) {
	m_account_balance = account_balance;
}

void ChequingAccount::account_withdraw(double &account_balance,
	double &withdraw_amount) {

	account_balance - withdraw_amount;
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
