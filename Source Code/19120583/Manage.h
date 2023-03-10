#pragma once
#include "SupeLib.h"
#include "Bill.h"
#include "Brand.h"
#include "PC.h"
#include "Date.h"

class Manage {
private:
	vector<Brand> LaptopBrands;
	vector<PC> laptops;
	vector<Bill> bills;
public:
	vector<Brand> getLaptopBrands();
	vector<PC> getLaptops();
	vector<Bill> getBills();

	void setLaptopBrands(vector<Brand>);
	void setLaptops(vector<PC>);
	void setBills(vector<Bill>);

	void setQuantity4PC(int, PC);

	bool createBill(Bill);
	void viewBill(string);//xem danh sách đơn hàng
	bool sortBill(Bill&);
	void viewBills(int, int);
	int checkBill(Bill);//check một đơn hàng có tổn tại hay không
	void addBill(Bill);//thêm 1 đơn hàng vào danh sách 
	bool deleteBill(string);//xóa 1 đơn hàng ra khỏi danh sách
	bool updateBill(string, Bill);//chỉnh sửa 1 đơn hàng

	void viewBrand(); //Xem danh sách tên hãng làm laptop
	int checkBrand(Brand); //Kiểm tra một hãng đã có trong danh sách hay chưa, nếu có trả ra vị trí, ngược lại trả về -1
	bool addBrand(string value); //Thêm một hãng vào danh sách
	bool deleteBrand(Brand); // Xóa một hãng ra khỏi danh sách
	bool changeBrand(Brand, string); //Chỉnh sửa một hãng trong danh sách

	void viewLaptop(); // Xem danh sách laptop
	void viewLaptop(Brand);
	int checkLaptop(PC);
	bool addLaptop(PC);
	bool deleteLaptop(PC);
	void changePCBrand(PC&, string);
	void changePCName(PC&, string);
	void changePCcpu(PC&, string);
	void changePCram(PC&, int);
	void changePChdd(PC&, int);
	void changePCssd(PC&, int);
	void changePCprice(PC&, int);
	void changePCcost(PC&, int);
	void changePCquantity(PC&, int);


	void PCrunningout(int);
	void getHotDeal();
	int getRevenue(int, int);
	int getProfit(int, int);
};