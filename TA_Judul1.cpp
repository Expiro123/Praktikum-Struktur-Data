#include <iostream>
using namespace std;

int main() {
    const int JUMLAH_KURSI = 10;
    bool kursi[JUMLAH_KURSI] = {false}; 
    // false = kosong, true = terisi

    int pilihan, nomor;

    do {
        cout << "\n=== Sistem Pemesanan Kursi Bioskop ===\n";
        cout << "1. Tampilkan Kursi\n";
        cout << "2. Pesan Kursi\n";
        cout << "3. Batalkan Kursi\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "\nStatus Kursi: ";
                for (int i = 0; i < JUMLAH_KURSI; i++) {
                    cout << "[" << (i+1) << (kursi[i] ? ":X" : ":O") << "] ";
                }
                cout << "\n(O = Kosong, X = Terisi)\n";
                break;

            case 2:
                cout << "Masukkan nomor kursi yang ingin dipesan (1-10): ";
                cin >> nomor;
                if (nomor >= 1 && nomor <= JUMLAH_KURSI) {
                    if (!kursi[nomor-1]) {
                        kursi[nomor-1] = true;
                        cout << "Kursi " << nomor << " berhasil dipesan.\n";
                    } else {
                        cout << "Kursi " << nomor << " sudah terisi!\n";
                    }
                } else {
                    cout << "Nomor kursi tidak valid!\n";
                }
                break;

            case 3:
                cout << "Masukkan nomor kursi yang ingin dibatalkan (1-10): ";
                cin >> nomor;
                if (nomor >= 1 && nomor <= JUMLAH_KURSI) {
                    if (kursi[nomor-1]) {
                        kursi[nomor-1] = false;
                        cout << "Kursi " << nomor << " berhasil dibatalkan.\n";
                    } else {
                        cout << "Kursi " << nomor << " memang kosong!\n";
                    }
                } else {
                    cout << "Nomor kursi tidak valid!\n";
                }
                break;

            case 4:
                cout << "Terima kasih telah menggunakan sistem.\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 4);

    return 0;
}
