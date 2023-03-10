#include "Date.h"
#include "Tokenizer.h"

int Date::getYear() {
	return _year;
}

int Date::getMonth() {
	return _month;
}

int Date::getDay() {
	return _day;
}

void Date::setYear(int value) {
	_year = value;
}

void Date::setMonth(int value) {
	_month = value;
}

void Date::setDay(int value) {
	_day = value;
}

Date::Date() {
	setYear(1970);
	setMonth(1);
	setDay(1);
}

Date::Date(int month, int day, int year) {
	setYear(year);
	setMonth(month);
	setDay(day);
}

bool operator==(Date x, Date y) {
	if (x.getYear() != y.getYear()) {
		return false;
	}
	else {
		if (x.getMonth() != y.getMonth()) {
			return false;
		}
		else {
			if (x.getDay() != y.getDay()) {
				return false;
			}
			else {
				return true;
			}
		}
	}
}


bool operator>(Date x, Date y) {
	if (x.getYear() < y.getYear()) {
		return false;
	}
	else {
		if (x.getYear() > y.getYear())
			return true;
		else {
			if (x.getMonth() < y.getMonth()) {
				return false;
			}
			if (x.getMonth() > y.getMonth())
				return true;
			else {
				if (x.getDay() < y.getDay()) {
					return false;
				}
				if (x.getDay() > y.getDay())
					return true;
				else {
					if (x == y) return false;
					else
						return true;
				}
			}
		}

	}
}



Date Date::parse(string buffer) {
	vector<string> tokens = Tokenizer::split(buffer, " ");
	int month = stoi(tokens[0]);
	int day = stoi(tokens[1]);
	int year = stoi(tokens[2]);

	Date answer(month, day, year);
	return answer;
}

string Date::toString() {
	stringstream builder;
	builder << getMonth() << " " << getDay() << " " << getYear();
	string answer = builder.str();
	return answer;
}

Date Date::getNow() {
	time_t now = time(0);
	tm* ltm = localtime(&now);
	Date res;
	res.setYear(1900 + ltm->tm_year);
	res.setMonth(1 + ltm->tm_mon);
	res.setDay(ltm->tm_mday);

	return res;
}