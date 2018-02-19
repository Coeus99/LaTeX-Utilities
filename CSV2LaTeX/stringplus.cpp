/******************************************************************************
* Name: Grosz, Logan
* ID: 7408481
* Section: M002
* Homework 7
*****************************************************************************/

#include "stringplus.h"
void trimString(string &s, char method)
{
	method = tolower(method);
	bool metChar; //helps drop out of while loop once a non space character is found
	bool isAllSpace = true;
	int i; //just a integer for counting since I cannot use algos library
	
	//if the string is empty, return it
	if (s.empty())
		return;

	//may be able to integrate into if statements below, but this works and is readable
	//if the string is all spaces, clear it then return it;
	for (unsigned int j = 0; j < s.size() && isAllSpace; j++)
	{
		if (!isspace(s.at(j)))
			isAllSpace = false;

	}
	if (isAllSpace)
	{
		s.clear();
		return;
	}

	//trim front end
	if (method == 'b' || method == 'f')
	{
		metChar = false;
		i = 0;
		//trim front of strings
		while (!metChar)
		{
			//counts spaces, then erases up to that point
			if (isspace(s.at(i)))
				i++;

			else
			{
				//iterator erase
				s.erase(s.begin(),s.begin()+i);
				metChar = true;
			}
		}
	}
	if (method == 'b' || method == 'e')
	{
		metChar = false;
		i = 0;
		//trim front of strings
		while (!metChar)
		{
			//counts spaces, then erases up to that point
			//need - 1 because .size() is not a valid index
			if (isspace(s.at(s.size() - 1 - i)))
			{
				i++;
			}
			else
			{
				//iterator erase
				//tried using reverse iterators, but .erase didn't like them
				s.erase(s.end() - i, s.end());
				metChar = true;
			}
		}
	}
	if (method != 'b' || method != 'f' || method != 'e')
		return;
}

void extractStringNames(string fullname, string &first, string &middle, string &last)
{
	int found;
	unsigned int i;

	//prep the string
	trimString(fullname, 'b');

	//check if , is in string
	found = fullname.find(',');

	//if comma is in string
	//fullname is Last, First or Last, First Middle
	if (found != string::npos)
	{
		i = 0;
		//check until found spaces (will be after comma)
		while (!isspace(fullname.at(i)))
			i++;

		//first is until i, minus the comma
		last = fullname.substr(0, i-1);

		//erase until the comma then trim
		fullname.erase(0, i);
		trimString(fullname, 'b');
		i = 0;
		//while its not a space and i is a valid index, increment i
		//need -1 because if middle doesn't exist, this is off the string
		while (!isspace(fullname.at(i)) && i < fullname.size() - 1)
			i++;

		//first is from position 0 through and including i
		first = fullname.substr(0, i + 1);
		//middle term may have some spaces in them
		trimString(first, 'b');
		fullname.erase(0,i+1);

		//If fullname is not empty, get middle name
		trimString(fullname, 'b');
		if (!fullname.empty())
			middle = fullname;
	}
	else
	{
		i = 0;
		//until there's a space, this is the first name
		while (!isspace(fullname.at(i)))
			i++;

		first = fullname.substr(0, i);
		trimString(first, 'b');

		//erase and trim so its easier to analyze
		fullname.erase(0,i);
		trimString(fullname, 'b');

		//reset counter
		i = 0;
		//need the -1 because this may be the last argument
		while (!isspace(fullname.at(i)) && i < fullname.size() - 1)
			i++;

		//Will assume its middle until proven otherwise
		middle = fullname.substr(0, i + 1);
		trimString(middle, 'b');

		//erase fullname so its easy to get last name
		fullname.erase(0, i + 1);
		trimString(fullname, 'b');

		//if the fullname is now empty, the last argument was the last name
		//and there is no middle name
		if (fullname.empty())
		{
			last = middle;
			middle.clear();
			return;
		}

		//the last are the remaining characters
		last = fullname;
	}
}