#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int mTab[100];
    int max;
    int min;
    int srednia;
    int mediana;
} struktura;

void wypelnienie(int *tab, int size) {
    srand(time(NULL));
    int i;
    for (i = 0; i < size; i++) {
        tab[i] = 1 + rand() % 100000;
    }
}

int max(int *tab, int size) {
    int i, max = tab[0];
    for (i = 1; i < size; i++) {
        if (tab[i] > max) {
            max = tab[i];
        }
    }
    return max;
}

int min(int *tab, int size) {
    int i, min = tab[0];
    for (i = 1; i < size; i++) {
        if (tab[i] < min) {
            min = tab[i];
        }
    }
    return min;
}

int srednia(int *tab, int size) {
    int i, suma = 0;
    for (i = 1; i < size; i++) {
        suma += tab[i];
    }
    return suma / size;
}

int mediana(int *tab, int size) {
    int temp[size], i, j;
    memcpy(temp, tab, size * sizeof(tab[0]));

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                int t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }
    return (temp[49] + temp[50]) / 2;
}

int main() {
    struktura *p_struct = (struktura *) malloc(sizeof(struktura));
    wypelnienie(p_struct->mTab, sizeof(p_struct->mTab) / sizeof(p_struct->mTab[0]));
    p_struct->max = max(p_struct->mTab, sizeof(p_struct->mTab) / sizeof(p_struct->mTab[0]));
    p_struct->min = min(p_struct->mTab, sizeof(p_struct->mTab) / sizeof(p_struct->mTab[0]));
    p_struct->srednia = srednia(p_struct->mTab, sizeof(p_struct->mTab) / sizeof(p_struct->mTab[0]));
    p_struct->mediana = mediana(p_struct->mTab, sizeof(p_struct->mTab) / sizeof(p_struct->mTab[0]));
    int again = 1;
    while (again) {
        system("cls");
        int wybor;
        printf("\nAplikacja proba losowa 100 elementow\n");
        printf(
            "1- wyswietl wygenerowane wartosci losowe\n2-wartosc max\n3-wartosc min\n4-srednia z proby\n5-mediana z proby\n6-wszystkie obliczone dane\n0-zamknij aplikacje\nWybrana funkcja:");
        scanf("%d", &wybor);
        printf("\n");
        switch (wybor) {
            case 1:
                printf("Wygenerowane wartosci losowe:\n");
                int i;
                for (i = 0; i < 100; i++) {
                    printf("%d, ", p_struct->mTab[i]);
                    if (i % 9 == 0) {
                        printf("\n");
                    }
                }
                break;
            case 2:
                printf("Wartosc max wynosi: %d\n", p_struct->max);
                break;
            case 3:
                printf("Wartosc min wynosi: %d\n", p_struct->min);
                break;
            case 4:
                printf("Wartosc sredniej wynosi: %d\n", p_struct->srednia);
                break;
            case 5:
                printf("Wartosc medniany wynosi: %d\n", p_struct->mediana);
                break;
            case 6:
                printf("Wartosc max wynosi: %d\n", p_struct->max);
                printf("Wartosc min wynosi: %d\n", p_struct->min);
                printf("Wartosc sredniej wynosi: %d\n", p_struct->srednia);
                printf("Wartosc medniany wynosi: %d\n", p_struct->mediana);
                printf("Wygenerowane wartosci losowe:\n");
                for (i = 0; i < 100; i++) {
                    printf("%d, ", p_struct->mTab[i]);
                    if (i % 9 == 0) {
                        printf("\n");
                    }
                }
                break;
            case 0:
                again = 0;
                break;
            default:
                printf("Podaj poprawny numer opcji\n");
        }
        system("pause");
    }
    free(p_struct);
    return 0;
}
