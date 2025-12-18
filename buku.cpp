#include <iostream>
#include "header.h"
using namespace std;

adrBuku createElemenBuku_103012400343(string id, string judul, int tahunTerbit , string deskripsi , string tipeBuku) {
    adrBuku P;
    P = new elemenBuku;
    P->info.IDbuku = id;
    P->info.judul = judul;
    P->info.deskripsi = deskripsi;
    P->info.tahunTerbit = tahunTerbit;
    P->info.tipeBuku = tipeBuku;
    P->next = nullptr;
    P->prev = nullptr;

    return P;
}

void insertFirstBuku(adrPenulis P, adrBuku B) {
    if (P == nullptr) {
        cout << "Error: Penulis tidak valid." << endl;
    }

    if (P->firstBuku == nullptr) {
        P->firstBuku = B;
    } else {
        B->next = P->firstBuku;
        P->firstBuku->prev = B;
        P->firstBuku = B;
    }
}

void insertAfterBuku(adrPenulis P, adrBuku B, string idBukuPrec) {
    if (P == nullptr) {
        cout << "Error: Penulis tidak valid." << endl;
    }

    adrBuku prec = findBukuInPenulis_103012400343(P, idBukuPrec);

    if (prec != nullptr) {
        if (prec->next == nullptr) {
            prec->next = B;
            B->prev = prec;
        } else {
            B->next = prec->next;
            B->prev = prec;
            prec->next->prev = B;
            prec->next = B;
        }
    } else {
        cout << "Error: Preceding Buku dengan ID " << idBukuPrec << " tidak ditemukan pada Penulis " << P->info.nama << endl;
    }
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

void deleteFirstBuku(adrPenulis P) {
    if (P == nullptr) {
        cout << "Error: Penulis tidak valid." << endl;
    }
    if (P->firstBuku == nullptr) {
        cout << "Error: List Buku pada penulis " << P->info.nama << " kosong." << endl;
    }

    adrBuku B = P->firstBuku;
    P->firstBuku = B->next;
    if (P->firstBuku != nullptr) {
        P->firstBuku->prev = nullptr;
    }
    B->next = nullptr;

    cout << "Buku ID " << B->info.IDbuku << " (" << B->info.judul << ") berhasil dihapus dari " << P->info.nama << " (First)." << endl;
}

void deleteAfterBuku_103012400343(adrPenulis P, string idBukuPrec) {
    if (P == nullptr) {
        cout << "Error: Penulis tidak valid." << endl;
        return;
    }

    adrBuku prec = findBukuInPenulis_103012400343(P, idBukuPrec);

    if (prec == nullptr) {
        cout << "Error: Preceding Buku dengan ID " << idBukuPrec << " tidak ditemukan pada Penulis " << P->info.nama << "." << endl;
    }
    if (prec->next == nullptr) {
        cout << "Error: Tidak ada Buku setelah ID " << idBukuPrec << " pada Penulis " << P->info.nama << "." << endl;
    }

    adrBuku B = prec->next;
    prec->next = B->next;
    if (B->next != nullptr) {
        B->next->prev = prec;
    }
    B->next = nullptr;
    B->prev = nullptr;

    cout << "Buku ID " << B->info.IDbuku << " (" << B->info.judul << ") berhasil dihapus dari " << P->info.nama << idBukuPrec << endl;
}

void deleteLastBuku(adrPenulis P) {
    if (P == nullptr) {
        cout << "Error: Penulis tidak valid." << endl;
    }
    if (P->firstBuku == nullptr) {
        cout << "Error: List Buku pada penulis " << P->info.nama << " kosong." << endl;
    }
    if (P->firstBuku->next == nullptr) {
        deleteFirstBuku_103012400343(P);
    }

    adrBuku B = P->firstBuku;
    while (B->next != nullptr) {
        B = B->next;
    }
    B->prev->next = nullptr;
    B->prev = nullptr;

    cout << "Buku ID " << B->info.IDbuku << " (" << B->info.judul << ") berhasil dihapus dari " << P->info.nama << endl;
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
