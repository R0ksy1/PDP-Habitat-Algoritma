#ifndef BOCEK_H
#define BOCEK_H
#include "canli.h"
typedef struct BOCEK {
    CANLI super;
} BOCEK;
typedef BOCEK* bocek;
extern char* bocek_gorunum(bocek b);
#endif