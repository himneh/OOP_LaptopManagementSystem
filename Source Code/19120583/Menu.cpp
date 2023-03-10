#include "Menu.h"

string* Menu::getItem3() {
    return item3;
}

int Menu::numberOfItem3() {
    return _numberOfItem3;
}

string* Menu::getItem2() {
    return item2;
}

int Menu::numberOfItem2() {
    return _numberOfItem2;
}


string* Menu::getItem1() {
    return item1;
}

int Menu::numberOfItem1() {
    return _numberOfItem1;
}


string* Menu::getItem() {
    return item;
}

int Menu::numberOfItem() {
    return _numberOfItem;
}

Menu::Menu() {
    item = new string[100];
    _numberOfItem = 4;
    item[0] = "Quan ly danh muc";
    item[1] = "Quan ly don hang";
    item[2] = "Thong ke bao cao";
    item[3] = "THOAT";

    _numberOfItem1 = 11;
    item1 = new string[200];
    item1[0] = "Quan ly hang";

    item1[1] = "Xem cac hang";
    item1[2] = "Them hang";
    item1[3] = "Xoa hang";
    item1[4] = "Sua hang";

    item1[5] = "Quan ly laptop";
    item1[6] = "Xem danh sach";
    item1[7] = "Them laptop";
    item1[8] = "Xoa laptop";
    item1[9] = "Sua laptop";

    item1[10] = "Quay lai";

    _numberOfItem2 = 5;
    item2 = new string[200];

    item2[0] = "Xem danh sach don hang trong thang";
    item2[1] = "Xem chi tiet don hang";
    item2[2] = "Cap nhat chi tiet don hang";
    item2[3] = "Xoa don hang";

    item2[4] = "Quay lai";

    _numberOfItem3 = 4;
    item3 = new string[200];

    item3[0] = "Danh sach cac mat hang sap het (so luong < 10)";//46
    item3[1] = "Cac mat hang ban chay trong thang truoc";//39
    item3[2] = "Doanh thu, loi nhuan theo mot thang cu the";//42

    item3[3] = "Quay lai";
}

void Menu::printMenuTKBC() {
    gotoxy(5, 6); cout << item3[0];
    gotoxy(56, 6); cout << item3[1];
    gotoxy(100, 6); cout << item3[2];
    gotoxy(147, 6); cout << item3[3];
}

void Menu::deleteMenuTKBC() {
    for (int i = 5; i < 170; i++) {
        for (int j = 6; j < 35; j++) {
            gotoxy(i, j); cout << " ";
        }
    }
}

void Menu::printMenuQLDH() {
    gotoxy(15, 6); cout << item2[0];
    gotoxy(54, 6); cout << item2[1];
    gotoxy(80, 6); cout << item2[2];
    gotoxy(111, 6); cout << item2[3];
    gotoxy(128, 6); cout << item2[4];
}

void Menu::deleteMenuQLDH() {
    for (int i = 15; i < 170; i++) {
        for (int j = 6; j < 35; j++) {
            gotoxy(i, j); cout << " ";
        }
    }
}

void Menu::printMenuQLDM() {

    gotoxy(40, 6); cout << item1[0];
    gotoxy(57, 6); cout << item1[5];
    gotoxy(76, 6); cout << item1[10];
}

void Menu::deleteMenuQLDM() {
    for (int i = 1; i < 170; i++) {
        for (int j = 6; j < 35; j++) {
            gotoxy(i, j); cout << " ";
        }
    }
}
void Menu::printMenuQLDMcon1() {
    gotoxy(30, 8); cout << item1[1];
    gotoxy(47, 8); cout << item1[2];
    gotoxy(61, 8); cout << item1[3];
    gotoxy(75, 8); cout << item1[4];
}
void Menu::deleteMenuQLDMcon1() {
    for (int i = 28; i < 170; i++) {
        gotoxy(i, 8); cout << " ";
    }
}
void Menu::printMenuQLDMcon2() {
    gotoxy(30, 8); cout << item1[6];
    gotoxy(48, 8); cout << item1[7];
    gotoxy(64, 8); cout << item1[8];
    gotoxy(79, 8); cout << item1[9];
}
void Menu::deleteMenuQLDMcon2() {
    for (int i = 28; i < 170; i++) {
        gotoxy(i, 8); cout << " ";
    }
}


void Menu::printMenu() {
    gotoxy(25, 4);
    int i = 0;
    cout << item[i++];
    gotoxy(46, 4);
    cout << item[i++];
    gotoxy(67, 4);
    cout << item[i++];
    gotoxy(88, 4);
    cout << item[i++];
}

void Menu::deleteMenu() {
    for (int i = 1; i < 170; i++) {
        gotoxy(i, 4);
        cout << " ";
    }
}

void SetWindowSize(SHORT width, SHORT height) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    SMALL_RECT WindowSize;
    WindowSize.Top = 0;
    WindowSize.Left = 0;
    WindowSize.Right = width;
    WindowSize.Bottom = height;

    SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}
