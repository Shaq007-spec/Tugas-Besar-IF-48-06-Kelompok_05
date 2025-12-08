#ifndef PENULIS_H_INCLUDED
#define PENULIS_H_INCLUDED

#include "buku.h"

using namespace std;

struct Penulis {
    string id;
    string nama;
};

struct elemenPenulis {
    Penulis info;
    elemenPenulis* next;
    adrBuku firstBuku;
};

typedef elemenPenulis* adrPenulis;

struct ListPenulis {
    adrPenulis first;
};

void createListPenulis_103012400343(ListPenulis &L);
adrPenulis createElemenPenulis_103012400343(string id, string nama);
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
int countAuthorsByBook_103012400343(ListPenulis L, string idBuku);
int countBooksWithoutAuthor_103012400343(ListPenulis L);


#endif
