#include "Buku.h"
#include <iostream>

using namespace std;

adrBuku createElemenBuku_103012400343(string id, string judul) {
    adrBuku B = new elemenBuku;
    B->info.id = id;
    B->info.judul = judul;
    B->next = NULL;
    B->prev = NULL;
    return B;
}
