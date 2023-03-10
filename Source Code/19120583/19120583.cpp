// 19120583.cpp
// Đồ án cuối kỳ môn OOP
// Sinh viên thực hiện: Lê Thái Bình Minh - MSSV: 19120583
//

#include "SupeLib.h"
#include "Manage.h"
#include "Menu.h"

Manage lms;


void writeBrand() {
    ofstream fo("LaptopBigBrand.txt");
    for (int i = 0; i < lms.getLaptopBrands().size() - 1; i++)
        fo << lms.getLaptopBrands()[i].toString() << "\n";
    fo << lms.getLaptopBrands()[lms.getLaptopBrands().size() - 1].toString();
}

void writePC() {
    ofstream out("TopLaptops.txt");
    for (int i = 0; i < lms.getLaptops().size() - 1; i++)
        out << lms.getLaptops()[i].toWrite() << "\n";
    out << lms.getLaptops()[lms.getLaptops().size() - 1].toWrite();
}

void writeBill() {
    ofstream writer("Bills.txt");
    for (int i = 0; i < lms.getBills().size() - 1; i++)
        writer << lms.getBills()[i].toWrite() << "\n";
    writer << lms.getBills()[lms.getBills().size() - 1].toWrite();
}

void printMenu();

void printQLDMcon1() {
    int x;

    int line = 8; //Vị trí dòng của menu
    int col = 28;

    bool thoat = false;
    Menu menu;
    menu.printMenuQLDMcon1();

    gotoxy(col, line);
    cout << (char)1; //Vẽ con trỏ trỏ tới menu

    int i = 1;
    while (!thoat) {
        if (_kbhit()) {
            x = move();
            gotoxy(col, line);
            cout << " "; //Xóa con trỏ ở vị trí cũ

            switch (x) {
            case 1: {}


            case 2: {}


            case 4:
            {
                if (i == 4) {
                    col = col - 13;
                }
                if (i == 3) {
                    col = col - 14;
                }
                if (i == 2) {
                    col = col - 17;
                }
                if (i == 1) {
                    i = 5;
                    col = 73;
                }
                i--;
                break;
            }
            case 3:
            {
                if (i == 1) {
                    col = col + 17;
                }
                if (i == 2) {
                    col = col + 14;
                }
                if (i == 3) {
                    col = col + 13;

                }
                if (i == 4) {
                    col = 28;
                    i = 0;
                }
                i++;

                break;
            }
            case 5:
            {
                if (menu.getItem1()[i] == "Xem cac hang") {
                    for (int i = 0; i < 150; i++) {
                        for (int j = 9; j < 35; j++) {
                            gotoxy(i, j); cout << " ";
                        }
                    }
                    lms.viewBrand();
                    break;
                }
                if (menu.getItem1()[i] == "Them hang") {
                    for (int i = 0; i < 150; i++) {
                        for (int j = 9; j < 35; j++) {
                            gotoxy(i, j); cout << " ";
                        }
                    }
                    string str;
                    gotoxy(28, 10); cout << "Nhap vo 1 hang: ";
                    cin >> str;
                    if (lms.addBrand(str)) {
                        gotoxy(45, 12);
                        cout << "Danh sach sau khi nhap:\n";
                        lms.viewBrand();
                        writeBrand();
                    }
                    break;
                }

                if (menu.getItem1()[i] == "Xoa hang") {
                    for (int i = 0; i < 150; i++) {
                        for (int j = 9; j < 35; j++) {
                            gotoxy(i, j); cout << " ";
                        }
                    }
                    Brand temp;
                    string str;
                    gotoxy(28, 10);
                    cout << "Nhap ten hang can xoa: ";
                    cin >> str;
                    temp.setName(str);
                    gotoxy(40, 12);
                    if (lms.deleteBrand(temp))
                    {
                        cout << "Xoa thanh cong!\n";
                        writeBrand();
                    }
                    else cout << "Xoa that bai!\n";
                    break;

                }
                if (menu.getItem1()[i] == "Sua hang") {
                    for (int i = 0; i < 150; i++) {
                        for (int j = 9; j < 35; j++) {
                            gotoxy(i, j); cout << " ";
                        }
                    }
                    gotoxy(28, 10);
                    cout << "Nhap ten hang can sua: ";
                    string str;
                    cin >> str;
                    Brand Temp;
                    Temp.setName(str);
                    gotoxy(28, 11);
                    cout << "Nhap ten hang moi: ";
                    cin >> str;
                    gotoxy(28, 12);
                    if (lms.changeBrand(Temp, str))
                    {
                        cout << "Sua thanh cong!";
                        writeBrand();
                    }
                    else cout << "Sua that bat!";

                    break;
                }
                break;

            }

            case 8:
                thoat = true;
            }

            gotoxy(col, line);
            cout << (char)1;
        }
    }
}

void printQLDMcon2() {
    int x;

    int line = 8; //Vị trí dòng của menu
    int col = 28;

    bool thoat = false;
    Menu menu;
    menu.printMenuQLDMcon2();

    gotoxy(col, line);
    cout << (char)1; //Vẽ con trỏ trỏ tới menu

    int i = 6;
    while (!thoat) {
        if (_kbhit()) {
            x = move();
            gotoxy(col, line);
            cout << " "; //Xóa con trỏ ở vị trí cũ

            switch (x) {
            case 1: {}


            case 2: {}


            case 4:
            {
                if (i == 9) {
                    col = col - 15;
                }
                if (i == 8) {
                    col = col - 16;
                }
                if (i == 7) {
                    col = col - 18;
                }
                if (i == 6) {
                    i = 10;
                    col = 77;
                }
                i--;
                break;
            }
            case 3:
            {
                if (i == 6) {
                    col = col + 18;
                }
                if (i == 7) {
                    col = col + 16;
                }
                if (i == 8) {
                    col = col + 15;

                }
                if (i == 9) {
                    col = 28;
                    i = 5;
                }
                i++;

                break;
            }
            case 5:
            {
                if (menu.getItem1()[i] == "Xem danh sach") {
                    for (int i = 0; i < 170; i++) {
                        for (int j = 9; j < 45; j++) {
                            gotoxy(i, j); cout << " ";
                        }
                    }
                    gotoxy(28, 10);
                    cout << "Nhap ten hang cac san pham muon xem: ";
                    string str;
                    cin >> str;
                    Brand z(str);
                    lms.viewLaptop(z);

                    break;
                }
                if (menu.getItem1()[i] == "Them laptop") {
                    for (int i = 0; i < 170; i++) {
                        for (int j = 9; j < 45; j++) {
                            gotoxy(i, j); cout << " ";
                        }
                    }

                    string str1, str2, str3;
                    int num1, num2, num3, num4, num5, num6;
                    gotoxy(28, 10);
                    cout << "Nhap brand: ";
                    cin >> str1;
                    for (int i = 28; i < 150; i++) {
                        gotoxy(i, 10);
                        cout << " ";
                    }

                    gotoxy(28, 10);
                    cout << "Nhap ten PC: ";
                    cin.ignore(1);
                    getline(cin, str2);
                    for (int i = 28; i < 150; i++) {
                        gotoxy(i, 10);
                        cout << " ";
                    }

                    gotoxy(28, 10);
                    cout << "Nhap CPU: ";
                    cin >> str3;
                    for (int i = 28; i < 150; i++) {
                        gotoxy(i, 10);
                        cout << " ";
                    }

                    gotoxy(28, 10);
                    cout << "Nhap RAM: ";
                    cin >> num1;
                    for (int i = 28; i < 150; i++) {
                        gotoxy(i, 10);
                        cout << " ";
                    }

                    gotoxy(28, 10);
                    cout << "Nhap HDD: ";
                    cin >> num2;
                    for (int i = 28; i < 150; i++) {
                        gotoxy(i, 10);
                        cout << " ";
                    }

                    gotoxy(28, 10);
                    cout << "Nhap SSD: ";
                    cin >> num3;
                    for (int i = 28; i < 150; i++) {
                        gotoxy(i, 10);
                        cout << " ";
                    }

                    gotoxy(28, 10);
                    cout << "Nhap gia mua: ";
                    cin >> num4;
                    for (int i = 28; i < 150; i++) {
                        gotoxy(i, 10);
                        cout << " ";
                    }

                    gotoxy(28, 10);
                    cout << "Nhap gia ban: ";
                    cin >> num5;
                    for (int i = 28; i < 150; i++) {
                        gotoxy(i, 10);
                        cout << " ";
                    }

                    gotoxy(28, 10);
                    cout << "So luong: ";
                    cin >> num6;
                    for (int i = 28; i < 150; i++) {
                        gotoxy(i, 10);
                        cout << " ";
                    }

                    PC pcc(str1, str2, str3, num1, num2, num3, num4, num5, num6);
                    Brand brd(str1);
                    if (lms.checkBrand(brd) == -1) {
                        gotoxy(28, 11);
                        cout << "Hang chua co trong database. Dang them...";
                        lms.addBrand(str1);
                        writeBrand();
                    }
                    gotoxy(28, 12);
                    if (lms.addLaptop(pcc)) {
                        cout << "Them thanh cong!";
                        writePC();
                    }
                    else cout << "Them that bai";

                    break;
                }

                if (menu.getItem1()[i] == "Xoa laptop") {
                    //xóa 1 laptop ra khỏi danh sách
                    for (int i = 0; i < 170; i++) {
                        for (int j = 9; j < 45; j++) {
                            gotoxy(i, j); cout << " ";
                        }
                    }
                    lms.viewLaptop();
                    gotoxy(28, 14 + lms.getLaptops().size());
                    cout << "Nhap vao So thu tu cua laptop can xoa: ";
                    int num;
                    cin >> num;
                    num--;

                    gotoxy(28, 14 + lms.getLaptops().size() + 1);
                    if (num >= lms.getLaptops().size() || num < 0) {
                        cout << "Xoa that bai!";
                        break;
                    }
                    else {
                        PC pcc = lms.getLaptops()[num];
                        if (lms.deleteLaptop(pcc)) {
                            cout << "Xoa thanh cong!";
                            writePC();
                        }
                        else cout << "Xoa that bai!";
                        break;
                    }

                }
                if (menu.getItem1()[i] == "Sua laptop") {
                    //chỉnh sửa thông tin laptop
                    for (int i = 0; i < 170; i++) {
                        for (int j = 9; j < 45; j++) {
                            gotoxy(i, j); cout << " ";
                        }
                    }

                    for (int i = 0; i < lms.getLaptops().size(); i++) {
                        gotoxy(5, 10); cout << "------------Danh sach cac laptop------------";
                        gotoxy(1, 11); cout << "STT";
                        gotoxy(5, 11); cout << "Ten may";
                        gotoxy(40, 11); cout << "CPU";
                        gotoxy(55, 11); cout << "RAM (GB)";
                        gotoxy(70, 11); cout << "HDD (GB)";
                        gotoxy(85, 11); cout << "SSD (GB)";
                        gotoxy(100, 11); cout << "Gia mua (USD)";
                        gotoxy(125, 11); cout << "Gia ban (USD)";
                        gotoxy(145, 11); cout << "So luong (Cai)";

                        int j = 12;
                        for (int i = 0; i < lms.getLaptops().size(); i++)
                        {
                            gotoxy(3, j);
                            cout << 1 + i;
                            gotoxy(5, j);
                            cout << lms.getLaptops()[i].getBrand().getName() << " " << lms.getLaptops()[i].getNamePC();

                            gotoxy(37, j); cout << "||";
                            gotoxy(40, j);
                            cout << lms.getLaptops()[i].getCPU();

                            gotoxy(52, j); cout << "||";
                            gotoxy(55, j);
                            cout << lms.getLaptops()[i].getRAM();

                            gotoxy(67, j); cout << "||";
                            gotoxy(70, j);
                            cout << lms.getLaptops()[i].getHDD();

                            gotoxy(82, j); cout << "||";
                            gotoxy(85, j);
                            cout << lms.getLaptops()[i].getSSD();

                            gotoxy(97, j); cout << "||";
                            gotoxy(100, j); cout << lms.getLaptops()[i].getCost();

                            gotoxy(122, j); cout << "||";
                            gotoxy(125, j);
                            cout << lms.getLaptops()[i].getPrice();

                            gotoxy(142, j); cout << "||";
                            gotoxy(145, j);
                            cout << lms.getLaptops()[i].getQuantity();

                            j++;
                        }
                    }
                    gotoxy(28, 12 + lms.getLaptops().size());
                    cout << "Nhap STT cua laptop can thay doi thong tin: ";
                    int x, y, z;
                    cin >> x;
                    x--;
                    if (x < 0 || x >= lms.getLaptops().size())
                    {
                        gotoxy(35, lms.getLaptops().size() + 13);
                        cout << "Loi!";
                        break;
                    }

                    int n = lms.getLaptops().size() + 12;
                    for (int i = 28; i < 170; i++)
                    {
                        gotoxy(i, n);
                        cout << " ";
                    }
                    gotoxy(28, lms.getLaptops().size() + 12);
                    cout << "Ban muon thay doi thong tin nao?";

                    n++;
                    gotoxy(28, n);
                    cout << "1. Ten hang";

                    n++;
                    gotoxy(28, n);
                    cout << "2. Ten may tinh";

                    n++;
                    gotoxy(28, n);
                    cout << "3. CPU";

                    n++;
                    gotoxy(28, n);
                    cout << "4. RAM";

                    n++;
                    gotoxy(28, n);
                    cout << "5. HDD";

                    n++;
                    gotoxy(28, n);
                    cout << "6. SSD";

                    n++;
                    gotoxy(28, n);
                    cout << "7. Gia mua";

                    n++;
                    gotoxy(28, n);
                    cout << "8. Gia ban";

                    n++;
                    gotoxy(28, n);
                    cout << "9. So luong";


                    n++;
                    gotoxy(28, n);
                    cout << "Chon STT phan muon thay doi: ";
                    cin >> y;
                    string str;
                    cin.ignore(1);

                    n++;
                    gotoxy(28, n);
                    switch (y)
                    {
                    case 1:
                    {
                        cout << "Nhap ten hang moi: ";
                        cin >> str;
                        lms.changePCBrand(lms.getLaptops()[x], str);
                        Brand _brd(str);
                        if (lms.checkBrand(_brd) == -1) {
                            gotoxy(28, n + 1);
                            cout << "Hang chua co trong database. Dang them...";
                            lms.addBrand(str);
                            writeBrand();
                        }
                        n++;
                        gotoxy(28, n);
                        cout << "Sua thanh cong!";
                        break;
                    }
                    case 2: {
                        cout << "Nhap ten may tinh moi: ";
                        getline(cin, str);
                        lms.changePCName(lms.getLaptops()[x], str);

                        n++;
                        gotoxy(28, n);
                        cout << "Sua thanh cong!";
                        break;
                    }
                    case 3: {
                        cout << "Nhap CPU moi: ";
                        cin >> str;
                        lms.changePCcpu(lms.getLaptops()[x], str);

                        n++;
                        gotoxy(28, n);
                        cout << "Sua thanh cong!";
                        break;
                    }
                    case 4: {
                        cout << "Nhap RAM moi: ";
                        cin >> z;
                        lms.changePCram(lms.getLaptops()[x], z);

                        n++;
                        gotoxy(28, n);
                        cout << "Sua thanh cong!";
                        break;
                    }
                    case 5: {
                        cout << "Nhap HDD moi: ";
                        cin >> z;
                        lms.changePChdd(lms.getLaptops()[x], z);

                        n++;
                        gotoxy(28, n);
                        cout << "Sua thanh cong!";
                        break;
                    }
                    case 6: {
                        cout << "Nhap SSD: ";
                        cin >> z;
                        lms.changePCssd(lms.getLaptops()[x], z);

                        n++;
                        gotoxy(28, n);
                        cout << "Sua thanh cong!";
                        break;
                    }
                    case 8: {
                        cout << "Nhap gia ban moi: ";
                        cin >> z;
                        lms.changePCprice(lms.getLaptops()[x], z);

                        n++;
                        gotoxy(28, n);
                        cout << "Sua thanh cong!";
                        break;
                    }
                    case 7: {
                        cout << "Nhap gia mua moi:";
                        cin >> z;
                        lms.changePCcost(lms.getLaptops()[x], z);

                        n++;
                        gotoxy(28, n);
                        cout << "Sua thanh cong!";
                        break;
                    }
                    case 9: {
                        cout << "Nhap so luong moi:";
                        cin >> z;
                        lms.changePCquantity(lms.getLaptops()[x], z);

                        n++;
                        gotoxy(28, n);
                        cout << "Sua thanh cong!";
                        break;
                    }
                    default: {
                        cout << "Loi, vui long thu lai!";
                        break;
                    }
                    }
                    break;
                }
                writePC();
                break;

            }

            case 8:

                thoat = true;
            }
            gotoxy(col, line);
            cout << (char)1;
        }
    }
}
void printQLDM() {
    int x;

    int line = 6; //Vị trí dòng của menu
    int col = 38;

    bool thoat = false;
    Menu menu;
    menu.printMenuQLDM();

    gotoxy(col, line);
    cout << (char)1; //Vẽ con trỏ trỏ tới menu

    int i = 0;
    while (!thoat) {
        if (_kbhit()) {
            x = move();
            gotoxy(col, line);
            cout << " "; //Xóa con trỏ ở vị trí cũ

            switch (x) {
            case 1: {}

            case 2: {}

            case 4:
            {
                if (i == 10) {
                    col = col - 19;
                }
                if (i == 5) {
                    col = col - 17;
                }
                if (i == 0) {
                    i = 15;
                    col = 74;
                }
                i = i - 5;
                break;
            }
            case 3:
            {
                if (i == 0) {
                    col = col + 17;
                }
                if (i == 5) {
                    col = col + 19;
                }
                if (i == 10) {
                    col = 38;
                    i = -5;
                }
                i += 5;

                break;
            }
            case 5:
            {
                if (menu.getItem1()[i] == "Quan ly hang") {
                    menu.deleteMenuQLDMcon2();
                    printQLDMcon1();

                    break;
                }
                if (menu.getItem1()[i] == "Quan ly laptop") {
                    menu.deleteMenuQLDMcon1();
                    printQLDMcon2();
                    break;
                }

                if (menu.getItem1()[i] == "Quay lai") {

                    menu.deleteMenuQLDM();
                    printMenu();
                    exit(0);
                }
                break;
            }
            case 8:
                thoat = true;
            }

            gotoxy(col, line);
            cout << (char)1;
        }
    }
}

void printQLDH() {
    int x;

    int line = 6; //Vị trí dòng của menu
    int col = 13;

    bool thoat = false;
    Menu menu;
    menu.printMenuQLDH();

    gotoxy(col, line);
    cout << (char)1; //Vẽ con trỏ trỏ tới menu

    int i = 0;
    while (!thoat) {
        if (_kbhit()) {
            x = move();
            gotoxy(col, line);
            cout << " "; //Xóa con trỏ ở vị trí cũ

            switch (x) {
            case 1: {}

            case 2: {}

            case 4:
            {
                if (i == 4) {
                    col = col - 17;
                }
                if (i == 3) {
                    col = col - 31;
                }
                if (i == 2) {
                    col = col - 26;
                }

                if (i == 1) {
                    col = col - 39;
                }

                if (i == 0) {
                    col = 126;
                    i = 5;
                }
                i--;
                break;
            }
            case 3:
            {
                if (i == 0) {
                    col = col + 39;
                }
                if (i == 1) {
                    col = col + 26;
                }
                if (i == 2) {
                    col = col + 31;
                }
                if (i == 3) {
                    col = col + 17;
                }
                if (i == 4) {
                    col = 13;
                    i = -1;
                }
                i++;

                break;
            }
            case 5:
            {
                if (menu.getItem2()[i] == "Xem danh sach don hang trong thang") {
                    for (int i = 0; i < 170; i++) {
                        for (int j = 8; j < 35; j++) {
                            gotoxy(i, j); cout << " ";
                        }
                    }
                    gotoxy(20, 8);

                    //phân trang
                    if (lms.getBills().size() <= 5) {
                        lms.viewBills(0, lms.getBills().size());
                        break;
                    }
                    else {
                        int bonus = lms.getBills().size() / 5;
                        if (bonus * 5 < lms.getBills().size()) bonus++;
                        int count = 0;
                        int size = 0;
                        for (int i = 20; i < 170; i++)
                            for (int j = 9; j < 15; j++) {
                                gotoxy(i, j); cout << " ";
                            }
                        lms.viewBills(size, size + 5);
                        count++;
                        size += 5;
                        int k = 1;

                        while (1) {
                            gotoxy(10, 15);
                            cout << "Trang: " << count;
                            if (count == bonus)
                            {
                                gotoxy(20, 15);  cout << "Nhan -1 de ve trang truoc, nhan 0 de thoat: ";
                            }
                            else
                            {
                                if (count == 1) {
                                    gotoxy(20, 15);  cout << "Nhan 1 de qua trang ke, nhan 0 de thoat: ";
                                }
                                else {
                                    gotoxy(20, 15);
                                    cout << "Nhan 1 de qua trang ke, Nhan -1 de ve trang truoc, nhan 0 de thoat: ";
                                }
                            }
                            cin >> k;
                            if (count == 1 && k == -1) {
                                gotoxy(28, 16); cout << "Loi!";
                                break;
                            }
                            if (count == bonus && k == 1) {
                                gotoxy(28, 16); cout << "Loi!";
                                break;
                            }
                            if (k == 0) {
                                for (int i = 10; i < 170; i++)
                                    for (int j = 9; j < 16; j++) {
                                        gotoxy(i, j); cout << " ";
                                    }
                                break;
                            }
                            if (k == 1) {
                                if (count == bonus - 1) {
                                    for (int i = 20; i < 170; i++)
                                        for (int j = 9; j < 16; j++) {
                                            gotoxy(i, j); cout << " ";
                                        }
                                    lms.viewBills(size, lms.getBills().size());
                                    count++;
                                }
                                else {
                                    for (int i = 20; i < 170; i++)
                                        for (int j = 9; j <= 15; j++) {
                                            gotoxy(i, j); cout << " ";
                                        }
                                    lms.viewBills(size, size + 5);
                                    count++;
                                    size += 5;
                                }
                            }
                            if (k == -1) {
                                if (count == 1) {
                                    size = 0;
                                    for (int i = 20; i < 170; i++)
                                        for (int j = 9; j <= 15; j++) {
                                            gotoxy(i, j); cout << " ";
                                        }
                                    lms.viewBills(size, size + 5);

                                }
                                else {
                                    count--;
                                    size -= 5;
                                    for (int i = 20; i < 170; i++)
                                        for (int j = 9; j <= 15; j++) {
                                            gotoxy(i, j); cout << " ";
                                        }
                                    lms.viewBills(size, size + 5);
                                }
                            }

                        }
                    }

                }
                if (menu.getItem2()[i] == "Xem chi tiet don hang") {
                    for (int i = 0; i < 170; i++) {
                        for (int j = 8; j < 35; j++) {
                            gotoxy(i, j); cout << " ";
                        }
                    }
                    gotoxy(20, 8);
                    string str;
                    cout << "Nhap ma don hang: ";
                    cin >> str;
                    lms.viewBill(str);

                    break;
                }

                if (menu.getItem2()[i] == "Cap nhat chi tiet don hang") {
                    string s1, ss;
                    int num1;
                    Bill bin;

                    for (int i = 0; i < 170; i++) {
                        for (int j = 8; j < 35; j++) {
                            gotoxy(i, j); cout << " ";
                        }
                    }
                    gotoxy(20, 8);
                    lms.viewBills(0, lms.getBills().size());
                    gotoxy(20, lms.getBills().size() + 10);
                    cout << "Nhap ID don hang can sua: ";
                    cin >> s1;
                    bin.setID(s1);
                    if (lms.checkBill(bin) == -1) {
                        gotoxy(20, 9);
                        cout << "Loi!";
                        break;
                    }
                    ss = s1;
                    int n = lms.getBills().size() + 11;
                    n++;
                    for (int i = 0; i < 150; i++) {
                        gotoxy(i, n);
                        cout << " ";
                    }

                    int cap;
                    int pos = lms.checkBill(bin);

                    gotoxy(20, n);
                    cout << "Co muon thay doi Ngay khong? (1-Co / 0-Khong) ";
                    cin >> cap;
                    for (int i = 0; i < 150; i++) {
                        gotoxy(i, n);
                        cout << " ";
                    }
                    if (cap == 1) {
                        cin.ignore(1);
                        gotoxy(20, n);
                        cout << "Thoi gian moi: ";
                        Date niw;
                        getline(cin, s1);
                        niw = Date::parse(s1);
                        bin.setDate(niw);
                        for (int i = 0; i < 150; i++) {
                            gotoxy(i, n);
                            cout << " ";
                        }
                    }
                    else {
                        bin.setDate(lms.getBills()[pos].getDate());
                    }

                    gotoxy(20, n);
                    cout << "Co muon thay doi Ten khach hang khong? (1-Co / 0-Khong) ";
                    cin >> cap;
                    for (int i = 0; i < 150; i++) {
                        gotoxy(i, n);
                        cout << " ";
                    }
                    if (cap == 1) {
                        cin.ignore(1);
                        gotoxy(20, n);
                        cout << "Ten khach hang moi: ";
                        getline(cin, s1);
                        bin.setNameCustomer(s1);
                        for (int i = 0; i < 150; i++) {
                            gotoxy(i, n);
                            cout << " ";
                        }
                    }
                    else {
                        bin.setNameCustomer(lms.getBills()[pos].getNameCustomer());
                    }

                    gotoxy(20, n);
                    cout << "Co muon thay doi Mat hang khong? (1-Co / 0-Khong) ";
                    cin >> cap;
                    for (int i = 0; i < 150; i++) {
                        gotoxy(i, n);
                        cout << " ";
                    }

                    if (cap == 1) {
                        cin.ignore(1);
                        gotoxy(20, n);
                        cout << "Laptop moi: ";
                        PC top;
                        getline(cin, s1);
                        top = PC::parse(s1);
                        bin.setPC(top);
                        for (int i = 0; i < 150; i++) {
                            gotoxy(i, n);
                            cout << " ";
                        }
                    }
                    else {
                        bin.setPC(lms.getBills()[pos].getPC());
                    }


                    gotoxy(20, n);
                    cout << "Co muon thay doi So luong khong? (1-Co / 0-Khong) ";
                    cin >> cap;
                    for (int i = 0; i < 150; i++) {
                        gotoxy(i, n);
                        cout << " ";
                    }
                    if (cap == 1) {
                        gotoxy(20, n);
                        cout << "So luong moi: ";
                        cin >> num1;
                        if (num1 > bin.getPC().getQuantity()) {
                            gotoxy(20, n + 1);
                            cout << "Loi!";
                            break;
                        }

                        bin.setCount(num1);
                        for (int i = 0; i < 150; i++) {
                            gotoxy(i, 8);
                            cout << " ";
                        }
                    }
                    else {
                        bin.setCount(lms.getBills()[pos].getCount());
                    }


                    bin.setAmount(bin.getCount() * bin.getPC().getPrice());

                    if (lms.updateBill(ss, bin))
                    {
                        gotoxy(20, n + 1);
                        cout << "Sua thanh cong!";
                        writeBill();
                    }
                    else {
                        gotoxy(20, n + 1);
                        cout << "Sua that bai!";
                    }
                    break;
                }

                if (menu.getItem2()[i] == "Xoa don hang") {
                    for (int i = 0; i < 170; i++) {
                        for (int j = 8; j < 35; j++) {
                            gotoxy(i, j); cout << " ";
                        }
                    }
                    string str;
                    lms.viewBills(0, lms.getBills().size());
                    gotoxy(20, lms.getBills().size() + 10);
                    cout << "Nhap vao Ma don hang can xoa: ";
                    cin >> str;
                    gotoxy(20, lms.getBills().size() + 11);
                    if (lms.deleteBill(str)) {
                        cout << "Xoa thanh cong!";
                        writeBill();
                    }
                    else cout << "Xoa that bai!";
                    break;
                }

                if (menu.getItem2()[i] == "Quay lai") {
                    menu.deleteMenuQLDH();
                    printMenu();
                    exit(0);
                }
                break;
            }
            case 8:

                thoat = true;
            }
            gotoxy(col, line);
            cout << (char)1;

        }
    }
}

void printTKBC() {
    int x;

    int line = 6; //Vị trí dòng của menu
    int col = 3;

    bool thoat = false;
    Menu menu;
    menu.printMenuTKBC();

    gotoxy(col, line);
    cout << (char)1; //Vẽ con trỏ trỏ tới menu

    int i = 0;
    while (!thoat) {
        if (_kbhit()) {
            x = move();
            gotoxy(col, line);
            cout << " "; //Xóa con trỏ ở vị trí cũ

            switch (x) {
            case 1: {}

            case 2: {}

            case 4:
            {
                if (i == 3) {
                    col = col - 47;
                }
                if (i == 2) {
                    col = col - 44;
                }
                if (i == 1) {
                    col = col - 51;
                }
                if (i == 0) {
                    i = 4;
                    col = 145;
                }
                i--;
                break;
            }
            case 3:
            {
                if (i == 0) {
                    col = col + 51;
                }
                if (i == 1) {
                    col = col + 44;
                }
                if (i == 2) {
                    col = col + 47;
                }
                if (i == 3) {
                    col = 3;
                    i = -1;
                }
                i++;

                break;
            }
            case 5:
            {
                if (menu.getItem3()[i] == "Danh sach cac mat hang sap het (so luong < 10)") {
                    for (int i = 0; i < 150; i++) {
                        for (int j = 8; j < 35; j++) {
                            gotoxy(i, j); cout << " ";
                        }
                    }
                    lms.PCrunningout(10);
                    break;
                }
                if (menu.getItem3()[i] == "Cac mat hang ban chay trong thang truoc") {
                    for (int i = 0; i < 150; i++) {
                        for (int j = 8; j < 35; j++) {
                            gotoxy(i, j); cout << " ";
                        }
                    }
                    lms.getHotDeal();
                    break;
                }
                if (menu.getItem3()[i] == "Doanh thu, loi nhuan theo mot thang cu the") {
                    //Show revenue, profit
                    for (int i = 0; i < 170; i++) {
                        for (int j = 8; j < 35; j++) {
                            gotoxy(i, j); cout << " ";
                        }
                    }

                    gotoxy(5, 9);
                    cout << "Nhap thang can xem: ";
                    int monz, yeaz;
                    cin >> monz;
                    for (int i = 0; i < 150; i++) {
                        gotoxy(i, 9);
                        cout << " ";
                    }

                    gotoxy(5, 9);
                    cout << "Nhap nam can xem: ";
                    cin >> yeaz;
                    for (int i = 0; i < 150; i++) {
                        gotoxy(i, 9);
                        cout << " ";
                    }

                    gotoxy(5, 10);
                    cout << "Tong doanh thu: " << lms.getRevenue(monz, yeaz);
                    gotoxy(5, 11);
                    cout << "Tong loi nhuan: " << lms.getProfit(monz, yeaz);
                    break;
                }

                if (menu.getItem3()[i] == "Quay lai") {

                    menu.deleteMenuTKBC();
                    printMenu();
                    exit(0);
                }
                break;

            }

            case 8:

                thoat = true;

            }

            gotoxy(col, line);
            cout << (char)1;

        }

    }

}

void printMenu() {
    gotoxy(45, 2);
    cout << "HE THONG QUAN LY CUA HANG LAPTOP\n";
    Menu menu;

    int x;

    int line = 4; //Vị trí dòng của menu
    int col = 23;

    bool thoat = false;

    menu.printMenu();

    gotoxy(col, line);
    cout << (char)1; //Vẽ con trỏ trỏ tới menu

    int i = 0;
    while (!thoat) {
        if (_kbhit()) {
            x = move();
            gotoxy(col, line);
            cout << " "; //Xóa con trỏ ở vị trí cũ

            switch (x) {
            case 1:

            case 2:

            case 4:
            {
                if (i == 3 || i == 2 || i == 1) col -= 21;
                if (i == 0) {
                    i = 4;
                    col = 86;
                }
                i--;
                break;
            }
            case 3:
            {
                if (i == 0 || i == 1 || i == 2) {
                    col += 21;
                }
                if (i == 3) {
                    col = 23;
                    i = -1;
                }
                i++;
                break;
            }
            case 5:
            {
                if (menu.getItem()[i] == "Quan ly danh muc") {
                    menu.deleteMenu();
                    printQLDM();

                    break;
                }

                if (menu.getItem()[i] == "Quan ly don hang") {
                    menu.deleteMenu();
                    printQLDH();

                    break;
                }

                if (menu.getItem()[i] == "Thong ke bao cao") {
                    menu.deleteMenu();
                    printTKBC();
                    break;
                }

                if (menu.getItem()[i] == "Quay lai") {
                    menu.deleteMenu();
                    thoat = true;
                    exit(0);
                }
            }
            case 8:
                thoat = true;
            }

            gotoxy(col, line);
            cout << (char)1;
        }
    }
    menu.deleteMenu();
}
int main()
{
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

    ifstream fi("LaptopBigBrand.txt");
    string str;
    if (fi.is_open()) {
        while (!fi.eof()) {
            fi >> str;
            lms.addBrand(str);
        }
        fi.close();
    }
    else cout << "Failed to open Brand list\n";

    ifstream inp("TopLaptops.txt");
    string buffer;
    if (inp.is_open()) {
        vector<PC> fire;
        while (!inp.eof()) {
            getline(inp, buffer);
            PC tmp_PC = PC::parse(buffer);
            fire.push_back(tmp_PC);
        }
        lms.setLaptops(fire);
        inp.close();
    }
    else cout << "Failed to open Laptop list\n";

    ifstream reader("Bills.txt");
    if (reader.is_open()) {
        while (!reader.eof()) {
            getline(reader, buffer);
            Bill pill = Bill::parse(buffer);
            lms.createBill(pill);
        }
    }
    else cout << "Failed to open Bill list\n";

    printMenu();

    return 0;
}