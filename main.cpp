#include <iostream>
#include "header.h"
using namespace std;

void menuAdmin(ListPenulis &L);
void menuUser(ListPenulis L);

int main()
{
    ListPenulis L;
    int pilihan = -1;

    createListPenulis_103012400343(L);

    while (pilihan != 0 && pilihan < 3) {
        cout << "=== APLIKASI PERPUSTAKAAN ===" << endl;
        cout << "1. Login sebagai Admin" << endl;
        cout << "2. Login sebagai User" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            menuAdmin(L);
        } else if (pilihan == 2) {
            menuUser(L);
        } else if (pilihan == 0) {
            cout << "Terima kasih telah menggunakan aplikasi." << endl;
        } else {
            cout << "Pilihan tidak valid." << endl;
        }
    }
    return 0;
}


void menuAdmin(ListPenulis &L){
    int pilihan = -1;
    string idPenulis, namaPenulis, idBuku, judulBuku;
    adrPenulis p;
    int tahun;
    string deskripsi, tipe;
    adrBuku q;

    while (pilihan != 0 && pilihan < 8){
        cout << "=== MENU ADMIN ===" << endl;
        cout << "1. Tambah Penulis" << endl;
        cout << "2. Tambah Buku ke Penulis" << endl;
        cout << "3. Hapus Penulis" << endl;
        cout << "4. Hapus Buku dari Penulis" << endl;
        cout << "5. Lihat Semua Data" << endl;
        cout << "6. Cari Penulis" << endl;
        cout << "7. Cari Buku" << endl;
        cout << "0. Kembali ke Menu Utama" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1){
            cout << "Masukkan ID penulis: ";
            cin >> idPenulis;
            cout << "Masukkan nama penulis: ";
            cin >> namaPenulis;
            p = createElemenPenulis_103012400343(idPenulis, namaPenulis);
            insertLastPenulis_103012400343(L, p);
        }else if (pilihan == 2){
            cout << "Masukkan ID penulis: ";
            cin >> idPenulis;
            p = findPenulis_103012400343(L, idPenulis);
            if (p != nullptr){
                cout << "Penulis Ditemukan: " << p->info.nama << endl;
                cout << "Masukan ID Buku: ";
                cin >> idBuku;
                cout << "Masukan Judul Buku: ";
                cin >> judulBuku;
                cout << "Masukan Tahun Terbit: ";
                cin >> tahun;
                cout << "Masukan Deskripsi: ";
                cin >> deskripsi;
                cout << "Masukan Tipe Buku: ";
                cin >> tipe;
                q = createElemenBuku_103012400343(idBuku, judulBuku, tahun, deskripsi, tipe);
                insertLastBuku_103012400343(p, q);
                cout << "Buku berhasil ditambahkan." << endl;
            }else {
                cout << "Penulis tidak ditemukan!" << endl;
            }
        }else if (pilihan == 3){
            cout << "Masukkan ID penulis yang akan dihapus: ";
            cin >> idPenulis;
            deletePenulis_103012400343(L, idPenulis);
        }else if (pilihan == 4){
            cout << "Masukkan ID penulis: ";
            cin >> idPenulis;
            p = findPenulis_103012400343(L, idPenulis);
            if (p != nullptr){
                cout << "Masukkan ID buku yang akan dihapus: ";
                cin >> idBuku;
                deleteBukuFromPenulis_103012400343(p, idBuku);
            }else{
                cout << "Penulis tidak ditemukan." << endl;
            }
        }else if (pilihan == 5){
            showAllPenulis_103012400343(L);
        }else if (pilihan == 6){
            cout << "Masukan ID Penulis: ";
            cin >> idPenulis;
            p = findPenulis_103012400343(L, idPenulis);
            if (p != nullptr) {
                cout << "Ditemukan: " << p->info.nama << endl;
                showBooksByPenulis_103012400343(p);
            } else {
                cout << "Penulis tidak ditemukan." << endl;
            }
        }else if (pilihan == 7){
            cout << "Masukkan ID buku: ";
            cin >> idBuku;
            findAuthorsByBook_103012400343(L, idBuku);
        }else if (pilihan == 0){
            cout << "Keluar" << endl;
        }else {
            cout << "Pilihan tidak valid" << endl;
        }
    }
}

void menuUser(ListPenulis L){
    int pilihan = -1;
    string idBuku, idPenulis;
    adrPenulis p;

    cout << "=== MENU USER ===" << endl;
        cout << "1. Lihat Semua Buku & Penulis" << endl;
        cout << "2. Cari Buku " << endl;
        cout << "3. Cari Penulis" << endl;
        cout << "4. Jumlah Buku per Penulis" << endl;
        cout << "5. Jumlah Penulis per Buku" << endl;
        cout << "0. Kembali ke Menu Utama" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1){
            showAllPenulis_103012400343(L);
        }else if (pilihan == 2){
            cout << "Masukkan ID buku yang dicari: ";
            cin >> idBuku;
            findAuthorsByBook_103012400343(L, idBuku);
        }else if (pilihan == 3){
            cout << "Masukkan penulis yang dicari: ";
            cin >> idPenulis;
            p = findPenulis_103012400343(L, idPenulis);
            if (p != nullptr){
                cout << "Penulis ditemukan: " << p->info.nama << endl;
                showBooksByPenulis_103012400343(p);
            }else {
                cout << "Penulis tersebut " << idPenulis << " tidak ditemukan." << endl;
            }
        }else if (pilihan == 4) {
            cout << "Masukkan ID penulis: ";
            cin >> idPenulis;
            p = findPenulis_103012400343(L, idPenulis);
            if (p != nullptr) {
                cout << "Jumlah buku oleh " << p->info.nama << ": " << countBooksByPenulis_103012400343(p) << " buku." << endl;
            } else {
                cout << "Penulis tidak ditemukan." << endl;
            }
        } else if (pilihan == 5) {
            cout << "Masukkan ID buku: ";
            cin >> idBuku;
            cout << "Buku " << idBuku << " dikontribusikan oleh: " << countAuthorsByBook_103012400343(L, idBuku) << " penulis." << endl;
        }else if (pilihan == 0){
            cout << "Keluar" << endl;
        }else {
            cout << "Pilihan tidak valid" << endl;
        }
}

