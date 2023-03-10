#include "Bill.h"
#include "Tokenizer.h"

void Bill::setID(string value) {
	_ID = value;
}

void Bill::setDate(Date value) {
	_date = value;
}

void Bill::setNameCustomer(string value) {
	_nameCustomer = value;
}

void Bill::setPC(PC value) {
	_pc = value;
}

void Bill::setAmount(int data) {
	_amount = data;
}

void Bill::setCount(int data) {
	_count = data;
}

string Bill::getID() {
	return _ID;
}

Date Bill::getDate() {
	return _date;
}

string Bill::getNameCustomer() {
	return _nameCustomer;
}

PC Bill::getPC() {
	return _pc;
}

int Bill::getCount() {
	return _count;
}

int Bill::getAmount() {
	return _amount;
}

Bill::Bill() {
	setID("");
	//setDate("");
	setNameCustomer("");
	setAmount(0);
}

Bill::Bill(string id, Date date, string name, PC pc, int count, int k) {
	setID(id);
	setDate(date);
	setNameCustomer(name);
	setPC(pc);
	setCount(count);
	setAmount(k);
}

bool operator==(Bill a, Bill b) {
	if (a.getAmount() == b.getAmount() && a.getDate() == b.getDate() && a.getID() == b.getID() && a.getNameCustomer() == b.getNameCustomer()
		&& a.getCount() == b.getCount() && a.getPC() == b.getPC())
		return true;
	return false;
}

string Bill::toString() {
	stringstream builder;
	builder << getID() << " || " << getDate().toString() << " || " << getPC().getBrand().getName() << " " << getPC().getNamePC()
		<< " " << getPC().getCPU() << " " << getPC().getRAM() << " " << getPC().getHDD() << " " <<
		getPC().getSSD() << " " << getPC().getPrice() << " || " << getNameCustomer() << " || " << getCount() << " || " << getAmount();
	string res = builder.str();
	return res;
}

string Bill::toWrite() {
	stringstream builder;
	builder << getID() << " || " << getDate().toString() << " || " << getNameCustomer() << " || "
		<< getPC().toWrite() << " || " << getCount() << " || " << getAmount();
	string res = builder.str();
	return res;
}

Bill Bill::parse(string buffer) {
	vector<string> tokens = Tokenizer::split(buffer, " || ");
	string id = tokens[0];
	string date_tmp = tokens[1];
	Date date = Date::parse(date_tmp);
	string name = tokens[2];

	string pc_tmp = tokens[3];
	PC pc = PC::parse(pc_tmp);
	int count = stoi(tokens[4]);
	int amount = stoi(tokens[5]);
	Bill answer(id, date, name, pc, count, amount);
	return answer;
}