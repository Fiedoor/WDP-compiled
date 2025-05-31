#include <stdio.h>

int main() {
    int a = 42;
    char bufor[100];  // bufor na sformatowany tekst

    // Tworzymy gotowy lancuch znakow w buforze
    sprintf(bufor, "Wynik = %d\n", a);

    // Wypisujemy komunikat na ekran
    printf("%s", bufor);

    // Zapisujemy dane do pliku - to samo co na ekranie
    FILE *plik = fopen("wynik.txt", "w");
    if (plik == NULL) {
        perror("Blad otwarcia pliku");
        return 1;
    }
    fputs(bufor, plik);
    fclose(plik);

    return 0;
}
