#include <iostream>
#include <string>
using namespace std;

struct Mobil {
    int id;
    string merk;
    string tipe;
    int tahun;
    bool disewa;
    Mobil* next;
};

Mobil* head = nullptr;
int idCounter = 1;

void garis(int n = 50) {
    for (int i = 0; i < n; ++i) cout << "=";
    cout << endl;
}

void headerMenu() {
    system("cls");  // Bersihkan layar (khusus Windows)
    garis();
    cout << "INVENTARIS SEWA MOBIL" << endl;
    garis();
}
