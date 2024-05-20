#include <stdio.h>
#include <stdlib.h>
#include "canli.h"
#include "bitki.h"
#include "bocek.h"
#include "pire.h"
#include "sinek.h"

CANLI Bitki = {(void*)bitki_gorunum};
CANLI Bocek = {(void*)bocek_gorunum};
CANLI Sinek = {(void*)sinek_gorunum};
CANLI Pire  = {(void*)pire_gorunum};


CANLI* canli_sec(int deger) {
    if (deger >= 1 && deger <= 9) {
        return &Bitki;
    } else if (deger >= 10 && deger <= 20) {
        return &Bocek;
    } else if (deger >= 21 && deger <= 50) {
        return &Sinek;
    } else if (deger >= 51 && deger <= 99) {
        return &Pire;
    } else {
        return NULL;
    }
}

int* canli_karsilastir(int* canli1, int* canli2){

    if ((*(int*)canli1 <= 20 && *(int*)canli1 >= 10) && (*(int*)canli2 <= 20 && *(int*)canli2 >= 10)){
        if (*(int*)canli1 > *(int*)canli2)
            return canli1;
        else if (*(int*)canli1 == *(int*)canli2)
            return canli1;
         else if (*(int*)canli1 < *(int*)canli2)
            return canli2;
        else
            return canli2;
    }

    if ((*(int*)canli1 <= 9 && *(int*)canli1 >= 1) && (*(int*)canli2 <= 9 && *(int*)canli2 >= 1)){
        if (*(int*)canli1 > *(int*)canli2)
            return canli1;
        else if (*(int*)canli1 == *(int*)canli2)
            return canli1;
        else if (*(int*)canli1 < *(int*)canli2)
            return canli2;
    }

    if ((*(int*)canli1 <= 50 && *(int*)canli1 >= 21) && (*(int*)canli2 <= 50 && *(int*)canli2 >= 21)){
        if (*(int*)canli1 > *(int*)canli2)
            return canli1;
        else if (*(int*)canli1 == *(int*)canli2)
            return canli1;
        else if (*(int*)canli1 < *(int*)canli2)
            return canli2;
    }
    
    if ((*(int*)canli1 <= 99 && *(int*)canli1 >= 51) && (*(int*)canli2 <= 99 && *(int*)canli2 >= 51)){
        if (*(int*)canli1 > *(int*)canli2)
            return canli1;
        else if (*(int*)canli1 == *(int*)canli2)
            return canli1;
        else if (*(int*)canli1 < *(int*)canli2)
            return canli2;    
    }

     if ((*(int*)canli1<=9 && *(int*)canli1>=1) && (*(int*)canli2<=99 && *(int*)canli2 >= 51))
    return canli1;

     if ((*(int*)canli1 <= 20 && *(int*)canli1 >= 10) && (*(int*)canli2<=9 && *(int*)canli2 >= 1))
    return canli1;

     if ((*(int*)canli1<=50 && *(int*)canli1 >=21) && (*(int*)canli2<=99 && *(int*)canli2 >= 51))
    return canli1;

     if ((*(int*)canli1<=9 && *(int*)canli1>=1) && (*(int*)canli2<=50 && *(int*)canli2 >=21))
    return canli1;

     if ((*(int*)canli1<=50 && *(int*)canli1 >=21) && (*(int*)canli2<=20 && *(int*)canli2 >= 10))
    return canli1;

     if ((*(int*)canli1 <= 20 && *(int*)canli1 >= 10) && (*(int*)canli2<=99 && *(int*)canli2 >= 51))
    return canli1;

     if ((*(int*)canli1<=99 && *(int*)canli1>=51) && (*(int*)canli2<=9 && *(int*)canli2 >= 1))
    return canli2;

     if ((*(int*)canli1<=9 && *(int*)canli1>=1) && (*(int*)canli2<=20 && *(int*)canli2 >= 10))
    return canli2;

     if ((*(int*)canli1<=99 && *(int*)canli1>=51) && (*(int*)canli2<=50 && *(int*)canli2 >=21))
    return canli2;

    if ((*(int*)canli1<=50 && *(int*)canli1 >=21) && (*(int*)canli2<=9 && *(int*)canli2 >= 1))
    return canli2;

     if ((*(int*)canli1 <= 20 && *(int*)canli1 >= 10) && (*(int*)canli2<=50 && *(int*)canli2 >=21))
    return canli2;

     if ((*(int*)canli1<=99 && *(int*)canli1>=51) && (*(int*)canli2<=20 && *(int*)canli2 >= 10))
    return canli2;
}


