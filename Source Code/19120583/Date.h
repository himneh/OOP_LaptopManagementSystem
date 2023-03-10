#pragma once
#include "SupeLib.h"

class Date {
private:
	int _year;
	int _month;
	int _day;

public:
	int getYear();
	int getMonth();
	int getDay();


	void setYear(int);
	void setMonth(int);
	void setDay(int);

	Date();
	Date(int, int, int);

	friend bool operator>(Date, Date);
	friend bool operator==(Date, Date);

	static Date parse(string);
	string toString();

	static Date getNow();

	~Date() {}
};