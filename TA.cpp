#include <iostream>
using namespace std;

// Fungsi Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Geser nilai yang lebih besar dari key ke kanan
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;

    cout << "Masukkan jumlah siswa: ";
    cin >> n;

    int nilai[n];

    // Input nilai ujian siswa
    cout << "Masukkan nilai ujian siswa:\n";
    for (int i = 0; i < n; i++) {
        cout << "Nilai siswa ke-" << i + 1 << ": ";
        cin >> nilai[i];
    }

    // Tampilkan sebelum diurutkan
    cout << "\nNilai sebelum diurutkan: ";
    for (int i = 0; i < n; i++) {
        cout << nilai[i] << " ";
    }
    cout << endl;

    // Panggil fungsi sorting
    insertionSort(nilai, n);

    // Tampilkan setelah diurutkan
    cout << "Nilai setelah diurutkan (terendah -> tertinggi): ";
    for (int i = 0; i < n; i++) {
        cout << nilai[i] << " ";
    }
    cout << endl;

    return 0;
}

