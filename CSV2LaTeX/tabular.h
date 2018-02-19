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
		vector<vector<string>> rawData;
		vector<vector<string>> formData;
		void buildFormData();
	public:
		enum style {
			SIMPLISTIC,
			FANCY
		};
		tabular();
		~tabular();
		//import data from csv
		void importData();
		//output data to a tex code snippit
		void exportData();
		//set a default style
		void setStyle();
		//default styles
};

#endif