#include <stdio.h>
#include <stdlib.h>
#include "habitat.h"
Habitat* habitat_olustur(int rows, int cols) {
    Habitat *habitat = (Habitat*)malloc(sizeof(Habitat));
    if (habitat == NULL) {
        return NULL;
    }
    habitat->canlilar = (void***)malloc(rows * sizeof(void**));
    if (habitat->canlilar == NULL) {
        free(habitat);
        return NULL;
    }
    for (int i = 0; i < rows; i++) {
        habitat->canlilar[i] = (void**)malloc(cols * sizeof(void*));
        if (habitat->canlilar[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(habitat->canlilar[j]);
            }
            free(habitat->canlilar);
            free(habitat);
            return NULL;
        }
    }
    habitat->rows = rows;
    habitat->cols = cols;
    return habitat;
}
void habitat_yok_et(Habitat *habitat) {
    if (habitat == NULL) {
        return;
    }
    for (int i = 0; i < habitat->rows; i++) {
        for (int j = 0; j < habitat->cols; j++) {
            free(habitat->canlilar[i][j]);
        }
        free(habitat->canlilar[i]);
    }
    free(habitat->canlilar);
    free(habitat);
}
void habitat_canli_ekle(Habitat *habitat, int row, int col, void *canli) {
    if (habitat == NULL || row < 0 || row >= habitat->rows || col < 0 || col >= habitat->cols) {
        return;
    }
    habitat->canlilar[row][col] = canli;
}
void* habitat_canli_al(const Habitat *habitat, int row, int col) {
    if (habitat == NULL || row < 0 || row >= habitat->rows || col < 0 || col >= habitat->cols) {
        return NULL;
    }
    return habitat->canlilar[row][col];
}