#include "Customer.h"

Customer::Customer() {}

Customer::Customer(const Person &person, 
	const SavingsAccount &savings_account) {

	set_person(person);
	set_savings_account(savings_account);
}

Customer::Customer(const Person &person, 
	const ChequingAccount &chequing_account) {

	set_person(person);
	set_chequing_account(chequing_account);
}

const Person Customer::get_person() {
	return m_person;
}

const SavingsAccount Customer::get_savings_account() {
	return m_savings_account;
}

const ChequingAccount Customer::get_chequing_account() {
	return m_chequing_account;
}

void Customer::set_person(const Person &person) {
	m_person = person;
}

void Customer::set_savings_account(const SavingsAccount &savings_account) {
	m_savings_account = savings_account;
}

void Customer::set_chequing_account(const ChequingAccount &chequing_account) {
	m_chequing_account = chequing_account;
}

const Person Customer::create_customer_info() {
	
	string fname, lname, dob, address, city, province, 
		country, postal_code, phone_number;

	cout << "First Name: " << endl;
	getline(cin, fname);
	cout << "Last Name: " << endl;
	getline(cin, lname);
	cout << "Date of Birth: " << endl;
	getline(cin, dob);
	cout << "Address: " << endl;
	getline(cin, address);
	cout << "City: " << endl;
	getline(cin, city);
	cout << "Province: " << endl;
	getline(cin, province);
	cout << "Country: " << endl;
	getline(cin, country);
	cout << "Postal Code: " << endl;
	getline(cin, postal_code);
	cout << "Phone Number: " << endl;
	getline(cin, phone_number);

	Person customer_info = { fname, lname, dob, address, city, 
		province, country, postal_code, phone_number };

	return customer_info;
}

const SavingsAccount Customer::create_savings_acc_info() {

	string account_number, account_type = "Savings";
	double account_balance = 0, account_interest;

	cout << "Account Number: " << endl;
	getline(cin, account_number);
	cout << "Account Interest: " << endl;
	cin >> account_interest;

	SavingsAccount savings_acc_info = { account_number, account_type, 
		account_balance, account_interest };

	return savings_acc_info;
}

const ChequingAccount Customer::create_chequing_acc_info() {

	string account_number, account_type = "Chequing";
	double account_balance = 0;

	cout << "Account Number: " << endl;
	getline(cin, account_number);

	ChequingAccount chequing_acc_info = { account_number, account_type,
		account_balance };

	return chequing_acc_info;
}