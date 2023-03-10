#include "Manage.h"

vector<Brand> Manage::getLaptopBrands() {
	return LaptopBrands;
}

vector<PC> Manage::getLaptops() {
	return laptops;
}

vector<Bill> Manage::getBills() {
	return bills;
}

void Manage::setLaptopBrands(vector<Brand> value) {
	LaptopBrands.swap(value);
}

void Manage::setLaptops(vector<PC> value) {
	laptops.swap(value);
}

void Manage::setBills(vector<Bill> value) {
	bills.swap(value);
}

void Manage::viewBrand() {
	gotoxy(28, 12); cout << "------------Danh sach cac hang laptop------------";
	for (int i = 0; i < LaptopBrands.size(); i++) {
		gotoxy(45, i + 13);
		cout << LaptopBrands[i].toString();
	}
}

int Manage::checkBrand(Brand value) {
	for (int i = 0; i < LaptopBrands.size(); i++)
		if (LaptopBrands[i].getName().compare(value.getName()) == 0) //Kiểm tra trùng lặp
			return i;
	return -1;
}

bool Manage::addBrand(string value) {
	Brand tmp;
	tmp.setName(value);
	if (checkBrand(tmp) == -1) {
		LaptopBrands.push_back(tmp);
		return true;
	}
	else {
		gotoxy(45, 12);
		cout << "Failed when adding " << tmp.getName() << " (because of duplicate)\n";
		return false;
	}
}

bool Manage::deleteBrand(Brand valuee) {
	int res = checkBrand(valuee);
	if (res == -1)
		return false;
	else {
		LaptopBrands.erase(LaptopBrands.begin() + res);
		return true;
	}
}

bool Manage::changeBrand(Brand brand_tmp, string new_name) {
	string valuee = brand_tmp.getName();
	Brand new_brand;
	new_brand.setName(new_name);
	int res = checkBrand(valuee);
	if (res == -1)
		return false;
	else {
		LaptopBrands.erase(LaptopBrands.begin() + res);
		LaptopBrands.insert(LaptopBrands.begin() + res, new_brand);
		return true;
	}
}

void Manage::viewLaptop() {
	gotoxy(28, 12); cout << "------------Danh sach cac laptop------------";
	gotoxy(28, 13); cout << "Ten may";
	gotoxy(63, 13); cout << "CPU";
	gotoxy(78, 13); cout << "RAM (GB)";
	gotoxy(93, 13); cout << "HDD (GB)";
	gotoxy(108, 13); cout << "SSD (GB)";
	gotoxy(123, 13); cout << "Gia (USD)";
	gotoxy(148, 13); cout << "So luong (Cai)";

	int j = 14;
	for (int i = 0; i < laptops.size(); i++)
	{
		gotoxy(25, j);
		cout << 1 + i;
		gotoxy(28, j);
		cout << laptops[i].getBrand().getName() << " " << laptops[i].getNamePC();

		gotoxy(60, j); cout << "||";
		gotoxy(63, j);
		cout << laptops[i].getCPU();

		gotoxy(75, j); cout << "||";
		gotoxy(78, j);
		cout << laptops[i].getRAM();

		gotoxy(90, j); cout << "||";
		gotoxy(93, j);
		cout << laptops[i].getHDD();

		gotoxy(105, j); cout << "||";
		gotoxy(108, j);
		cout << laptops[i].getSSD();

		gotoxy(120, j); cout << "||";
		gotoxy(123, j);
		cout << laptops[i].getPrice();

		gotoxy(145, j); cout << "||";
		gotoxy(148, j);
		cout << laptops[i].getQuantity();

		j++;
	}
}

void Manage::viewLaptop(Brand brand) {
	gotoxy(28, 12); cout << "------------Danh sach cac laptop------------";
	gotoxy(28, 13); cout << "Ten may";
	gotoxy(63, 13); cout << "CPU";
	gotoxy(78, 13); cout << "RAM (GB)";
	gotoxy(93, 13); cout << "HDD (GB)";
	gotoxy(108, 13); cout << "SSD (GB)";
	gotoxy(123, 13); cout << "Gia (USD)";
	gotoxy(148, 13); cout << "So luong (Cai)";
	string namee = brand.getName();
	int j = 14;
	for (int i = 0; i < laptops.size(); i++)
		if (laptops[i].getBrand().getName() == namee)
		{
			gotoxy(28, j);
			cout << laptops[i].getBrand().getName() << " " << laptops[i].getNamePC();

			gotoxy(60, j); cout << "||";
			gotoxy(63, j);
			cout << laptops[i].getCPU();

			gotoxy(75, j); cout << "||";
			gotoxy(78, j);
			cout << laptops[i].getRAM();

			gotoxy(90, j); cout << "||";
			gotoxy(93, j);
			cout << laptops[i].getHDD();

			gotoxy(105, j); cout << "||";
			gotoxy(108, j);
			cout << laptops[i].getSSD();

			gotoxy(120, j); cout << "||";
			gotoxy(123, j);
			cout << laptops[i].getPrice();

			gotoxy(145, j); cout << "||";
			gotoxy(148, j);
			cout << laptops[i].getQuantity();

			j++;
		}
}

int Manage::checkLaptop(PC pc) {
	for (int i = 0; i < laptops.size(); i++) {
		if (laptops[i] == pc)
			return i;
	}
	return -1;
}

bool Manage::addLaptop(PC pc) {
	if (checkLaptop(pc) == -1) {
		laptops.push_back(pc);
		return true;
	}
	cout << "Failed when adding PC!\n";
	return false;
}

bool Manage::deleteLaptop(PC valuee) {
	int res = checkLaptop(valuee);
	if (res == -1)
		return false;
	else {
		laptops.erase(laptops.begin() + res);
		return true;
	}
}

void Manage::changePCBrand(PC& pc, string str) {
	Brand tmp(str);
	if (checkBrand(tmp) == -1) {
		LaptopBrands.push_back(tmp);
	}
	for (int i = 0; i < laptops.size(); i++)
		if (laptops[i] == pc)
			laptops[i].setBrand(tmp);
}

void Manage::changePCName(PC& pc, string str) {
	for (int i = 0; i < laptops.size(); i++)
		if (laptops[i] == pc)
			laptops[i].setNamePC(str);
}

void Manage::changePCcpu(PC& pc, string str) {
	for (int i = 0; i < laptops.size(); i++)
		if (laptops[i] == pc)
			laptops[i].setCPU(str);
}

void Manage::changePCram(PC& pc, int k) {
	for (int i = 0; i < laptops.size(); i++)
		if (laptops[i] == pc)
			laptops[i].setRAM(k);
}
void Manage::changePChdd(PC& pc, int k) {
	for (int i = 0; i < laptops.size(); i++)
		if (laptops[i] == pc)
			laptops[i].setHDD(k);
}

void Manage::changePCssd(PC& pc, int k) {
	for (int i = 0; i < laptops.size(); i++)
		if (laptops[i] == pc)
			laptops[i].setSSD(k);
}

void Manage::changePCprice(PC& pc, int k) {
	for (int i = 0; i < laptops.size(); i++)
		if (laptops[i] == pc)
			laptops[i].setPrice(k);
}

void Manage::changePCcost(PC& pc, int k) {
	for (int i = 0; i < laptops.size(); i++)
		if (laptops[i] == pc)
			laptops[i].setCost(k);
}

void Manage::changePCquantity(PC& pc, int k) {
	for (int i = 0; i < laptops.size(); i++)
		if (laptops[i] == pc)
			laptops[i].setQuantity(k);
}

bool Manage::createBill(Bill now) {
	Bill tmp;
	if (sortBill(now)) {
		if (bills.size() == 0) {
			bills.push_back(now);
			return true;
		}
		tmp.setDate(Date::getNow());
		bills.push_back(tmp);

		Date x = now.getDate();
		for (int i = 0; i < bills.size() - 1; i++) {
			Date y = bills[i].getDate();
			if (x == y) {
				bills.insert(bills.begin() + i, now);
				return true;
			}
			else {
				if (y > x) {
					bills.insert(bills.begin() + i, now);
					bills.pop_back();
					return true;
				}
				else {
					Date z = bills[i + 1].getDate();
					if (x > y && z > x) {
						bills.insert(bills.begin() + i + 1, now);
						bills.pop_back();
						return true;
					}
				}
			}
		}
		bills.pop_back();
		return false;
	}
}

void Manage::setQuantity4PC(int tmp, PC value) {
	for (int i = 0; i < laptops.size(); i++) {
		if (value == laptops[i]) {
			int res = laptops[i].getQuantity();
			if (tmp > res) {
				cout << "\nOut of Product!";
			}
			else {
				res -= tmp;
				laptops[i].setQuantity(res);
			}
		}
	}
}

bool Manage::sortBill(Bill& value) {
	for (int i = 0; i < laptops.size(); i++) {
		if (value.getPC() == laptops[i]) {
			int tmp = value.getCount();
			int res = laptops[i].getQuantity();
			if (tmp > res) {
				cout << "\nOut of Product!";
				return false;
			}
			else {
				res -= tmp;
				laptops[i].setQuantity(res);
				return true;
			}
		}
	}
	return false;

	/*setQuantity4PC(value.getCount(), value.getPC());
	return true;*/
}

void Manage::viewBills(int start, int finish) {
	gotoxy(20, 9); cout << "Ma don hang";
	gotoxy(35, 9); cout << "Thoi gian";
	gotoxy(50, 9); cout << "Tong don";
	int j = 10;
	for (int i = start; i < finish; i++) {
		gotoxy(20, j);
		cout << bills[i].getID();
		gotoxy(32, j);
		cout << "||";
		gotoxy(35, j);
		cout << bills[i].getDate().getMonth() << " " << bills[i].getDate().getDay() << " " << bills[i].getDate().getYear();
		gotoxy(47, j);
		cout << "||";
		gotoxy(50, j);
		cout << bills[i].getAmount();
		j++;
	}
}
void Manage::viewBill(string value) {
	//xem danh sách đơn hàng
	gotoxy(5, 10); cout << "Ma don";
	gotoxy(15, 10); cout << "Thoi gian";
	gotoxy(30, 10); cout << "Ten khach hang";
	gotoxy(50, 10); cout << "Ten laptop";
	gotoxy(145, 10); cout << "So luong mua";
	gotoxy(160, 10); cout << "Tong don";
	for (int i = 0; i < bills.size(); i++) {
		if (bills[i].getID() == value) {
			gotoxy(5, 11);
			cout << bills[i].getID();

			gotoxy(12, 11); cout << "||";

			gotoxy(15, 11);
			cout << bills[i].getDate().toString();

			gotoxy(27, 11); cout << "||";
			gotoxy(30, 11);
			cout << bills[i].getNameCustomer();

			gotoxy(47, 11); cout << "||";
			gotoxy(50, 11);
			cout << bills[i].getPC().toString();

			gotoxy(142, 11); cout << "||";
			gotoxy(145, 11);
			cout << bills[i].getCount();

			gotoxy(157, 11); cout << "||";
			gotoxy(160, 11);
			cout << bills[i].getAmount();

			break;
		}
	}
}

int Manage::checkBill(Bill value) {
	//check một đơn hàng có tổn tại hay không
	for (int i = 0; i < bills.size(); i++)
		if (bills[i].getID() == value.getID())
			return i;
	return -1;
}

void Manage::addBill(Bill data) {
	//thêm 1 đơn hàng vào danh sách 
	if (checkBill(data)) {
		bills.push_back(data);
		cout << "Success\n";
	}
	else cout << "failed\n";
}

bool Manage::deleteBill(string valuee) {
	//xóa 1 đơn hàng ra khỏi danh sách
	Bill crc;
	crc.setID(valuee);
	int res = checkBill(crc);
	if (res == -1)
		return false;
	else {
		bills.erase(bills.begin() + res);
		return true;
	}
}

bool Manage::updateBill(string valuee, Bill data) {
	//chỉnh sửa 1 đơn hàng
	Bill crc;
	crc.setID(valuee);
	int res = checkBill(crc);
	if (res == -1)
		return false;
	else {
		bills.erase(bills.begin() + res);
		bills.insert(bills.begin() + res, data);
		return true;
	}
}

void Manage::PCrunningout(int k) {
	gotoxy(15, 9); cout << "------------Danh sach cac laptop sap het------------";
	gotoxy(15, 10); cout << "Ten may";
	gotoxy(50, 10); cout << "CPU";
	gotoxy(65, 10); cout << "RAM (GB)";
	gotoxy(80, 10); cout << "HDD (GB)";
	gotoxy(95, 10); cout << "SSD (GB)";
	gotoxy(110, 10); cout << "Gia (USD)";
	gotoxy(135, 10); cout << "So luong (Cai)";
	int j = 11;
	for (int i = 0; i < laptops.size(); i++)
		if (laptops[i].getQuantity() < k) {

			gotoxy(15, j);
			cout << laptops[i].getBrand().getName() << " " << laptops[i].getNamePC();

			gotoxy(47, j); cout << "||";
			gotoxy(50, j);
			cout << laptops[i].getCPU();

			gotoxy(62, j); cout << "||";
			gotoxy(65, j);
			cout << laptops[i].getRAM();

			gotoxy(73, j); cout << "||";
			gotoxy(80, j);
			cout << laptops[i].getHDD();

			gotoxy(92, j); cout << "||";
			gotoxy(95, j);
			cout << laptops[i].getSSD();

			gotoxy(107, j); cout << "||";
			gotoxy(110, j);
			cout << laptops[i].getPrice();

			gotoxy(132, j); cout << "||";
			gotoxy(135, j);
			cout << laptops[i].getQuantity();

			j++;
		}
}

int Manage::getRevenue(int mon, int yeh) {
	int res = 0;
	for (int i = 0; i < getBills().size(); i++) {
		if (getBills()[i].getDate().getMonth() == mon && getBills()[i].getDate().getYear() == yeh)
			res += getBills()[i].getAmount();
	}
	return res;
}

int Manage::getProfit(int mon, int yeh) {
	int res = 0;
	int ans = 0;
	for (int i = 0; i < getBills().size(); i++) {
		if (getBills()[i].getDate().getMonth() == mon && getBills()[i].getDate().getYear() == yeh) {
			ans = ans + getBills()[i].getPC().getCost() * getBills()[i].getCount();
		}
	}
	res = getRevenue(mon, yeh) - ans;
	return res;
}

void Manage::getHotDeal() {
	int value1 = Date::getNow().getMonth() - 1;
	int value2 = Date::getNow().getYear();
	int count = 0;
	int sum = 0;
	for (int i = 0; i < getBills().size(); i++) {
		if (getBills()[i].getDate().getMonth() == value1 && getBills()[i].getDate().getYear() == value2) {
			sum += getBills()[i].getCount();
			count++;
		}
	}

	if (count == 0)
	{
		gotoxy(5, 8);
		cout << "Khong co san pham nao!";
	}
	else {
		gotoxy(15, 8); cout << "-----------Danh sach san pham ban chay thang truoc-----------";
		gotoxy(15, 9); cout << "Ten may";
		gotoxy(50, 9); cout << "CPU";
		gotoxy(65, 9); cout << "RAM (GB)";
		gotoxy(80, 9); cout << "HDD (GB)";
		gotoxy(95, 9); cout << "SSD (GB)";
		gotoxy(110, 9); cout << "Gia (USD)";
		gotoxy(135, 9); cout << "So luong (Cai)";
		int ans = sum / count;
		int j = 10;
		for (int i = 0; i < getBills().size(); i++) {
			if (getBills()[i].getDate().getMonth() == value1 && getBills()[i].getDate().getYear() == value2
				&& getBills()[i].getCount() >= ans) {

				gotoxy(15, j);
				cout << bills[i].getPC().getBrand().getName() << " " << bills[i].getPC().getNamePC();

				gotoxy(47, j); cout << "||";
				gotoxy(50, j);
				cout << bills[i].getPC().getCPU();

				gotoxy(62, j); cout << "||";
				gotoxy(65, j);
				cout << bills[i].getPC().getRAM();

				gotoxy(73, j); cout << "||";
				gotoxy(80, j);
				cout << bills[i].getPC().getHDD();

				gotoxy(92, j); cout << "||";
				gotoxy(95, j);
				cout << bills[i].getPC().getSSD();

				gotoxy(107, j); cout << "||";
				gotoxy(110, j);
				cout << bills[i].getPC().getPrice();

				gotoxy(132, j); cout << "||";
				gotoxy(135, j);
				cout << bills[i].getCount();

				j++;
			}
		}
	}
}