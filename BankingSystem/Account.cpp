#include "Account.h"

Account::Account() {}

Account::Account(const string &account_number,
	const string &account_type, const double &account_balance) {

	set_account_number(account_number);
	set_account_type(account_type);
	set_account_balance(account_balance);
}

const string Account::get_account_number() {
	return m_account_number;
}

const string Account::get_account_type() {
	return m_account_type;
}

const double Account::get_account_balance() {
	return m_account_balance;
}

/*
	Sets the account number after validating the number is not empty
	@throws exception if account number is empty
*/
void Account::set_account_number(const string &account_number) {
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
void Account::set_account_type(const string &account_type) {
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

void Account::set_account_balance(const double &account_balance) {
	m_account_balance = account_balance;
}

