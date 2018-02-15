/*
* Psuedocode:
* 
* Command line arugments: input file (csv)....
*      Info, headers, style,etc?
* Read amount of rows to determine size
*	keep track of most columns
* Dynamically allocate a 2D array of size row,col
* Check to made sure it was made
* Seekg to front of file and begin reading into array
*	(maybe get line then split into tokens by commas?)
*/

#include "tabular.h"

const int MENU_SIZE = 5;

enum MENU
{
	exit_program,
	import_data,
	export_data,
	change_style
};

const char MENU_TEXT[MENU_SIZE][100] =
{
	"",
	"1. Import Data",
	"2. Export Data",
	"3. Change Style",
	"0. Exit"
};

int main(int argc, char **argv)
{
	//Base "GUI Program"
	if (argc == 1)
	{
		tabular table;
		int choice = 0;

		//title screen
		cout << "===================" << endl;
		cout << "||   CSV2LaTeX   ||" << endl;
		cout << "===================" << endl;

		do
		{
			//print menu
			for (int i = 1; i < MENU_SIZE; i++)
				cout << MENU_TEXT[i] << endl;
			cout << endl;

			//take in menu choice
			cout << "Enter menu item: ";
			cin >> choice;
			cout << endl;

			//run code based on menu choice
			switch (choice)
			{
			case exit_program:
				cout << "Exiting program..." << endl;
				break;
			case import_data:
				table.importData();
				break;
			case export_data:
				table.exportData();
				break;
			case change_style:
				table.changeStyle();
				break;
			default:
				cout << "Invalid Choice." << endl << endl;
				break;
			}
			cout << endl << "-------------------" << endl << endl;
		} while (choice != exit_program);
	}
	return 0;
}