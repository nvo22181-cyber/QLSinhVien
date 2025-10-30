#include <iostream>
#include <cstring>
using namespace std;

struct student {
    char id[16];
    char name[50];
    int year;
    float gpa;
};

int n, menu;
int svthemthanhcong = 0;
student A[1000];
student sv;

void inmenu();
void nhapthongtin();
void indanhsach();
void timtheoid();
void sapxepgpa();
void thongkenamsinh();
void capnhatGPA();

int main() {
    while (true) {
        inmenu();
        switch (menu) {
            case 0:
                cout << "Da thoat chuong trinh.\n";
                return 0;
            case 1:
                nhapthongtin();
                break;
            case 2:
                indanhsach();
                break;
            case 3:
                timtheoid();
                break;
            case 4:
                sapxepgpa();
                break;
            case 5:
                thongkenamsinh();
                break;
            case 6:
                capnhatGPA();
                break;
            default:
                cout << "Lua chon khong hop le.\n";
        }
    }
    return 0;
}

void inmenu() {
    cout << "\n========== MENU ==========\n";
    cout << "1: Nhap va them sinh vien.\n";
    cout << "2: In danh sach sinh vien.\n";
    cout << "3: Tim theo ID.\n";
    cout << "4: Sap xep giam dan theo GPA.\n";
    cout << "5: Thong ke theo nam sinh.\n";
    cout << "6: Cap nhat GPA theo ID.\n";
    cout << "0: Thoat chuong trinh.\n";
    cout << "===========================\n";
    cout << "Nhap lua chon: ";
    cin >> menu;
}

void nhapthongtin() {
    int them;
    cout << "\nNhap so sinh vien can them: ";
    cin >> them;

    if (them <= 0 || svthemthanhcong + them > 1000) {
        cout << "So luong khong hop le.\n";
        return;
    }

    for (int i = 0; i < them; i++) {
        while (true) {
            bool trung = false;
            cout << "\nNhap MSSV: ";
            cin >> sv.id;

            for (int j = 0; j < svthemthanhcong; j++) {
                if (strcmp(sv.id, A[j].id) == 0) {
                    trung = true;
                    break;
                }
            }

            if (trung) {
                cout << "MSSV da bi trung.\n";
                continue;
            }

            cout << "Nhap ten sinh vien: ";
            cin.ignore();
            cin.getline(sv.name, 50);

            cout << "Nhap nam sinh: ";
            cin >> sv.year;

            if (sv.year < 1990 || sv.year > 2015) {
                cout << "Thong tin nam sinh khong hop le.\n";
                continue;
            }

            cout << "Nhap GPA: ";
            cin >> sv.gpa;

            if (sv.gpa < 0 || sv.gpa > 4.0) {
                cout << "GPA khong hop le.\n";
                continue;
            }

            A[svthemthanhcong++] = sv;
            break;
        }
    }
}

void indanhsach() {
    if (svthemthanhcong == 0) {
        cout << "Danh sach rong.\n";
        return;
    }

    cout << "\n=== DANH SACH SINH VIEN ===\n";
    for (int i = 0; i < svthemthanhcong; i++) {
        cout << "\nTen SV: " << A[i].name << "\n";
        cout << "MSSV: " << A[i].id << "\n";
        cout << "GPA: " << A[i].gpa << "\n";
        cout << "Nam sinh: " << A[i].year << "\n";
    }
}

void timtheoid() {
    if (svthemthanhcong == 0) {
        cout << "Danh sach rong.\n";
        return;
    }

    char timID[16];
    cin.ignore();
    cout << "Nhap ID can tim: ";
    cin.getline(timID, 16);

    bool timthay = false;
    for (int i = 0; i < svthemthanhcong; i++) {
        if (strcmp(A[i].id, timID) == 0) {
            timthay = true;
            cout << "\nDa tim thay sinh vien:\n";
            cout << "Ten: " << A[i].name << "\n";
            cout << "MSSV: " << A[i].id << "\n";
            cout << "Nam sinh: " << A[i].year << "\n";
            cout << "GPA: " << A[i].gpa << "\n";
            break;
        }
    }

    if (!timthay) {
        cout << "Khong tim thay sinh vien co ID nay.\n";
    }
}

void sapxepgpa() {
    if (svthemthanhcong == 0) {
        cout << "Danh sach rong.\n";
        return;
    }

    for (int i = 0; i < svthemthanhcong - 1; i++) {
        for (int j = i + 1; j < svthemthanhcong; j++) {
            if (A[i].gpa < A[j].gpa) {
                student tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
        }
    }

    cout << "\nDanh sach sau khi sap xep giam dan theo GPA:\n";
    for (int i = 0; i < svthemthanhcong; i++) {
        cout << "\nTen: " << A[i].name << "\n";
        cout << "MSSV: " << A[i].id << "\n";
        cout << "Nam sinh: " << A[i].year << "\n";
        cout << "GPA: " << A[i].gpa << "\n";
    }
}

void thongkenamsinh() {
    if (svthemthanhcong == 0) {
        cout << "Khong co du lieu de thong ke.\n";
        return;
    }

    bool coNam = false;
    for (int i = 0; i < svthemthanhcong; i++) {
        bool daThongKe = false;
        for (int j = 0; j < i; j++) {
            if (A[j].year == A[i].year) {
                daThongKe = true;
                break;
            }
        }
        if (!daThongKe) {
            int dem = 0;
            for (int k = 0; k < svthemthanhcong; k++) {
                if (A[k].year == A[i].year)
                    dem++;
            }
            cout << "\nNam " << A[i].year << ": " << dem << " sinh vien\n";
            coNam = true;
        }
    }

    if (!coNam)
        cout << "\nKhong co du lieu de thong ke.\n";
}

void capnhatGPA() {
    if (svthemthanhcong == 0) {
        cout << "Danh sach rong.\n";
        return;
    }

    char id[16];
    bool found = false;
    cout << "\nNhap ID sinh vien can cap nhat GPA: ";
    cin >> id;

    for (int i = 0; i < svthemthanhcong; i++) {
        if (strcmp(id, A[i].id) == 0) {
            found = true;
            float newGPA;
            do {
                cout << "Nhap GPA moi (0 <= GPA <= 4.0): ";
                cin >> newGPA;
                if (newGPA < 0 || newGPA > 4.0)
                    cout << "GPA khong hop le, vui long nhap lai!\n";
            } while (newGPA < 0 || newGPA > 4.0);
            A[i].gpa = newGPA;
            cout << "Cap nhat thanh cong! GPA moi cua " << A[i].id << " la " << A[i].gpa << "\n";
            break;
        }
    }

    if (!found) {
        cout << "Khong tim thay ID sinh vien.\n";
    }
}

