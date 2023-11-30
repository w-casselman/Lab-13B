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

int main(void)
{
	cout << "Enter year: ";
	int year;
	cin >> year;

	cout << endl << isLeapYear(year) << endl;

	return 0;
}

bool isLeapYear(int year)
{
	if (year % 400 == 0) return true;
	if (year % 100 == 0) return false;
	if (year % 4 == 0) return true;
	return false;
}