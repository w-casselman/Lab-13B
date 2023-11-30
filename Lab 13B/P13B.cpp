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
		cout << "Enter month and year: ";
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
	if (month == 1) return 31;
	if (month == 2)
	{
		if (isLeapYear(year)) return 29;
		return 28;
	}
	if (month == 3) return 31;
	if (month == 4) return 30;
	if (month == 5) return 31;
	if (month == 6) return 30;
	if (month == 7) return 31;
	if (month == 8) return 31;
	if (month == 9) return 30;
	if (month == 10) return 31;
	if (month == 11) return 30;
	if (month == 12) return 31;
}