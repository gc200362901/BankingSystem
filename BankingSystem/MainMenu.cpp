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
		else if (menu_selection == 3) {
			account_transaction();
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

void MainMenu::write_savings_account(Person p, SavingsAccount sa) {
	string acc_num = sa.get_account_number();
	ofstream customer_file(acc_num + ".txt");
	if (!customer_file.is_open()) {
		cout << "Error opening file." << endl;
	}
	customer_file << sa.get_account_number() << ','
		<< sa.get_account_type() << ','
		<< p.get_fname() << ','
		<< p.get_lname() << ','
		<< p.get_dob() << ','
		<< p.get_address() << ','
		<< p.get_city() << ','
		<< p.get_province() << ','
		<< p.get_country() << ','
		<< p.get_postal_code() << ','
		<< p.get_phone_number() << ','
		<< sa.get_account_balance() << ','
		<< sa.get_account_interest() << endl;
	customer_file.close();
}

void MainMenu::write_chequing_account(Person p, ChequingAccount ca) {
	string acc_num = ca.get_account_number();
	ofstream customer_file(acc_num + ".txt");
	if (!customer_file.is_open()) {
		cout << "Error opening file." << endl;
	}
	customer_file << ca.get_account_number() << ','
		<< ca.get_account_type() << ','
		<< p.get_fname() << ','
		<< p.get_lname() << ','
		<< p.get_dob() << ','
		<< p.get_address() << ','
		<< p.get_city() << ','
		<< p.get_province() << ','
		<< p.get_country() << ','
		<< p.get_postal_code() << ','
		<< p.get_phone_number() << ','
		<< ca.get_account_balance() << endl;
	customer_file.close();
}

void MainMenu::read_account(vector<string> &tmp_collection) {
	string acc_num, tmp;
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
}

void MainMenu::create_new_account() {
	Customer new_customer;

	system("CLS");

	Person p = new_customer.create_customer_info();

	system("CLS");

	cout << "Select Account Type: " << endl;
	vector<string> options = { "Savings", "Chequing" };
	int account_choice = Menu::user_options(options);

	if (account_choice == 1) {
		SavingsAccount sa = new_customer.create_savings_acc_info();

		write_savings_account(p, sa);
	}
	else {
		ChequingAccount ca = new_customer.create_chequing_acc_info();

		write_chequing_account(p, ca);
	}
}

void MainMenu::display_account_info() {

	vector<string> tmp_collection;
	
	system("CLS");

	read_account(tmp_collection);

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
	//Chequing Account
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

void MainMenu::account_transaction() {
	vector<string> tmp_collection;
	string acc_num, tmp;

	system("CLS");

	read_account(tmp_collection);

	//Savings Account
	if (tmp_collection.size() == 13) {
		Person p = { tmp_collection[2], tmp_collection[3], tmp_collection[4],
			tmp_collection[5], tmp_collection[6], tmp_collection[7],
			tmp_collection[8], tmp_collection[9], tmp_collection[10] };
		SavingsAccount sa = { tmp_collection[0], tmp_collection[1],
			stod(tmp_collection[11]), stod(tmp_collection[12]) };

		system("CLS");

		cout << "Transaction Options: " << endl;
		vector<string> options = { "Deposit", "Withdraw" };
		int transaction_choice = Menu::user_options(options);
		if (transaction_choice == 1) {
			double deposit_amount;
			system("CLS");
			cout << "Enter Deposit Amount: " << endl;
			cin >> deposit_amount;
			double balance = sa.account_deposit(sa.get_account_balance(), deposit_amount);
			sa.set_account_balance(balance);

			write_savings_account(p, sa);

			system("CLS");
			cout << "Account has been updated.\n" << endl;
			cout << sa;
			cout << "Press any key to return to main menu" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.get();
		}
		else {
			double withdraw_amount;
			system("CLS");
			cout << "Enter Withdraw Amount: " << endl;
			cin >> withdraw_amount;
			double balance = sa.account_withdraw(sa.get_account_balance(), withdraw_amount);
			sa.set_account_balance(balance);

			write_savings_account(p, sa);

			system("CLS");
			cout << "Account has been updated.\n" << endl;
			cout << sa;
			cout << "Press any key to return to main menu" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.get();
		}
	}
	//Chequing Account
	else {
		Person p = { tmp_collection[2], tmp_collection[3], tmp_collection[4],
			tmp_collection[5], tmp_collection[6], tmp_collection[7],
			tmp_collection[8], tmp_collection[9], tmp_collection[10] };
		ChequingAccount ca = { tmp_collection[0], tmp_collection[1],
			stod(tmp_collection[11]) };

		system("CLS");

		cout << "Transaction Options: " << endl;
		vector<string> options = { "Deposit", "Withdraw" };
		int transaction_choice = Menu::user_options(options);
		if (transaction_choice == 1) {
			double deposit_amount;
			system("CLS");
			cout << "Enter Deposit Amount: " << endl;
			cin >> deposit_amount;
			double balance = ca.account_deposit(ca.get_account_balance(), deposit_amount);
			ca.set_account_balance(balance);

			write_chequing_account(p, ca);

			system("CLS");
			cout << "Account has been updated.\n" << endl;
			cout << ca;
			cout << "Press any key to return to main menu" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.get();
		}
		else {
			double withdraw_amount;
			system("CLS");
			cout << "Enter Withdraw Amount: " << endl;
			cin >> withdraw_amount;
			double balance = ca.account_withdraw(ca.get_account_balance(), withdraw_amount);
			ca.set_account_balance(balance);

			write_chequing_account(p, ca);

			system("CLS");
			cout << "Account has been updated.\n" << endl;
			cout << ca;
			cout << "Press any key to return to main menu" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.get();
		}
	}
}
