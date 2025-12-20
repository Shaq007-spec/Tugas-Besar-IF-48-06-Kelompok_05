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
void insertFirstPenulis_103012400225(ListPenulis &L, adrPenulis P);
void insertAfterPenulis_103012400225(ListPenulis &L, adrPenulis P, string idPrec);
void insertLastPenulis_103012400343(ListPenulis &L, adrPenulis P);
void insertFirstBuku_103012400225(adrPenulis P, adrBuku B);
void insertAfterBuku_103012400225(adrPenulis P, adrBuku B, string idBukuPrec);
void insertLastBuku_103012400343(adrPenulis P, adrBuku B);
adrPenulis findPenulis_103012400343(ListPenulis L, string id);
adrBuku findBukuInPenulis_103012400343(adrPenulis P, string idBuku);
void showAllPenulis_103012400343(ListPenulis L);
void showBooksByPenulis_103012400343(adrPenulis P);
void findAuthorsByBook_103012400343(ListPenulis L, string idBuku);
void showBooksByOtherAuthors_103012400343(ListPenulis L, string excludeID);
void editPenulis_103012400343(adrPenulis P, string idBaru, string namaBaru);
void editBuku_103012400343(adrBuku B, string idBaru, string judulBaru);
void deleteFirstPenulis_103012400225(ListPenulis &L);
void deleteAfterPenulis_103012400225(ListPenulis &L, string idPrec);
void deleteLastPenulis_103012400225(ListPenulis &L);
void deleteBukuFromPenulis_103012400343(adrPenulis P, string idBuku);
void deletePenulis_103012400343(ListPenulis &L, string idPenulis);
void deleteFirstBuku_103012400225(adrPenulis P);
void deleteAfterBuku_103012400225(adrPenulis P, string idBukuPrec);
void deleteLastBuku_103012400225(adrPenulis P);
int countBooksByPenulis_103012400343(adrPenulis P);
int countAuthorsByBook_103012400343(ListPenulis L, string idBuku);

#endif // HEADER_H_INCLUDED

