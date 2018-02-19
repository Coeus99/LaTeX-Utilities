#ifndef __TABUAR__H__
#define __TABULAR__H__

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class tabular
{
	private:
		vector<vector<double>> raw_data;
		int maxRowSize = 256;
	public:
		tabular();
		~tabular();
		void importData();
		void exportData();
		void setStyle();
		void setMaxRowSize();
};

#endif