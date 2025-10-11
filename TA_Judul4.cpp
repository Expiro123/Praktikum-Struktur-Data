#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<string> riwayat;
    int n;
    cout << "=== Simulasi Riwayat Browser ===" << endl;
    cout << "Masukkan jumlah halaman yang dikunjungi: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string halaman;
        cout << "Kunjungi halaman ke-" << i + 1 << ": ";
        getline(cin, halaman);
        riwayat.push(halaman);
    }

    cout << "\n--- Menekan tombol 'Back' ---\n";
    while (!riwayat.empty()) {
        cout << "Kembali ke halaman: " << riwayat.top() << endl;
        riwayat.pop();
    }

    cout << "Tidak ada riwayat lagi.\n";
    return 0;
}

