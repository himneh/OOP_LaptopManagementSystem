#include "Brand.h"


void Brand::setName(string value) {
	_name = value;
}

string Brand::getName() {
	return _name;
}

Brand::Brand() {
	_name = "";
}

Brand::Brand(string value) {
	Brand::setName(value);
}

string Brand::toString() {
	string ans = Brand::getName();
	return ans;
}