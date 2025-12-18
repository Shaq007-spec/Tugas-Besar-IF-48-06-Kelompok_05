#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>

using namespace std;

typedef struct elemenBuku* adrBuku;
typedef struct elemenPenulis* adrPenulis;

struct Buku{
    string judul;
    string IDbuku;
    int tahunTerbit;
    string deskripsi;
    string tipeBuku;
};

struct elemenBuku{
    Buku info;
    adrBuku next;
    adrBuku prev;
};

struct Penulis{
    string id;
    string nama;
};

struct elemenPenulis{
    Penulis info;
    adrPenulis next;
    adrBuku firstBuku;
};

struct ListPenulis{
    adrPenulis first;
};

void createListPenulis_103012400343(ListPenulis &L);
adrPenulis createElemenPenulis_103012400343(string id, string nama);
bool isListPenulisEmpty_103012400343(ListPenulis L);
adrBuku createElemenBuku_103012400343(string id, string judul, int tahunTerbit , string deskripsi , string tipeBuku);
void insertLastPenulis_103012400343(ListPenulis &L, adrPenulis P);
void insertLastBuku_103012400343(adrPenulis P, adrBuku B);
adrPenulis findPenulis_103012400343(ListPenulis L, string id);
adrBuku findBukuInPenulis_103012400343(adrPenulis P, string idBuku);
void showAllPenulis_103012400343(ListPenulis L);
void showBooksByPenulis_103012400343(adrPenulis P);
void findAuthorsByBook_103012400343(ListPenulis L, string idBuku);
void showBooksByOtherAuthors_103012400343(ListPenulis L, string excludeID);
void editPenulis_103012400343(adrPenulis P, string idBaru, string namaBaru);
void editBuku_103012400343(adrBuku B, string idBaru, string judulBaru);
void deleteBukuFromPenulis_103012400343(adrPenulis P, string idBuku);
void deletePenulis_103012400343(ListPenulis &L, string idPenulis);
int countBooksByPenulis_103012400343(adrPenulis P);
int countAuthorsByBook_103012400343(ListPenulis L, string idBuku)
void insertFirstPenulis(ListPenulis &L, adrPenulis P);
void insertAfterPenulis(ListPenulis &L, adrPenulis P, string idPrec);
void deleteFirstPenulis(ListPenulis &L);
void deleteAfterPenulis(ListPenulis &L, string idPrec);
void deleteLastPenulis(ListPenulis &L);
void insertFirstBuku(adrPenulis P, adrBuku B);
void insertAfterBuku(adrPenulis P, adrBuku B, string idBukuPrec);
void deleteFirstBuku(adrPenulis P);
void deleteAfterBuku(adrPenulis P, string idBukuPrec);
void deleteLastBuku(adrPenulis P);

#endif // HEADER_H_INCLUDED
