#pragma once
#include "Menu.cpp"
#include "Customer.h"
#include "stdlib.h"
#include <fstream>

class MainMenu {

public:
	MainMenu();

	int get_menu_selection();

	void create_new_account();

	void display_account_info();
};
