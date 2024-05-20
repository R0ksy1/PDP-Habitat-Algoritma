#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "canli.h"

int main() {
// Dosya oku
    char* dosya_Ad = "Veri.txt";

    FILE *file = fopen(dosya_Ad, "r");
    if (file == NULL) {
        printf("Error: Unable to open input file.\n");
        return 1;
    }

    int MAX_ROWS = 0;
    int MAX_COLS = 0;
    char line[1024];

    // Satır ve sütun sayısını say
    while (fgets(line, sizeof(line), file)) {
        MAX_ROWS++;
        char* tmp = line;
        int count = 0;
        while(*tmp){
            if ( *tmp == ' ' || *tmp == '\n' ) {
                count++;
            }
            tmp++;
        }
        if (count > MAX_COLS) {
            MAX_COLS = count;
        }
    }

     // Matrisi ayır
    int **matris = malloc(MAX_ROWS * sizeof(int *));
    for (int i = 0; i < MAX_ROWS; i++) {
        matris[i] = malloc(MAX_COLS * sizeof(int));
    }

    // Dosya işaretçisini dosyanın başına geri sar
    rewind(file);

    // Verileri matrise oku
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (fscanf(file, "%d", &matris[i][j]) != 1) {
                printf("Error reading file.\n");
                fclose(file);
                return 1;
            }
        }
    }

    fclose(file);
    system("cls");

    

    //Matrisi yazdır
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            CANLI *c = canli_sec(matris[i][j]);
            if (c != NULL) {
                printf("%s ", c->gorunum((void*)&matris[i][j]));
            } else {
                printf("Invalid value: %d ", matris[i][j]);
            }
        }
        printf("\n");
    }

    for (int i = 0; i < 5; i++)
    {
        printf("-");
    }
    printf("\n");
    printf("Lutfen bir tusa basiniz...\n");
    getchar();
    system("cls");
    

     // Matris elemanlarını tek boyutlu diziye dönüştür
    int size = MAX_ROWS * MAX_COLS;
    int *data = (int*)malloc(size * sizeof(int));
    int index = 0;
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            data[index++] = matris[i][j];
        }
    }
    

    // Kazanan kaybeden belirle
    
    int* kazanan;
    int* kaybeden;
    kazanan = &data[0];
    kaybeden = &data[1];
    int* arac;


    for (int i = 1; i < size; i++) {
         arac= canli_karsilastir(kazanan,&data[i]);
            kazanan = arac;
            
    }

    
    int kazanan_index = -1;
    for (int i = 0; i < size; i++) {
    if (&data[i] == kazanan) {
        kazanan_index = i;
        break;
    }
}

    int kz;
    kz = *kazanan;

    // Matrisi tekrar X formunda yazdır
for (int i = 0; i < MAX_ROWS; i++) {
    for (int j = 0; j < MAX_COLS; j++) {
        if (matris[i][j] == kz && ((i == kazanan_index / MAX_COLS) && (j == kazanan_index % MAX_ROWS))) {
            CANLI *c = canli_sec(matris[i][j]);
            if (c != NULL) {
                printf("%s ", c->gorunum((void*)&matris[i][j]));
            } else {
                printf("Invalid value: %d ", matris[i][j]);
            }
        } else {
            printf("X ");
        }
    }
    printf("\n");
}
Sleep(1000);
    for (int i = 0; i < 18; i++)
    {
        printf("-");
    }
    printf("\n");

    if(kz>=1 && kz <= 9)
    {
        printf("Kazanan: B : ");
    }
    else if(kz>=10 && kz <=20 )
    {
        printf("Kazanan: C : ");
    }
    else if(kz>=21 && kz <= 50 )
    {
        printf("Kazanan: S : ");
    }
    else if(kz>= 51 && kz <=99)
    {
        printf("Kazanan: P : ");
    }
    else

    
    printf("Kazanan, %d \n", kz);


        int row = kazanan_index / MAX_COLS;
        int col = kazanan_index % MAX_ROWS;

    printf("(%d,%d) ", row, col);

    free(data);

    // Matrisi serbest bırak
    for (int i = 0; i < MAX_ROWS; i++) {
        free(matris[i]);
    }
    free(matris);

    return 0;
}