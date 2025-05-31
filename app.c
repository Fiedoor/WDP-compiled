#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void fill_arr(int *a, int n, int max) {
    srand(time(NULL));
    int i;
    for (i = 0; i < n; i++) {
        a[i] = rand() % (max + 1);
    }
}

void print_arr(int *a, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int app_menu() {
    int a;
    printf("1. Sortowanie babelkowe (bubble sort)\n");
    printf("2. Sortowanie przez wybieranie (selection sort)\n");
    printf("3. Sortowanie przez wstawianie (insertion sort)\n");
    printf("4. clear log\n");
    printf("0. Zakoncz\n");
    printf("Wybierz opcje: ");
    scanf("%d", &a);
    return a;
}

void bubble_sort(int *a, int n) {
    print_arr(a, n);
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
                print_arr(a, n);
            }
        }
    }
}


void selection_sort(int *a, int n) {
    print_arr(a, n);
    int i, j;
    for (i = 0; i < n - 1; i++) {
        int min = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        printf("\t\t[i]=%i,[min_index]=%i\n", i, min);
        if (a[i] > a[min]) {
            swap(&a[min], &a[i]);
        }
        print_arr(a, n);
    }
}

void insertion_sort(int *a, int n) {
    int i;
    for (i = 0; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
        print_arr(a, n);
    }
}
void log(char message[40]) {
    FILE *file;
    char datetime[20];
    strftime(datetime, sizeof(datetime), "%Y-%m-%d %H:%M:%S", localtime(&(time_t){time(NULL)}));
    file=fopen("log.txt","w");
    if (file == NULL ) {
        perror("Blad otwarcia pliku");
    }
    fprintf(file,"%s %s\n",datetime,message);
    fclose(file);
}
void clear_log() {

}

int main() {
    log("Uruchomienie aplikacji");
    int arr_size = 0;
    int arr_max_value = 99;
    int opt = 1;

    printf("\n=== Podstawowe algorytmy sortowania ===\n");

    printf("Podaj rozmiar tablicy\n? > ");
    scanf("%d", &arr_size);
    int *arr = (int *) malloc(arr_size * sizeof(int));
    while (opt != 0) {
        int opt = app_menu();
        switch (opt) {
            case 1:
                fill_arr(arr, arr_size, arr_max_value);
                printf("We:\n");
                print_arr(arr, arr_size);
                printf("Sortowanie:\n");
                bubble_sort(arr, arr_size);
                printf("Wy:\n");
                print_arr(arr, arr_size);
                break;
            case 2:
                fill_arr(arr, arr_size, arr_max_value);
                printf("We:\n");
                print_arr(arr, arr_size);
                printf("Sortowanie:\n");
                selection_sort(arr, arr_size);
                printf("Wy:\n");
                print_arr(arr, arr_size);
                break;
            case 3:
                fill_arr(arr, arr_size, arr_max_value);
                printf("We:\n");
                print_arr(arr, arr_size);
                printf("Sortowanie:\n");
                insertion_sort(arr, arr_size);
                printf("Wy:\n");
                print_arr(arr, arr_size);
                break;
            case 4:
                clear_log();
                break;
            case 0:
                free(arr);
                return 0;
            default:
                printf("Nieprawidlowa opcja...\n");
        }
    };
}
