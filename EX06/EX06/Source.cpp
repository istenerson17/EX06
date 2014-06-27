#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <sstream>
#include "Circle.h"
#include "Complex.h"
using namespace std;

string chooseFile(int &year);
string formFile(int year);

int main()
{
	srand(time(NULL));
	//EX06_01 – 13.1: Create a text file-Complete

	string filename1 = "c:\\users\\Ian\\Desktop\\Exercise13_1.txt";
	ofstream fout;
	ifstream fin;

	fout.open(filename1);

	if (fout.fail())
	{
		cout << "can't open file" << endl;
		return 0;
	}
	
	int random;
	for (int i = 0; i < 100; i++)
	{
		random = rand() % 100;
		fout << random << " ";
	}
	fout.close();

	//EX06_02 – 13.2: Count characters-Complete
	string filename2 = "C:\\Users\\Ian\\CS172\\Jabberwocky.txt"; // I designed this to run on my computer, so this does in fact work
	string text;
	fstream file(filename2.c_str(), ios::in | ios::out);

	int sum = 0;
	char Antichar = ' ';	
	
	while (file >> Antichar)
	{
		sum++;
	}
	cout << "This file contains " << sum << " characters." << endl << endl;
	file.close();

	//EX06_03 – 13.5: Baby names-Complete
	void getInfo(int &year, char &gender, string &name);
	string chooseFile(int &year);
	string formFile(int year);

	int year;
	char gender;
	string name;
	cout << "What year would you like to check?" << endl;
	cin >> year;
	cout << "What gender would you like to check? M or F" << endl;
	cin >> gender;
	cout << "What name would you like to check?" << endl;
	cin >> name;

	string filename = chooseFile(year);

	fstream babyfile("C:\\Users\\Ian\\Documents\\CS172\\" + filename, ios::in);

	if (!file)
	{			
		cout << "Can't open the file. Baby." << endl << endl;
	}

	string line;
	string findName;
	int count = 0;
	int rank = 0;
	while (getline(babyfile, line))
	{
		count++;
		int tab1 = line.find('\t');
		int tab2 = line.find('\t', tab1 + 1);
		int tab3 = line.find('\t', tab2 + 1);
		int tab4 = line.find('\t', tab3 + 1);

		string MName = (line.substr(tab1 + 1, tab2 - tab1 - 1));
		string FName = (line.substr(tab3 + 1, tab4 - tab3 - 1));

		switch (gender)
		{
		case 'M':
		case 'm':
			if (MName == name)
			{
				rank = count;
			}
		case 'F':
		case 'f':
			if (FName == name)
			{
					rank = count;
			}
		}
	}
	file.clear();
	file.close();

	if (rank != 0)
		cout << name << " is ranked #" << rank << " in the year " << year << " ." << endl << endl;
	else
		cout << name << " is not ranked at all for the year of " << year << "." << endl << endl;
	
	//EX06_04 – 14.3: The Circle class-Complete
	Circle c1(4), c2(4);
	if (c1 == c2)
	{
		cout << "Test Succeeded" << endl;
	}
	else
		cout << "Test Failed" << endl;

	Circle c3(5), c4(1);
	c3 = c4;
	if (c3 == c4)
	{
		cout << "Test Succeeded" << endl;
	}
	else
		cout << "Test Failed" << endl;

	Circle c5;
	c5 = ((c4 + c3) + (c2 + c1));
	cout << "Radius: " << c5.getRadius() << endl;

	//EX06_05 – 14.7: Math : The Complex class-Complete
	double a, b, c, d;
	cout << "Enter the first complex number: ";
	cin >> a;
	cin >> b;
	cout << "Enter the second complex number: ";
	cin >> c;
	cin >> d;

	Complex Comp1(a, b), Comp2(c, d);
	cout << Comp1 << " + " << Comp2 << " = " << (Comp1 + Comp2) << endl;
	cout << Comp1 << " - " << Comp2 << " = " << (Comp1 - Comp2) << endl;
	cout << Comp1 << " * " << Comp2 << " = " << (Comp1 * Comp2) << endl;
	cout << Comp1 << " / " << Comp2 << " = " << (Comp1 / Comp2) << endl;
	cout << "|" << Comp1 << "| = " << Comp1.Abs() << endl;
}

string chooseFile(int &year)
{
	string filename;
	switch (year){
	case 2013:
	case 2012:
	case 2011:
	case 2010:
	case 2009:
	case 2008:
	case 2007:
	case 2006:
	case 2005:
	case 2004:
	case 2003:
	case 2002:
	case 2001:
	case 2000:
		filename = formFile(year);
	}
	return filename;
}

string formFile(int year)
{
	string txt = ".txt";
	stringstream conv;
	conv << year;
	string Year = conv.str();
	string txtyear = Year;
	return (txtyear + txt);
}
