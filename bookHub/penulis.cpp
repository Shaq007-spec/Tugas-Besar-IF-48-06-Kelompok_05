#include "Penulis.h"
#include <iostream>

using namespace std;

void createListPenulis_103012400343(ListPenulis &L) {
    L.first = NULL;
}

adrPenulis createElemenPenulis_103012400343(string id, string nama) {
    adrPenulis P = new elemenPenulis;
    P->info.id = id;
    P->info.nama = nama;
    P->next = NULL;
    P->firstBuku = NULL;
    return P;
}

void insertLastPenulis_103012400343(ListPenulis &L, adrPenulis P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        adrPenulis Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertLastBuku_103012400343(adrPenulis P, adrBuku B) {
    if (P->firstBuku == NULL) {
        P->firstBuku = B;
    } else {
        adrBuku Q = P->firstBuku;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = B;
        B->prev = Q;
    }
    cout << "Buku berhasil ditambahkan ke penulis.\n";
}

adrPenulis findPenulis_103012400343(ListPenulis L, string id) {
    adrPenulis P = L.first;
    while (P != NULL) {
        if (P->info.id == id) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

adrBuku findBukuInPenulis_103012400343(adrPenulis P, string idBuku) {
    adrBuku B = P->firstBuku;
    while (B != NULL) {
        if (B->info.id == idBuku) {
            return B;
        }
        B = B->next;
    }
    return NULL;
}

void showAllPenulis_103012400343(ListPenulis L) {
    cout << "===== DATA PENULIS =====\n";
    adrPenulis P = L.first;

    if (P == NULL) {
        cout << "Tidak ada penulis.\n";
        return;
    }

    while (P != NULL) {
        cout << "ID   : " << P->info.id << endl;
        cout << "Nama : " << P->info.nama << endl;
        cout << "-------------------------\n";
        P = P->next;
    }
}

void showBooksByPenulis_103012400343(adrPenulis P) {
    if (P == NULL) {
        cout << "Penulis tidak ditemukan.\n";
        return;
    }

    cout << "===== BUKU OLEH PENULIS =====\n";
    adrBuku B = P->firstBuku;

    if (B == NULL) {
        cout << "Tidak ada buku.\n";
        return;
    }

    while (B != NULL) {
        cout << "ID Buku : " << B->info.id << endl;
        cout << "Judul   : " << B->info.judul << endl;
        cout << "-----------------------------\n";
        B = B->next;
    }
}

void findAuthorsByBook_103012400343(ListPenulis L, string idBuku) {
    cout << "===== PENULIS DARI BUKU =====\n";

    adrPenulis P = L.first;
    int found = 0;

    while (P != NULL) {
        adrBuku B = P->firstBuku;
        while (B != NULL) {
            if (B->info.id == idBuku) {
                cout << "Penulis : " << P->info.nama << " (" << P->info.id << ")\n";
                cout << "------------------------------\n";
                found = 1;
            }
            B = B->next;
        }
        P = P->next;
    }

    if (found == 0) {
        cout << "Tidak ada penulis untuk buku ini.\n";
    }
}

void showBooksByOtherAuthors_103012400343(ListPenulis L, string excludeID) {
    cout << "===== BUKU PENULIS LAIN =====\n";

    adrPenulis P = L.first;
    int found = 0;

    while (P != NULL) {

        if (P->info.id != excludeID) {
            adrBuku B = P->firstBuku;
            while (B != NULL) {
                cout << "ID Buku : " << B->info.id << endl;
                cout << "Judul   : " << B->info.judul << endl;
                cout << "Penulis : " << P->info.nama << endl;
                cout << "------------------------------\n";
                found = 1;
                B = B->next;
            }
        }

        P = P->next;
    }

    if (!found) {
        cout << "Tidak ada buku dari penulis lain.\n";
    }
}

void editPenulis_103012400343(adrPenulis P, string idBaru, string namaBaru) {
    if (P != NULL) {
        P->info.id = idBaru;
        P->info.nama = namaBaru;
        cout << "Data penulis berhasil diubah.\n";
    }
}


void editBuku_103012400343(adrBuku B, string idBaru, string judulBaru) {
    if (B != NULL) {
        B->info.id = idBaru;
        B->info.judul = judulBaru;
        cout << "Data buku berhasil diubah.\n";
    }
}

void deleteBukuFromPenulis_103012400343(adrPenulis P, string idBuku) {
    adrBuku B = P->firstBuku;

    while (B != NULL) {

        if (B->info.id == idBuku) {

            if (B->prev != NULL) {
                B->prev->next = B->next;
            } else {
                P->firstBuku = B->next;
            }

            if (B->next != NULL) {
                B->next->prev = B->prev;
            }

            delete B;

            cout << "Buku berhasil dihapus.\n";
            return;
        }

        B = B->next;
    }

    cout << "Buku tidak ditemukan.\n";
}

void deletePenulis_103012400343(ListPenulis &L, string idPenulis) {
    adrPenulis P = L.first;
    adrPenulis prev = NULL;

    while (P != NULL) {

        if (P->info.id == idPenulis) {

            if (prev == NULL) {
                L.first = P->next;
            } else {
                prev->next = P->next;
            }

            adrBuku B = P->firstBuku;
            while (B != NULL) {
                adrBuku del = B;
                B = B->next;
                delete del;
            }

            delete P;

            cout << "Penulis berhasil dihapus.\n";
            return;
        }

        prev = P;
        P = P->next;
    }

    cout << "Penulis tidak ditemukan.\n";
}

int countBooksByPenulis_103012400343(adrPenulis P) {
    int jumlah = 0;
    adrBuku B = P->firstBuku;

    while (B != NULL) {
        jumlah++;
        B = B->next;
    }

    return jumlah;
}

int countAuthorsByBook_103012400343(ListPenulis L, string idBuku) {
    int jumlah = 0;

    adrPenulis P = L.first;

    while (P != NULL) {
        adrBuku B = P->firstBuku;

        while (B != NULL) {
            if (B->info.id == idBuku) {
                jumlah++;
            }
            B = B->next;
        }
        P = P->next;
    }

    return jumlah;
}

int countBooksWithoutAuthor_103012400343(ListPenulis L) {
    int jumlah = 0;

    adrPenulis P = L.first;

    while (P != NULL) {

        adrBuku B = P->firstBuku;
        while (B != NULL) {

            int found = 0;

            adrPenulis X = L.first;

            while (X != NULL) {

                if (X != P) {
                    adrBuku Y = X->firstBuku;
                    while (Y != NULL) {
                        if (Y->info.id == B->info.id) {
                            found = 1;
                        }
                        Y = Y->next;
                    }
                }

                X = X->next;
            }

            if (found == 0) {
                jumlah++;
            }

            B = B->next;
        }

        P = P->next;
    }

    return jumlah;
}
