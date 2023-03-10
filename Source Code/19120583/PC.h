#pragma once
#include "SupeLib.h"
#include "Brand.h"

class PC {
private:
	string _namePC;
	int _price;
	Brand _brand;
	string _CPU;
	int _RAM;
	int _HDD;
	int _SSD;
	int _quantity;
	int _cost;

public:
	PC();

	void setNamePC(string);
	void setPrice(int);
	void setBrand(Brand);
	void setCPU(string);
	void setRAM(int);
	void setHDD(int);
	void setSSD(int);
	void setCost(int);
	void setQuantity(int);

	string getNamePC();
	int getPrice();
	Brand getBrand();
	string getCPU();
	int getRAM();
	int getSSD();
	int getHDD();
	int getCost();
	int getQuantity();


	PC(Brand, string, string, int, int, int, int, int, int);

	static PC parse(string buffer);

	friend bool operator==(PC, PC);

	string toString();
	string toWrite();
};