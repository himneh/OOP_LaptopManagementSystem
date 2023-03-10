#pragma once
#include "SupeLib.h"

class Menu {
private:
    string* item; //Mảng lưu tên của các menu
    int _numberOfItem; //Số lượng menu

    string* item1; //Mảng lưu tên của các menu quản lý danh mục
    int _numberOfItem1; //Số lượng menu quản lý danh mục

    string* item2; //Mảng lưu tên của các menu quản lý đơn hàng
    int _numberOfItem2; //Số lượng menu quản lý đơn hàng

    string* item3; //Mảng lưu tên của các menu thống kê báo cáo
    int _numberOfItem3; //Số lượng menu thống kê báo cáo
public:
    Menu();
    ~Menu() {}
    void printMenu();
    void deleteMenu(); //Xóa menu khi kết thúc chương trình bằng cách viết đè kí tự trắng
    int numberOfItem();
    string* getItem();

    void printMenuQLDM();
    void printMenuQLDMcon1();
    void printMenuQLDMcon2();
    void deleteMenuQLDM();
    void deleteMenuQLDMcon1();
    void deleteMenuQLDMcon2();

    void printMenuQLDH();
    void deleteMenuQLDH();

    void printMenuTKBC();
    void deleteMenuTKBC();

    //Xóa menu khi kết thúc chương trình bằng cách viết đè kí tự trắng
    int numberOfItem1();
    string* getItem1();
    int numberOfItem2();
    string* getItem2();
    int numberOfItem3();
    string* getItem3();
};