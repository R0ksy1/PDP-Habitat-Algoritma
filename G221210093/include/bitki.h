#ifndef BITKI_H
#define BITKI_H
#include "canli.h"
typedef struct BITKI {
    CANLI super;
} BITKI;
typedef BITKI* bitki;

extern char* bitki_gorunum(bitki b);
#endif