/*
	P13B
	Wesley Casselman
	November 30th of 2023
*/

#include <iostream>
#include <string>

using namespace std;

bool isLeapYear(int year);
/**
 isLeapYear � determines whether a given year is a leap year
 under the Gregorian calendar.
 @param year the year; expected to be >= 1582
 @return true if year is a leap year; false otherwise
*/

int daysInMonth(int month, int year);
/**
 daysInMonth � determines the number of days in a specified month
 @param month the month; expected to be in the range [1..12]
 @param year the year; expected to be >= 1582
 @return either 28, 29, 30, or 31, based on month and (leap) year
*/

int dayOfWeek(int month, int day, int year);
/**
 dayOfWeek - Computes the weekday of a given date.
 @param year the year
 @param month the month (1 = January ... 12 = December)
 @param day the day of the month
 @return the weekday (0 = Saturday ... 6 = Friday)
*/

void displayCalendar(int month, int year);

int main(void)
{
	while (true)
	{
		cout << "Enter a date or Q to quit: ";
		int month, year;
		cin >> month >> year;
		if (cin.fail()) break;

		displayCalendar(month, year);
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

int dayOfWeek(int month, int day, int year)
{
	int m;
	int Y;
	if (month <= 2)
	{
		m = month + 12;
		Y = year - 1;
	}
	else
	{
		m = month;
		Y = year;
	}
	return (day + int((m + 1) * 26 / 10) + Y + int(Y / 4) + 6 * int(Y / 100) + int(Y / 400)) % 7;
}

void displayCalendar(int month, int year)
{
	//                      Sa Fr Th We Tu Mo Su
	string calendar[6] = { "                   1  2  3  4  5  6  7 ",
						   " 2  3  4  5  6  7  8  9 10 11 12 13 14 ",
						   " 9 10 11 12 13 14 15 16 17 18 19 20 21 ",
						   "16 17 18 19 20 21 22 23 24 25 26 27 28 ",
						   "23 24 25 26 27 28 29 30 31             ",
						   "30 31                                  " };
	
	int weekday = dayOfWeek(month, 1, year);
	if (weekday == 0) weekday = 7;

	int num = 3 * (daysInMonth(month, year) + weekday - 1);

	cout << "Su Mo Tu We Th Fr Sa " << endl;
	for (int i = 0; i < 6; i++)
	{
		if (num >= 21)
		{
			cout << calendar[i].substr(3 * (7 - weekday), 21) << endl;
			num -= 21;
		}
		else
		{
			cout << calendar[i].substr(3 * (7 - weekday), num) << endl;
			break;
		}
	}
}