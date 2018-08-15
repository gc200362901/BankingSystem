#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Menu {

public:

	/*
		Takes in a vector of options for a menu and displays 
		them. Allows user to enter option choice and checks 
		if the choice is a valid integer.
		@return the users choice
	*/
	static int user_options(const vector<string> &options) {

		int user_choice;
		int count = 1;
		bool valid_choice = false;

		cout << "-------------------" << endl;
		for (string option : options) {
			cout << count << ": " << option << endl;
			count++;
		}
		cout << "\n" << endl;
		cout << "Select an option: \n" << endl;
		while (!(cin >> user_choice)) {
			cout << "Not a valid integer! \n" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Select an option: \n" << endl;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return user_choice;		
	}
};