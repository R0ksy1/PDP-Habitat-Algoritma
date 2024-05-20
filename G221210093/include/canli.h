#ifndef CANLI_H
#define CANLI_H

typedef struct {
    char* (*gorunum)(void*);
} CANLI;

extern CANLI* canli_sec(int deger);
extern int* canli_karsilastir(int* canli1, int* canli2);

#endif