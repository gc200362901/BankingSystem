#pragma once
#include <string>
#include <iostream>

using namespace std;

class SavingsAccount {

public:
	SavingsAccount();

	SavingsAccount(const string &account_number,
		const string &account_type, const double &account_balance,
		const double &account_interest);

	const string get_account_number();

	const string get_account_type();

	const double get_account_balance();

	const double get_account_interest();

	void set_account_number(const string &account_number);

	void set_account_type(const string &account_type);

	void set_account_balance(const double &account_balance);

	void set_account_interest(const double &account_interest);

	void account_withdraw(double &account_balance, double &withdraw_amount);

	double account_deposit(double account_balance, double deposit_amount);

	void calculate_interest();

	friend ostream &operator << (ostream &output, SavingsAccount &sa);

private:
	string m_account_number;
	string m_account_type;
	double m_account_balance;
	double m_account_interest;
};