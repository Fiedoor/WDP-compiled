#include <stdio.h>

int main(void) {
    FILE *plik;
    if ((plik = fopen("liczby.txt", "a")) == NULL) {
        perror("Blad otwarcia pliku.");
        fclose(plik);
        return 1;
    }
    int ile = 0;
    int liczba = 0;
    printf("Ile liczb chcesz wpisac? ");
    scanf("%i",&ile);
    for(int i = 0; i < ile; i++) {
        printf("Liczba %i: ",i+1);
        scanf("%i",&liczba);
        plik = fopen("liczby.txt","a");
        fprintf(plik,"%i\n",liczba);
        fclose(plik);
    }
    return 0;
}