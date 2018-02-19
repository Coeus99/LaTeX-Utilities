#include "tabular.h"
#include "stringplus.h"

tabular::tabular()
{

}

tabular::~tabular()
{

}

void tabular::importData()
{
	ifstream fin;
	string row;
	string tempString;
	vector<string> tempRow;
	int commaPos;
	char filename[255];

	//ask for file to input from
	cout << "File to transfer: " << endl;
	cin >> filename;

	//open and check for validation
	fin.open(filename);
	if (!fin.is_open())
	{
		fin.close();
		cout << "Failed to open file " << filename;
		return;
	}

	//read in lines and do stuff with them
	while (getline(fin, row, '\n'))
	{
		//find position of next comma
		commaPos = row.find(',');
		while (commaPos != string::npos)
		{
			tempString = row.substr(0,commaPos);
			//get rid of whitespace
			trimString(tempString, 'b');
			tempRow.push_back(tempString);
			row.erase(row.begin(), row.begin() + commaPos + 1);
			commaPos = row.find(',');
		}
		//get rid of whitespace
		trimString(row, 'b');
		tempRow.push_back(row);
		for (int i = 0; i < tempRow.size(); i++)
		{
			cout << tempRow.at(i) << " ";
		}
		cout << endl;
		tempRow.clear();
	}

	fin.close();
}

void tabular::exportData()
{
	ifstream fout;
	char filename[255];

	cout << "Output to file: " << endl;
	cin >> filename;

	fout.open(filename);

	if (!fout.is_open())
	{
		fout.close();
		cout << "Failed to open file " << filename;
		return;
	}

	//do output stuff here

	fout.close();
}

void tabular::setStyle()
{

}

void tabular::setMaxRowSize()
{

}