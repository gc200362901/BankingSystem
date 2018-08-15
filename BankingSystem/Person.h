#pragma once
#include <string>

using namespace std;

class Person {

public:

	Person();

	Person(const string &fname, const string &lname, const string &dob, 
		const string &address, const string &city, const string &province, 
		const string &country, const string &postal_code, 
		const string &phone_number);

	const string get_fname();
	const string get_lname();
	const string get_dob();
	const string get_address();
	const string get_city();
	const string get_province();
	const string get_country();
	const string get_postal_code();
	const string get_phone_number();

	void set_fname(const string &fname);
	void set_lname(const string &lname);
	void set_dob(const string &dob);
	void set_address(const string &address);
	void set_city(const string &city);
	void set_province(const string &province);
	void set_country(const string &country);
	void set_postal_code(const string &postal_code);
	void set_phone_number(const string &phone_number);

	friend ostream &operator << (ostream &output, Person &person);

private:
	string m_fname;
	string m_lname;
	string m_dob;
	string m_address;
	string m_city;
	string m_province;
	string m_country;
	string m_postal_code;
	string m_phone_number;
};
