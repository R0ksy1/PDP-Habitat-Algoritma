#ifndef SINEK_H
#define SINEK_H
#include "bocek.h"
typedef struct SINEK {
    BOCEK super;
} SINEK;
typedef SINEK* sinek;
extern char* sinek_gorunum(sinek s);
#endif