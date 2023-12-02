/*
	P13B
	Wesley Casselman
	November 30th of 2023
*/

#include <iostream>

using namespace std;

bool isLeapYear(int year);
/**
 isLeapYear – determines whether a given year is a leap year
 under the Gregorian calendar.
 @param year the year; expected to be >= 1582
 @return true if year is a leap year; false otherwise
*/

int daysInMonth(int month, int year);
/**
 daysInMonth – determines the number of days in a specified month
 @param month the month; expected to be in the range [1..12]
 @param year the year; expected to be >= 1582
 @return either 28, 29, 30, or 31, based on month and (leap) year
*/

int main(void)
{
	while (true)
	{
		cout << "Enter year: ";
		int month, year;
		cin >> month >> year;
		if (cin.fail()) break;

		cout << endl << daysInMonth(month, year) << endl;
	}

	return 0;
}

bool isLeapYear(int year)
{
	if (year % 400 == 0) return true;
	if (year % 100 == 0) return false;
	if (year % 4 == 0) return true;
	return false;
}

int daysInMonth(int month, int year)
{
	switch (month)
	{
	case  2: if (isLeapYear(year)) { return 29; }
		   else { return 28; }
	case  4: return 30;
	case  6: return 30;
	case  9: return 30;
	case 11: return 30;
	default: return 31;
	}
}