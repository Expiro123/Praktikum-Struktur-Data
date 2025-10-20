#include <iostream>
#include <string>
using namespace std;

struct Book {
    int isbn;
    string title;
    Book* left;
    Book* right;

    Book(int i, string t) : isbn(i), title(t), left(nullptr), right(nullptr) {}
};

Book* insertBook(Book* root, int isbn, string title) {
    if (root == nullptr)
        return new Book(isbn, title);

    if (isbn < root->isbn)
        root->left = insertBook(root->left, isbn, title);
    else if (isbn > root->isbn)
        root->right = insertBook(root->right, isbn, title);

    return root;
}

Book* searchBook(Book* root, int isbn) {
    if (root == nullptr || root->isbn == isbn)
        return root;

    if (isbn < root->isbn)
        return searchBook(root->left, isbn);
    else
        return searchBook(root->right, isbn);
}

void inorder(Book* root) {
    if (!root) return;
    inorder(root->left);
    cout << "ISBN: " << root->isbn << " | Judul: " << root->title << endl;
    inorder(root->right);
}

int main() {
    Book* root = nullptr;
    int pilih, isbn;
    string title;

    do {
        cout << "\n=== Sistem Perpustakaan Digital (BST) ===\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Cari Buku berdasarkan ISBN\n";
        cout << "3. Lihat Semua Buku (Urut ISBN)\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilih;
        cin.ignore();

        if (pilih == 1) {
            cout << "Masukkan ISBN buku: ";
            cin >> isbn;
            cin.ignore();
            cout << "Masukkan judul buku: ";
            getline(cin, title);
            root = insertBook(root, isbn, title);
            cout << "Buku berhasil ditambahkan!\n";
        }
        else if (pilih == 2) {
            cout << "Masukkan ISBN yang ingin dicari: ";
            cin >> isbn;
            Book* hasil = searchBook(root, isbn);
            if (hasil)
                cout << "Buku ditemukan! Judul: " << hasil->title << endl;
            else
                cout << "Buku dengan ISBN tersebut tidak ditemukan.\n";
        }
        else if (pilih == 3) {
            cout << "\nDaftar Buku (Terurut Berdasarkan ISBN):\n";
            inorder(root);
        }
    } while (pilih != 4);

    cout << "Terima kasih telah menggunakan sistem!\n";
    return 0;
}
