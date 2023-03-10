#include "PC.h"
#include "Tokenizer.h"

void PC::setNamePC(string value) {
	_namePC = value;
}

void PC::setPrice(int value) {
	_price = value;
}

void PC::setBrand(Brand brand) {
	_brand = brand;
}

void PC::setCPU(string value) {
	_CPU = value;
}

void PC::setRAM(int value) {
	_RAM = value;
}

void PC::setHDD(int value) {
	_HDD = value;
}

void PC::setSSD(int value) {
	_SSD = value;
}

void PC::setCost(int value) {
	_cost = value;
}

void PC::setQuantity(int value) {
	_quantity = value;
}

string PC::getNamePC() {
	return _namePC;
}

int PC::getPrice() {
	return _price;
}

Brand PC::getBrand() {
	return _brand;
}

string PC::getCPU() {
	return _CPU;
}

int PC::getRAM() {
	return _RAM;
}

int PC::getSSD() {
	return _SSD;
}

int PC::getHDD() {
	return _HDD;
}

int PC::getCost() {
	return _cost;
}

int PC::getQuantity() {
	return _quantity;
}

PC::PC() {
	_namePC = "";
	_price = 0;
	_CPU = "";
	_RAM = 0;
	_HDD = 0;
	_SSD = 0;
	_cost = 0;
	_quantity = 0;
}

PC::PC(Brand brand, string name, string CPU, int RAM, int HDD, int SSD, int cost, int price, int quantity) {
	PC::setBrand(brand);
	PC::setNamePC(name);
	PC::setCPU(CPU);
	PC::setRAM(RAM);
	PC::setHDD(HDD);
	PC::setSSD(SSD);
	PC::setPrice(price);
	PC::setCost(cost);
	PC::setQuantity(quantity);
}

PC PC::parse(string buffer) {
	vector<string> tokens = Tokenizer::split(buffer, "; ");
	string tam = tokens[0];
	Brand brandd(tam);
	string namee = tokens[1];
	string cpuu = tokens[2];
	int ramm = stoi(tokens[3]);
	int hddd = stoi(tokens[4]);
	int ssdd = stoi(tokens[5]);
	int costt = stoi(tokens[6]);
	int pricee = stoi(tokens[7]);
	int quantityy = stoi(tokens[8]);

	PC answer(brandd, namee, cpuu, ramm, hddd, ssdd, costt, pricee, quantityy);
	return answer;
}

bool operator==(PC x, PC y) {
	if (x.getBrand().toString() == y.getBrand().toString() && x.getCPU() == y.getCPU() &&
		x.getHDD() == y.getHDD() && x.getNamePC() == x.getNamePC() && x.getPrice() == y.getPrice()
		&& x.getRAM() == y.getRAM() && x.getSSD() == y.getSSD() && x.getCost() == y.getCost())
		return true;
	return false;
}

string PC::toString() {
	stringstream builder;
	string tmp = PC::getBrand().toString();
	builder << tmp << " " << PC::getNamePC() << "; CPU: " << PC::getCPU() << "; RAM: " << PC::getRAM() << "GB; HDD: "
		<< PC::getHDD() << "GB; SSD: " << PC::getSSD() << "GB; Price: " << PC::getPrice()
		<< "$";
	string ans = builder.str();
	return ans;
}

string PC::toWrite() {
	stringstream builder;
	string tmp = PC::getBrand().toString();
	builder << tmp << "; " << PC::getNamePC() << "; " << PC::getCPU() << "; " << PC::getRAM() << "; "
		<< PC::getHDD() << "; " << PC::getSSD() << "; " << PC::getCost() << "; " << PC::getPrice()
		<< "; " << PC::getQuantity();
	string ans = builder.str();
	return ans;
}