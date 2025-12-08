#ifndef BUKU_H_INCLUDED
#define BUKU_H_INCLUDED

#include <iostream>
using namespace std;

struct Buku {
    string id;
    string judul;
};

struct elemenBuku {
    Buku info;
    elemenBuku next;
    elemenBuku prev;
};

typedef elemenBuku* adrBuku;

adrBuku createElemenBuku_103012400343(string id, string judul);

#endif
