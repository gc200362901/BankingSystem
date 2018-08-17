#pragma once
#include "Account.h"

class ChequingAccount : public Account {
public:
	ChequingAccount();

	ChequingAccount(const string &account_number,
		const string &account_type, const double &account_balance);

	double account_withdraw(double account_balance, double withdraw_amount);

	double account_deposit(double account_balance, double deposit_amount);

	friend ostream &operator << (ostream &output, ChequingAccount &ca);
};
