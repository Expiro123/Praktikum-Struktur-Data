#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

void tampilMenu() {
    cout << "\n=== Sistem Login dengan HashMap ===" << endl;
    cout << "1. Daftar Akun Baru" << endl;
    cout << "2. Login" << endl;
    cout << "3. Hapus Akun" << endl;
    cout << "4. Lihat Semua Akun (Admin)" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilih menu: ";
}

int main() {
    unordered_map<string, string> akun; 
    int pilih;
    string username, password;

    akun.insert({"aldes", "12345"});
    akun.insert({"nandika", "abcde"});

    do {
        tampilMenu();
        cin >> pilih;
        cin.ignore();

        if (pilih == 1) {
            cout << "\nMasukkan username baru: ";
            getline(cin, username);

            if (akun.count(username) > 0) {
                cout << "❌ Username sudah terdaftar!" << endl;
            } else {
                cout << "Masukkan password: ";
                getline(cin, password);
                akun.insert({username, password}); // menggunakan insert()
                cout << "Akun berhasil dibuat!" << endl;
            }

        } else if (pilih == 2) { 
            cout << "\nMasukkan username: ";
            getline(cin, username);
            cout << "Masukkan password: ";
            getline(cin, password);

            auto it = akun.find(username); // menggunakan find()
            if (it != akun.end()) {
                if (it->second == password) {
                    cout << "Login berhasil! Selamat datang, " << username << "!" << endl;
                } else {
                    cout << "Password salah!" << endl;
                }
            } else {
                cout << "Username tidak ditemukan!" << endl;
            }

        } else if (pilih == 3) { 
            cout << "\nMasukkan username yang ingin dihapus: ";
            getline(cin, username);

            if (akun.erase(username)) { // menggunakan erase()
                cout << "Akun berhasil dihapus!" << endl;
            } else {
                cout << "Username tidak ditemukan!" << endl;
            }

        } else if (pilih == 4) { 
            cout << "\n=== Daftar Semua Akun ===" << endl;
            for (auto &pair : akun) {
                cout << "Username: " << pair.first << " | Password: " << pair.second << endl;
            }

        } else if (pilih == 5) {
            cout << "Keluar dari sistem..." << endl;
        } else {
            cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilih != 5);

    return 0;
}
