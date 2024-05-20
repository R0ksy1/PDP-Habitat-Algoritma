#ifndef HABITAT_H
#define HABITAT_H
#include "canli.h"
typedef struct {
    void*** canlilar;
    int rows;
    int cols;
} Habitat;
Habitat* habitat_olustur(int rows, int cols);
void habitat_yok_et(Habitat *habitat);
void habitat_canli_ekle(Habitat *habitat, int row, int col, void *canli);
void* habitat_canli_al(const Habitat *habitat, int row, int col);
#endif