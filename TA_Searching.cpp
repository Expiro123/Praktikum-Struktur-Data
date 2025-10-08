#include <iostream>
#include <string>
using namespace std;

int main() {
    const int jumlahItem = 10;
    string inventori[jumlahItem] = {
        "Pedang Baja",
        "Ramuan Kesehatan",
        "Busur Kayu",
        "Perisai Besi",
        "Kunci Emas",
        "Obor",
        "Anak Panah",
        "Kalung Ajaib",
        "Potion Mana",
        "Kunci Perak"
    };

    string cari;
    bool ditemukan = false;

    cout << "=== INVENTORI PEMAIN ===" << endl;
    for (int i = 0; i < jumlahItem; i++) {
        cout << i + 1 << ". " << inventori[i] << endl;
    }

    cout << "\nMasukkan nama item yang ingin dicari: ";
    getline(cin, cari);

    for (int i = 0; i < jumlahItem; i++) {
        if (inventori[i] == cari) {
            cout << "\nItem \"" << cari << "\" ditemukan di slot ke-" << i + 1 << "!" << endl;
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan)
        cout << "\nItem \"" << cari << "\" tidak ditemukan di inventori." << endl;

    cout << "\n=== Terima kasih telah menggunakan sistem inventori! ===" << endl;

    return 0;
}

