#include "buku.h"
#include <iostream>

using namespace std;

adrBuku createElemenBuku_103012400343(string id, string judul, int tahunTerbit , string deskripsi , string tipeBuku) {
    adrBuku B = new elemenBuku;
    B->info.id = id;
    B->info.judul = judul;
    B->info.tahunTerbit;
    B->info.deskirpsi;
    B->info.tipeBuku
    B->next = NULL;
    B->prev = NULL;
    return B;
}
