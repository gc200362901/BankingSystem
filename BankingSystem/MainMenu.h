#pragma once
#include "Menu.cpp"
#include "Customer.h"
#include "stdlib.h"
#include <fstream>

class MainMenu {

public:
	MainMenu();

	int get_menu_selection();

	void write_savings_account(Person p, SavingsAccount sa);

	void write_chequing_account(Person p, ChequingAccount ca);

	void read_account(vector<string> &tmp_collection);

	void create_new_account();

	void display_account_info();

	void account_transaction();
};
