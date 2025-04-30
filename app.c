/*
 Stanisław Fiedoruk, WCY24KY1S1
 Zajęcia: 29.04.2025 Rozliczenie: 06.05.2025
 Temat: Program obliczający dane na podstawie próby losowej
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//definicja struktury
typedef struct {
    int mTab[100]; //rozmiar tablicy wybrany przez autora
    int max;
    int min;
    int srednia;
    int mediana;
} struktura;

//funkcja wypełniająca tablicę wartościami losowymi z zakresu 1-100000 (decyzja autora)
void wypelnienie(int *tab, int size) {
    srand(time(NULL));
    int i;
    for (i = 0; i < size; i++) {
        tab[i] = 1 + rand() % 100000;
    }
}

//funkcja znajdująca iteracyjnie największy element tablicy
int max(int *tab, int size) {
    int i, max = tab[0];
    for (i = 1; i < size; i++) {
        if (tab[i] > max) {
            max = tab[i];
        }
    }
    return max;
}

//funkcja znajdująca iteracyjnie najmniejszy element tablicy
int min(int *tab, int size) {
    int i, min = tab[0];
    for (i = 1; i < size; i++) {
        if (tab[i] < min) {
            min = tab[i];
        }
    }
    return min;
}

//funkcja licząca średnią poprzez zsumowanie elementów i zwraca sumę podzieloną przez ilość elementów w tablicy
int srednia(int *tab, int size) {
    int i, suma = 0;
    for (i = 1; i < size; i++) {
        suma += tab[i];
    }
    return suma / size;
}

//funkcja licząca medianę
int mediana(int *tab, int size) {
    int temp[size], i, j;
    memcpy(temp, tab, size * sizeof(tab[0])); //tworzenie kopii tablicy podanej w parametrze funkcji
    for (i = 0; i < size - 1; i++) {
        //
        for (j = 0; j < size - i - 1; j++) {
            //
            if (temp[j] > temp[j + 1]) {
                //sortowanie bąbelkowo kopii
                int t = temp[j]; //
                temp[j] = temp[j + 1]; //
                temp[j + 1] = t; //
            }
        }
    }
    //funkcja zwraca medianę na podstawie średniej 2 elementów środkowych posortowanej tablicy
    return (temp[48] + temp[49]) / 2;
}

int main() {
    struktura *p_struct = (struktura *) malloc(sizeof(struktura)); //alokacja pamięci na strukturę
    wypelnienie(p_struct->mTab, sizeof(p_struct->mTab) / sizeof(p_struct->mTab[0]));
    p_struct->max = max(p_struct->mTab, sizeof(p_struct->mTab) / sizeof(p_struct->mTab[0]));
    p_struct->min = min(p_struct->mTab, sizeof(p_struct->mTab) / sizeof(p_struct->mTab[0]));
    p_struct->srednia = srednia(p_struct->mTab, sizeof(p_struct->mTab) / sizeof(p_struct->mTab[0]));
    p_struct->mediana = mediana(p_struct->mTab, sizeof(p_struct->mTab) / sizeof(p_struct->mTab[0]));
    //interfejs zrealizowany na pętli while przerywanej poprzez zmianę wartości zmiennej na 0 gdy użytkownik wybierze zakończenie programu
    int again = 1;
    while (again) {
        system("cls"); //czyszczenie konsoli w celu przejrzystości
        printf("\nAplikacja proba losowa 100 elementow\n");
        printf(
            "1- wyswietl wygenerowane wartosci losowe\n2-wartosc max\n3-wartosc min\n4-srednia z proby\n5-mediana z proby\n6-wszystkie obliczone dane\n0-zamknij aplikacje\nWybrana funkcja:");
        //wybór jest charem ponieważ gdy jest intem i wpiszemy literę nie zachodzi w switchu defeault a jakaś opcja
        char wybor;
        scanf("%c", &wybor);
        printf("\n");
        //switch obsługujący wszystkie możliwości wyboru oraz że użytkownik wpisze niepoprwany numer opcji
        switch (wybor) {
            case '1':
                printf("Wygenerowane wartosci losowe:\n");
                int i;
                for (i = 0; i < 100; i++) {
                    printf("%d, ", p_struct->mTab[i]);
                    if (i % 9 == 0) {
                        printf("\n");
                    }
                }
                break;
            case '2':
                printf("Wartosc max wynosi: %d\n", p_struct->max);
                break;
            case '3':
                printf("Wartosc min wynosi: %d\n", p_struct->min);
                break;
            case '4':
                printf("Wartosc sredniej wynosi: %d\n", p_struct->srednia);
                break;
            case '5':
                printf("Wartosc medniany wynosi: %d\n", p_struct->mediana);
                break;
            case '6':
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
            case '0':
                again = 0;
                break;
            default:
                printf("Podaj poprawny numer opcji\n");
        }
        fflush(stdin);
        system("pause");
    }
    free(p_struct);
    return 0;
}
