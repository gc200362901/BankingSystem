#pragma once
#include "Person.h"
#include "SavingsAccount.h"
#include "ChequingAccount.h"

class Customer {

public:
	Customer();

	Customer(const Person &person, const SavingsAccount &savings_account);

	Customer(const Person &person, const ChequingAccount &chequing_account);

	const Person get_person();

	const SavingsAccount get_savings_account();

	const ChequingAccount get_chequing_account();

	void set_person(const Person &person);

	void set_savings_account(const SavingsAccount &savings_account);

	void set_chequing_account(const ChequingAccount &chequing_account);

	const Person create_customer_info();

	const SavingsAccount create_savings_acc_info();

	const ChequingAccount create_chequing_acc_info();

private:
	Person m_person;
	SavingsAccount m_savings_account;
	ChequingAccount m_chequing_account;
};
