#pragma once
#include "SupeLib.h"

class Brand {
private:
	string _name;
public:
	Brand();
	void setName(string value);
	string getName();

	Brand(string);

	string toString();

	~Brand() {}
};