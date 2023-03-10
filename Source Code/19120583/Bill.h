#pragma once
#include "Date.h"
#include "PC.h"


class Bill {
private:
	string _ID;
	Date _date;
	string _nameCustomer;
	PC _pc;
	int _count;
	int _amount;
public:
	void setID(string);
	void setDate(Date);
	void setNameCustomer(string);
	void setPC(PC);
	void setCount(int);
	void setAmount(int);

	string getID();
	Date getDate();
	string getNameCustomer();
	PC getPC();
	int getCount();
	int getAmount();

	Bill();
	Bill(string, Date, string, PC, int, int);
	//friend ostream& operator<<(ostream& out, Bill bill);
	friend bool operator==(Bill, Bill);
	string toString();
	string toWrite();
	static Bill parse(string buffer);

	~Bill() {}
};