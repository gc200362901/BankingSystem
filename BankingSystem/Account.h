#pragma once
#include <string>
#include <iostream>

using namespace std;

class Account {

public:
	Account();

	Account(const string &account_number,
		const string &account_type, const double &account_balance);

	const string get_account_number();

	const string get_account_type();

	const double get_account_balance();

	void set_account_number(const string &account_number);

	void set_account_type(const string &account_type);

	void set_account_balance(const double &account_balance);

protected:
	string m_account_number;
	string m_account_type;
	double m_account_balance;
};
