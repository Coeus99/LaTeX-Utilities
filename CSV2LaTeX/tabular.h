#ifndef __TABUAR__H__
#define __TABULAR__H__

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class tabular
{
	private:
	vector<vector<double>> raw_data;
	public:
	void importData()
	{
		cout << "Data imported" << endl;
		return;
	}
	void exportData()
	{
		cout << "Data exported." << endl;
		return;
	}
	void changeStyle()
	{
		cout << "Style changed." << endl;
		return;
	}
};

#endif