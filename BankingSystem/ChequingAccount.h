#pragma once
#include <string>
#include <iostream>

using namespace std;

class ChequingAccount {

public:
	ChequingAccount();

	ChequingAccount(const string &account_number,
		const string &account_type, const double &account_balance);

	const string get_account_number();

	const string get_account_type();

	const double get_account_balance();

	void set_account_number(const string &account_number);

	void set_account_type(const string &account_type);

	void set_account_balance(const double &account_balance);

	void account_withdraw(double &account_balance, double &withdraw_amount);

	void account_deposit(double &account_balance, double &deposit_amount);

	friend ostream &operator << (ostream &output, ChequingAccount &ca);

private:
	string m_account_number;
	string m_account_type;
	double m_account_balance;
	double m_account_interest;
};