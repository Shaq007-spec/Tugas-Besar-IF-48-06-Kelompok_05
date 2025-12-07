#include <iostream>
#include "header.h"
using namespace std;

adrBuku createElemenBuku_103012400343(string id, string judul) {
    adrBuku P;
    P = new elemenBuku;
    P->info.IDbuku = id;
    P->info.judul = judul;
    P->next = nullptr;
    P->prev = nullptr;

    return P;
}

void insertLastBuku_103012400343(adrPenulis P, adrBuku B) {
    if (P == nullptr) {
        cout << "Error: Penulis tidak valid." << endl;
    }

    if (P->firstBuku == nullptr) {
        P->firstBuku = B;
    } else {
        adrBuku Q;
        Q = P->firstBuku;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = B;
        B->prev = Q;
    }
}

adrBuku findBukuInPenulis_103012400343(adrPenulis P, string idBuku) {
    if (P == nullptr) {
        return nullptr;
    }

    adrBuku B = P->firstBuku;
    while (B != nullptr && B->info.IDbuku != idBuku) {
        B = B->next;
    }
    return B;
}

void editBuku_103012400343(adrBuku B, string idBaru, string judulBaru) {
    if (B != nullptr) {
        B->info.IDbuku = idBaru;
        B->info.judul = judulBaru;
        cout << "Data buku berhasil diubah." << endl;
    } else {
        cout << "Buku tidak ditemukan." << endl;
    }
}

void deleteBukuFromPenulis_103012400343(adrPenulis P, string idBuku) {
    adrBuku B = nullptr;

    if (P != nullptr) {
        B = P->firstBuku;
        while (B != nullptr && B->info.IDbuku != idBuku) {
            B = B->next;
        }
    }

    if (B != nullptr) {
        if (B == P->firstBuku) {
            P->firstBuku = B->next;
            if (P->firstBuku != nullptr) {
                P->firstBuku->prev = nullptr;
            }
        } else if (B->next == nullptr) {

            B->prev->next = nullptr;
        } else {
            B->prev->next = B->next;
            B->next->prev = B->prev;
        }
        B->next = nullptr;
        B->prev = nullptr;
        delete B;

        cout << "Buku dengan ID " << idBuku << " berhasil dihapus dari penulis " << P->info.nama << "." << endl;
    } else if (P != nullptr) {
        cout << "Buku dengan ID " << idBuku << " tidak ditemukan pada penulis ID " << P->info.id << "." << endl;
    } else {
        cout << "Error: Penulis tidak valid." << endl;
    }
}
