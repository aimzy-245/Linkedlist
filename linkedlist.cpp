#include <iostream>
#include <iomanip>
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

// Membuat garis pemisah
void garis(int n = 50) {
    for (int i = 0; i < n; ++i) cout << "=";
    cout << endl;
}

// Header Menu
void headerMenu() {
    system("cls");  // Bersihkan layar (khusus Windows)
    garis();
    cout << setw(30) << "INVENTARIS SEWA MOBIL" << endl;
    garis();
}

// Tambah Data Mobil
void tambahMobil() {
    headerMenu();
    cout << "Tambah Data Mobil\n";
    garis();
    Mobil* baru = new Mobil;
    baru->id = idCounter++;
    cout << "Merk Mobil   : "; getline(cin >> ws, baru->merk);
    cout << "Tipe Mobil   : "; getline(cin, baru->tipe);
    cout << "Tahun        : "; cin >> baru->tahun;
    baru->disewa = false;
    baru->next = nullptr;

    if (!head) {
        head = baru;
    } else {
        Mobil* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = baru;
    }
    cout << "Data mobil berhasil ditambahkan!\n";
    system("pause");
}

// Tampil Data Mobil
void tampilMobil(bool tampilSemua = true, bool status = false) {
    headerMenu();
    if (tampilSemua)
        cout << "Daftar Semua Mobil\n";
    else
        cout << (status ? "Daftar Mobil Disewa\n" : "Daftar Mobil Tersedia\n");
    garis();
    cout << left << setw(5) << "ID" << setw(15) << "Merk" << setw(15) << "Tipe" 
         << setw(8) << "Tahun" << setw(12) << "Status" << endl;
    garis();
    
    Mobil* temp = head;
    bool ada = false;
    while (temp) {
        if (tampilSemua || temp->disewa == status) {
            cout << left << setw(5) << temp->id
                 << setw(15) << temp->merk
                 << setw(15) << temp->tipe
                 << setw(8) << temp->tahun
                 << setw(12) << (temp->disewa ? "Disewa" : "Tersedia") << endl;
            ada = true;
        }
        temp = temp->next;
    }
    if (!ada) cout << "Tidak ada data mobil.\n";
    garis();
    system("pause");
}

// Ubah Status Mobil (Disewa/Dikembalikan) dengan Validasi
void updateStatusMobil() {
    headerMenu();
    cout << "Pilih Mobil Yang Akan Disewa / Kembalikan Mobil Yang Telah Disewa\n";
    garis();
    tampilMobil();
    cout << "Masukkan ID mobil: ";
    int id;
    cin >> id;

    Mobil* temp = head;
    while (temp && temp->id != id)
        temp = temp->next;

    if (!temp) {
        cout << "Mobil tidak ditemukan!\n";
    } else {
        cout << "Status saat ini: " << (temp->disewa ? "Disewa" : "Tersedia") << endl;

        int st;
        while (true) {
            cout << "Ubah status menjadi (1: Disewa, 0: Dikembalikan): ";
            cin >> st;

            if (st == 0 || st == 1) {
                temp->disewa = (st == 1);
                cout << "Status berhasil diubah menjadi: " << (st == 1 ? "Disewa" : "Tersedia") << endl;
                break;
            } else {
                cout << "Input tidak valid. Masukkan hanya angka 1 (Disewa) atau 0 (Dikembalikan).\n";
            }
        }
    }
    system("pause");
}

// Hapus Mobil
void hapusMobil() {
    headerMenu();
    cout << "Hapus Data Mobil\n";
    garis();
    tampilMobil();
    cout << "Masukkan ID mobil yang akan dihapus: ";
    int id; cin >> id;
    Mobil* temp = head;
    Mobil* prev = nullptr;
    while (temp && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) {
        cout << "Mobil tidak ditemukan!\n";
    } else {
        if (!prev) head = temp->next;
        else prev->next = temp->next;
        delete temp;
        cout << "Data mobil berhasil dihapus!\n";
    }
    system("pause");
}

// Cari Mobil Berdasarkan Merk
void cariMobil() {
    headerMenu();
    cout << "Cari Mobil Berdasarkan Merk\n";
    garis();
    cout << "Masukkan merk mobil: ";
    string merkCari;
    getline(cin >> ws, merkCari);
    Mobil* temp = head;
    bool ada = false;
    garis();
    cout << left << setw(5) << "ID" << setw(15) << "Merk" << setw(15) << "Tipe" 
         << setw(8) << "Tahun" << setw(12) << "Status" << endl;
    garis();
    while (temp) {
        if (temp->merk.find(merkCari) != string::npos) {
            cout << left << setw(5) << temp->id
                 << setw(15) << temp->merk
                 << setw(15) << temp->tipe
                 << setw(8) << temp->tahun
                 << setw(12) << (temp->disewa ? "Disewa" : "Tersedia") << endl;
            ada = true;
        }
        temp = temp->next;
    }
    if (!ada) cout << "Mobil dengan merk tersebut tidak ditemukan.\n";
    garis();
    system("pause");
}

// Main Program
int main() {
    int pilihan;
    do {
        headerMenu();
        cout << "Menu:\n";
        cout << "1. Tambah Data Mobil\n";
        cout << "2. Pilih Mobil Yang Akan Disewa / Kembalikan Mobil Yang Telah Disewa\n";
        cout << "3. Hapus Mobil dari Daftar\n";
        cout << "4. Cari Mobil Berdasarkan Merk\n";
        cout << "5. Tampilkan Semua Mobil\n";
        cout << "6. Tampilkan Mobil Tersedia\n";
        cout << "7. Tampilkan Mobil Disewa\n";
        cout << "0. Keluar\n";
        garis();
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambahMobil(); break;
            case 2: updateStatusMobil(); break;
            case 3: hapusMobil(); break;
            case 4: cariMobil(); break;
            case 5: tampilMobil(); break;
            case 6: tampilMobil(false, false); break;
            case 7: tampilMobil(false, true); break;
            case 0: cout << "Terima kasih telah menggunakan sistem ini!\n"; break;
            default: cout << "Pilihan tidak valid!\n"; system("pause");
        }
    } while (pilihan != 0);

    // Bersihkan memori
    while (head) {
        Mobil* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
