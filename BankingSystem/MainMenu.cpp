#include "MainMenu.h"

MainMenu::MainMenu() {

	while (true) {
		int menu_selection = get_menu_selection();

		if (menu_selection == 1) {
			create_new_account();
		}
		else if(menu_selection == 2) {
			display_account_info();
		}
		else {
			cout << "Have a nice day!" << endl;
			break;
		}
	}
}

int MainMenu::get_menu_selection() {
	system("CLS");

	cout << "Sean's Sketchy Bank" << endl;

	vector<string> options = { "New Account", "Display Account Info", "Account Transaction", "Exit" };
	int main_menu_choice = Menu::user_options(options);

	return main_menu_choice;
}

void MainMenu::create_new_account() {
	Customer new_customer;

	system("CLS");

	Person person_info = new_customer.create_customer_info();

	system("CLS");

	cout << "Select Account Type: " << endl;
	vector<string> options = { "Savings", "Chequing" };
	int account_choice = Menu::user_options(options);

	if (account_choice == 1) {
		SavingsAccount savings_info = new_customer.create_savings_acc_info();
		new_customer.set_person(person_info);
		new_customer.set_savings_account(savings_info);

		string acc_num = savings_info.get_account_number();
		ofstream customer_file(acc_num + ".txt");
		if (!customer_file.is_open()) {
			cout << "File Error" << endl;
		}
		customer_file << savings_info.get_account_number() << ','
			<< savings_info.get_account_type() << ','
			<< person_info.get_fname() << ','
			<< person_info.get_lname() << ','
			<< person_info.get_dob() << ','
			<< person_info.get_address() << ','
			<< person_info.get_city() << ','
			<< person_info.get_province() << ','
			<< person_info.get_country() << ','
			<< person_info.get_postal_code() << ','
			<< person_info.get_phone_number() << ','
			<< savings_info.get_account_balance() << ','
			<< savings_info.get_account_interest() << endl;
		customer_file.close();
	}
	else {
		ChequingAccount chequing_info = new_customer.create_chequing_acc_info();
		new_customer.set_person(person_info);
		new_customer.set_chequing_account(chequing_info);

		string acc_num = chequing_info.get_account_number();
		ofstream customer_file(acc_num + ".txt");
		if (!customer_file.is_open()) {
			cout << "File Error" << endl;
		}
		customer_file << chequing_info.get_account_number() << ','
			<< chequing_info.get_account_type() << ','
			<< person_info.get_fname() << ','
			<< person_info.get_lname() << ','
			<< person_info.get_dob() << ','
			<< person_info.get_address() << ','
			<< person_info.get_city() << ','
			<< person_info.get_province() << ','
			<< person_info.get_country() << ','
			<< person_info.get_postal_code() << ','
			<< person_info.get_phone_number() << ','
			<< chequing_info.get_account_balance() << endl;
		customer_file.close();
	}
}

void MainMenu::display_account_info() {

	vector<string> tmp_collection;
	string acc_num, tmp;

	system("CLS");

	cout << "Enter Account Number: " << endl;
	cin >> acc_num;
	ifstream customer_file(acc_num + ".txt");
	if (!customer_file.is_open()) {
		cout << "File Error" << endl;
	}
	while (customer_file.good()) {
		getline(customer_file, tmp, ',');
		tmp_collection.push_back(tmp);
	}
	customer_file.close();

	//Savings account
	if (tmp_collection.size() == 13) {
		Person p = { tmp_collection[2], tmp_collection[3], tmp_collection[4],
			tmp_collection[5], tmp_collection[6], tmp_collection[7],
			tmp_collection[8], tmp_collection[9], tmp_collection[10] };
		SavingsAccount sa = { tmp_collection[0], tmp_collection[1],
			stod(tmp_collection[11]), stod(tmp_collection[12]) };

		system("CLS");
		cout << p;
		cout << sa;
		
		cout << "Press any key to return to main menu" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.get();
	}
	else {
		Person p = { tmp_collection[2], tmp_collection[3], tmp_collection[4],
			tmp_collection[5], tmp_collection[6], tmp_collection[7],
			tmp_collection[8], tmp_collection[9], tmp_collection[10] };
		ChequingAccount ca = { tmp_collection[0], tmp_collection[1],
			stod(tmp_collection[11]) };

		system("CLS");
		cout << p;
		cout << ca;

		cout << "Press any key to return to main menu" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.get();
	}
}

