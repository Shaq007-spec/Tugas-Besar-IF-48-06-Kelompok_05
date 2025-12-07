#include <iostream>
#include "header.h"
using namespace std;

void createListPenulis_103012400343(ListPenulis &L) {
    L.first = nullptr;
}

bool isListPenulisEmpty_103012400343(ListPenulis L){
    return L.first == nullptr;
}

adrPenulis createElemenPenulis_103012400343(string id, string nama) {
    adrPenulis P;
    P = new elemenPenulis;
    P->info.id = id;
    P->info.nama = nama;
    P->next = nullptr;
    P->firstBuku = nullptr;

    return P;
}

void insertLastPenulis_103012400343(ListPenulis &L, adrPenulis P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        adrPenulis Q = L.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

adrPenulis findPenulis_103012400343(ListPenulis L, string id) {
    adrPenulis P = L.first;
    while (P != nullptr && P->info.id != id) {
        P = P->next;
    }
    return P;
}

void showAllPenulis_103012400343(ListPenulis L) {
    if (L.first == nullptr) {
        cout << "List Penulis Kosong." << endl;
    }

    adrPenulis P;
    P = L.first;
    cout << "--- Daftar Semua Penulis ---" << endl;
    while (P != nullptr) {
        cout << "ID: " << P->info.id << ", Nama: " << P->info.nama << endl;
        showBooksByPenulis_103012400343(P);
        P = P->next;
    }
}

void showBooksByPenulis_103012400343(adrPenulis P) {
    if (P->firstBuku == nullptr) {
        cout << "Belum ada buku yang tercatat." << endl;
    }

    cout << "Buku-buku yang ditulis:" << endl;
    adrBuku Q;
    Q = P->firstBuku;
    while (Q != nullptr) {
        cout << "ID Buku: " << Q->info.IDbuku << ", Judul: " << Q->info.judul << endl;
        Q = Q->next;
    }
}

void findAuthorsByBook_103012400343(ListPenulis L, string idBuku) {
    bool found;
    adrPenulis P;
    found = false;
    P = L.first;
    cout << "Penulis Buku dengan ID " << idBuku << endl;

    while (P != nullptr) {
        if (findBukuInPenulis_103012400343(P, idBuku) != nullptr) {
            cout << "ID: " << P->info.id << ", Nama: " << P->info.nama << endl;
            found = true;
        }
        P = P->next;
    }

    if (!found) {
        cout << "Tidak ada penulis yang terhubung dengan buku ID " << idBuku << "." << endl;
    }
}

void showBooksByOtherAuthors_103012400343(ListPenulis L, string excludeID) {
    adrPenulis P;
    P = L.first;

    while (P != nullptr) {
        if (P->info.id != excludeID) {
            cout << "Penulis ID: " << P->info.id << ", Nama: " << P->info.nama << endl;
            showBooksByPenulis_103012400343(P);
        }
        P = P->next;
    }
}

void editPenulis_103012400343(adrPenulis P, string idBaru, string namaBaru) {
    if (P != nullptr) {
        P->info.id = idBaru;
        P->info.nama = namaBaru;
        cout << "Data penulis berhasil diubah." << endl;
    } else {
        cout << "Penulis tidak ditemukan." << endl;
    }
}

void deletePenulis_103012400343(ListPenulis &L, string idPenulis) {
    adrPenulis P;
    adrPenulis precP;
    P = L.first;
    precP = nullptr;

    while (P != nullptr && P->info.id != idPenulis) {
        precP = P;
        P = P->next;
    }

    if (P != nullptr) {
        adrBuku B = P->firstBuku;
        while (B != nullptr) {
            adrBuku temp = B;
            B = B->next;
            temp->next = nullptr;
            temp->prev = nullptr;
        }
        P->firstBuku = nullptr;
        if (P == L.first) {
            L.first = P->next;
        } else {
            precP->next = P->next;
        }
        P->next = nullptr;
        cout << "Penulis dengan ID " << idPenulis << " berhasil dihapus." << endl;
    } else {
        cout << "Penulis dengan ID " << idPenulis << " tidak ditemukan." << endl;
    }
}
