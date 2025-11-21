#include <stdio.h>
#include <string.h>

#define ROZMIAR 11

int main() {
    char cokolwiek[ROZMIAR];
    char odczyt[ROZMIAR];
    FILE *plik;

    printf("Wpisz cokolwiek (max %d znakow): ", ROZMIAR - 1);
    fgets(cokolwiek, ROZMIAR, stdin);

    // Sprawdzenie, czy tekst zmieścil się w buforze
    if (strchr(cokolwiek, '\n') == NULL) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);  // czyszczenie bufora wejsciowego
    } else {
        // Usuwanie znaku "\n", jesli zostal wczytany
        cokolwiek[strcspn(cokolwiek, "\n")] = '\0';
    }

    // Zapis wprowadzonych danych do pliku
    plik = fopen("dane.txt", "w");
    if (plik == NULL) {
        printf("Blad otwarcia pliku do zapisu.\n");
        return 1;
    }
    fprintf(plik, "%s", cokolwiek);
    fclose(plik);

    // Odczyt z pliku
    plik = fopen("dane.txt", "r");
    if (plik == NULL) {
        printf("Blad otwarcia pliku do odczytu.\n");
        return 1;
    }
    fgets(odczyt, ROZMIAR, plik);
    fclose(plik);

    printf("Dane zapisane w pliku: %s\n", odczyt);

    return 0;
}
