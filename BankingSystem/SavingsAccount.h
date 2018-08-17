#pragma once
#include "Account.h"

using namespace std;

class SavingsAccount : public Account {

public:
	SavingsAccount();

	SavingsAccount(const string &account_number,
		const string &account_type, const double &account_balance,
		const double &account_interest);

	const double get_account_interest();

	void set_account_interest(const double &account_interest);

	/*void calculate_interest();*/

	double account_withdraw(double account_balance, double withdraw_amount);

	double account_deposit(double account_balance, double deposit_amount);

	friend ostream &operator << (ostream &output, SavingsAccount &sa);

private:
	double m_account_interest;
};