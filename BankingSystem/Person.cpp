#include "Person.h"
#include <iostream>

Person::Person() {}

Person::Person(const string &fname, const string &lname, const string &dob, 
	const string &address, const string &city, const string &province, 
	const string &country, const string &postal_code, 
	const string &phone_number) {

	set_fname(fname);
	set_lname(lname);
	set_dob(dob);
	set_address(address);
	set_city(city);
	set_province(province);
	set_country(country);
	set_postal_code(postal_code);
	set_phone_number(phone_number);
}

const string Person::get_fname() {
	return m_fname;
}
const string Person::get_lname() {
	return m_lname;
}
const string Person::get_dob() {
	return m_dob;
}
const string Person::get_address() {
	return m_address;
}
const string Person::get_city() {
	return m_city;
}
const string Person::get_province() {
	return m_province;
}

const string Person::get_country() {
	return m_country;
}

const string Person::get_postal_code() {
	return m_postal_code;
}
const string Person::get_phone_number() {
	return m_phone_number;
}

/*
	Sets the first name after checking a valid string is entered.
	@throws exception if string length is < then 1
*/
void Person::set_fname(const string &fname) {
	try {
		if (fname.length() < 1) {
			throw 1;
		}
		m_fname = fname;
	}
	catch (int e) {
		cout << "First name cannot be empty, ERR NUMBER: " << e << endl;
	}	
}

/*
	Sets the last name after checking a valid string is entered.
	@throws exception if string length is < then 1
*/
void Person::set_lname(const string &lname) {
	try {
		if (lname.length() < 1) {
			throw 1;
		}
		m_lname = lname;
	}
	catch (int e) {
		cout << "Last name cannot be empty, ERR NUMBER: " << e << endl;
	}
}

/*
	Sets the Dob object.
*/
void Person::set_dob(const string &dob) {
	m_dob = dob;
}

/*
	Sets the address after checking a valid string is entered.
	@throws exception if string length is < then 1
*/
void Person::set_address(const string &address) {
	try {
		if (address.length() < 1) {
			throw 1;
		}
		m_address = address;
	}
	catch (int e) {
		cout << "Address cannot be empty, ERR NUMBER: " << e << endl;
	}
}

/*
	Sets the city after checking a valid string is entered.
	@throws exception if string length is < then 1
*/
void Person::set_city(const string &city) {
	try {
		if (city.length() < 1) {
			throw 1;
		}
		m_city = city;
	}
	catch (int e) {
		cout << "City cannot be empty, ERR NUMBER: " << e << endl;
	}
}

/*
	Sets the province after checking a valid string is entered and the 
	string matches one of the 13 strings within the provinces array.
	@throws exception if string length is < then 1
	@throws exception if string is not located in array
*/
void Person::set_province(const string &province) {
	string provinces[13] = {"AB", "BC", "MB", "NB", "NL", "NS", "NT", 
		                    "NU", "ON", "PE", "QC", "SK", "YT"};
	try {
		if (province.length() < 1) {
			throw 1;
		}
	}
	catch (int e) {
		cout << "Province cannot be empty, ERR NUMBER: " << e << endl;
	}
	try {
		bool valid_province = false;
		for (int i = 0; i < 13; i++) {
			if (provinces[i] == province) {
				valid_province = true;
			}
		}
		if (valid_province == true) {
			m_province = province;
		}
		else {
			throw 2;
		}
	}
	catch (int e) {
		cout << "Valid provinces: AB, BC, MB, NB, NL, NS, NT, NU, ON, PE, QC, SK, YT., ERR NUMBER: " 
			<< e << endl;
	}
}
void Person::set_country(const string &country) {
	m_country = country;
}

void Person::set_postal_code(const string &postal_code) {
	m_postal_code = postal_code;
}
void Person::set_phone_number(const string &phone_number) {
	m_phone_number = phone_number;
}

ostream &operator << (ostream &output, Person &person) {
	output << "First Name: " << person.get_fname() << endl;
	output << "Last Name: " << person.get_lname() << endl;
	output << "Date Of Birth: " << person.get_dob() << endl;
	output << "Address: " << person.get_address() << endl;
	output << "City: " << person.get_city() << endl;
	output << "Province: " << person.get_province() << endl;
	output << "Country: " << person.get_country() << endl;
	output << "Postal Code: " << person.get_postal_code() << endl;
	output << "Phone Number: " << person.get_phone_number() << endl;
	return output;
}