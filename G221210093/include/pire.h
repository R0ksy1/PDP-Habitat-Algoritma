#ifndef PIRE_H
#define PIRE_H
#include "bocek.h"

typedef struct PIRE {
    BOCEK super;
} PIRE;
typedef PIRE* pire;
extern char* pire_gorunum(pire p);
#endif