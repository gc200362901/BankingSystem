#include "SavingsAccount.h"

SavingsAccount::SavingsAccount() {}

SavingsAccount::SavingsAccount(const string &account_number,
	const string &account_type, const double &account_balance,
	const double &account_interest) {

	set_account_number(account_number);
	set_account_type(account_type);
	set_account_balance(account_balance);
	set_account_interest(account_interest);
}

const string SavingsAccount::get_account_number() {
	return m_account_number;
}

const string SavingsAccount::get_account_type() {
	return m_account_type;
}

const double SavingsAccount::get_account_balance() {
	return m_account_balance;
}

const double SavingsAccount::get_account_interest() {
	return m_account_interest;
}

/*
Sets the account number after validating the number is not empty
@throws exception if account number is empty
*/
void SavingsAccount::set_account_number(const string &account_number) {
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
void SavingsAccount::set_account_type(const string &account_type) {
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

/*
Sets the account balance and validates the balance is not less then 0
@throws exception if balance is less then 0
*/
void SavingsAccount::set_account_balance(const double &account_balance) {
	try {
		if (account_balance < 0) {
			throw 1;
		}
		m_account_balance = account_balance;
	}
	catch (int e) {
		cout << "Savings account balance can not be less then 0, ERR NUMBER: " << e << endl;
	}
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

void SavingsAccount::account_withdraw(double &account_balance, 
	double &withdraw_amount) {

	account_balance - withdraw_amount;
}

void SavingsAccount::account_deposit(double &account_balance, 
	double &deposit_amount) {

	account_balance - deposit_amount;
}

void SavingsAccount::calculate_interest() {

}

ostream &operator << (ostream &output, SavingsAccount &sa) {
	output << "Account Number: " << sa.get_account_number() << endl;
	output << "Account Type: " << sa.get_account_type() << endl;
	output << "Account Balance: " << sa.get_account_balance() << endl;
	output << "Account Interest: " << sa.get_account_interest() << endl;
	return output;
}