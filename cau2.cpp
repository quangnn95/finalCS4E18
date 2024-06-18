#include <iostream>
#include <string>
using namespace std;

class Vemaybay {
private:
    string tenchuyen;
    string ngaybay;
    int giave;

public:
    Vemaybay() : tenchuyen(""), ngaybay(""), giave(0) {}
    Vemaybay(const string& tenchuyen, const string& ngaybay, int giave) 
        : tenchuyen(tenchuyen), ngaybay(ngaybay), giave(giave) {}

    ~Vemaybay() {}

    void Nhap() {
        cout << "Nhập tên chuyến: ";
        cin.ignore();
        getline(cin, tenchuyen);
        cout << "Nhập ngày bay: ";
        getline(cin, ngaybay);
        cout << "Nhập giá vé: ";
        cin >> giave;
    }

    void Xuat() const {
        cout << "Tên chuyến: " << tenchuyen << ", Ngày bay: " << ngaybay << ", Giá vé: " << giave << endl;
    }

    int getgiave() const {
        return giave;
    }
};

class Nguoi {
protected:
    string hoten;
    string gioitinh;
    int tuoi;

public:
    Nguoi() : hoten(""), gioitinh(""), tuoi(0) {}
    Nguoi(const string& hoten, const string& gioitinh, int tuoi) 
        : hoten(hoten), gioitinh(gioitinh), tuoi(tuoi) {}

    ~Nguoi() {}

    void Nhap() {
        cout << "Nhập họ tên: ";
        cin.ignore();
        getline(cin, hoten);
        cout << "Nhập giới tính: ";
        getline(cin, gioitinh);
        cout << "Nhập tuổi: ";
        cin >> tuoi;
    }

    void Xuat() const {
        cout << "Họ tên: " << hoten << ", Giới tính: " << gioitinh << ", Tuổi: " << tuoi << endl;
    }
};

class Hanhkhach : public Nguoi {
private:
    Vemaybay* ve;
    int soluong;

public:
    Hanhkhach() : Nguoi(), ve(nullptr), soluong(0) {}
    Hanhkhach(const string& hoten, const string& gioitinh, int tuoi, int soluong) 
        : Nguoi(hoten, gioitinh, tuoi), soluong(soluong) {
        ve = new Vemaybay[soluong];
    }

    Hanhkhach(const Hanhkhach& other) : Nguoi(other), soluong(other.soluong) {
        ve = new Vemaybay[soluong];
        for (int i = 0; i < soluong; ++i) {
            ve[i] = other.ve[i];
        }
    }

    Hanhkhach& operator=(const Hanhkhach& other) {
        if (this != &other) {
            Nguoi::operator=(other);
            soluong = other.soluong;
            delete[] ve;
            ve = new Vemaybay[soluong];
            for (int i = 0; i < soluong; ++i) {
                ve[i] = other.ve[i];
            }
        }
        return *this;
    }

    ~Hanhkhach() {
        delete[] ve;
    }

    void Nhap() {
        Nguoi::Nhap();
        cout << "Nhập số lượng vé: ";
        cin >> soluong;
        ve = new Vemaybay[soluong];
        for (int i = 0; i < soluong; ++i) {
            cout << "Nhập thông tin vé thứ " << i + 1 << ":\n";
            ve[i].Nhap();
        }
    }

    void Xuat() const {
        Nguoi::Xuat();
        for (int i = 0; i < soluong; ++i) {
            cout << "Thông tin vé thứ " << i + 1 << ":\n";
            ve[i].Xuat();
        }
    }

    int tongtien() const {
        int tong = 0;
        for (int i = 0; i < soluong; ++i) {
            tong += ve[i].getgiave();
        }
        return tong;
    }
};

int main() {
    int n;
    cout << "Nhập số lượng hành khách: ";
    cin >> n;
    Hanhkhach* dsHanhkhach = new Hanhkhach[n];

    for (int i = 0; i < n; ++i) {
        cout << "Nhập thông tin hành khách thứ " << i + 1 << ":\n";
        dsHanhkhach[i].Nhap();
    }

    for (int i = 0; i < n; ++i) {
        cout << "Thông tin hành khách thứ " << i + 1 << ":\n";
        dsHanhkhach[i].Xuat();
        cout << "Tổng tiền: " << dsHanhkhach[i].tongtien() << endl;
    }

    // Sắp xếp danh sách hành khách giảm dần theo tổng tiền vé
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (dsHanhkhach[i].tongtien() < dsHanhkhach[j].tongtien()) {
                Hanhkhach temp = dsHanhkhach[i];
                dsHanhkhach[i] = dsHanhkhach[j];
                dsHanhkhach[j] = temp;
            }
        }
    }

    cout << "Danh sách hành khách sau khi sắp xếp giảm dần theo tổng tiền:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Thông tin hành khách thứ " << i + 1 << ":\n";
        dsHanhkhach[i].Xuat();
        cout << "Tổng tiền: " << dsHanhkhach[i].tongtien() << endl;
    }

    delete[] dsHanhkhach;
    return 0;
}