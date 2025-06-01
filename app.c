#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int arr_size = 0;
int arr_max_value = 99;

void textify(int *arr, int n, char *temp) {
    strcat(temp, "[");
    int i;
    for (i = 0; i < n; i++) {
        if (i != 0) {
            strcat(temp, ", ");
        }
        char a[20];
        sprintf(a, "%d", arr[i]);
        strcat(temp, a);
    }
    strcat(temp, "]");
}

void log(char message[40], int *arr) {
    FILE *file;
    char datetime[20];
    strftime(datetime, sizeof(datetime), "%Y-%m-%d %H:%M:%S", localtime(&(time_t){time(NULL)}));
    int *temp = (int *) malloc(arr_size*4);
    temp[0] = '\0';
    if (arr != NULL) {
        textify(arr, arr_size, temp);
    }
    file = fopen("log.txt", "a");
    if (file == NULL) {
        perror("Blad otwarcia pliku");
    }
    fprintf(file, "%s %s %s\n", datetime, message, temp);
    fclose(file);
    free(temp);
}


void clear_log() {
    FILE *file;
    file = fopen("log.txt", "w");
    if (file == NULL) {
        perror("Blad otwarcia pliku");
    }
    fprintf(file, "");
    fclose(file);
}

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
    log("Dane we: ", a);
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
                print_arr(a, n);
                log("", a);
            }
        }
    }
    log("Dane wy: ", a);
}


void selection_sort(int *a, int n) {
    log("Dane we:", a);
    int i, j;
    for (i = 0; i < n - 1; i++) {
        int min = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        printf("\t\t[i]=%i,[min_index]=%i\n", i, min);
        log("", a);
        if (a[i] > a[min]) {
            swap(&a[min], &a[i]);
        }
        print_arr(a, n);
    }
    log("Dane wy: ", a);
}

void insertion_sort(int *a, int n) {
    log("Dane we:", a);
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
        log("", a);
    }
    log("Dane wy: ", a);
}


int main() {
    log("Uruchomienie aplikacji",NULL);
    int opt = 1;
    printf("\n=== Podstawowe algorytmy sortowania ===\n");
    printf("Podaj rozmiar tablicy\n? > ");
    scanf("%d", &arr_size);
    char mess[arr_size * 8];
    sprintf(mess, "Wpisano rozmiar tablicy: %d", arr_size);
    log(mess,NULL);
    int *arr = (int *) malloc(arr_size * sizeof(int));
    while (opt != 0) {
        int opt = app_menu();
        switch (opt) {
            case 1:
                log("Wybrano sortowanie: bubble sort",NULL);
                fill_arr(arr, arr_size, arr_max_value);
                printf("We:\n");
                print_arr(arr, arr_size);
                printf("Sortowanie:\n");
                bubble_sort(arr, arr_size);
                printf("Wy:\n");
                print_arr(arr, arr_size);
                break;
            case 2:
                log("Wybrano sortowanie: selection sort",NULL);
                fill_arr(arr, arr_size, arr_max_value);
                printf("We:\n");
                print_arr(arr, arr_size);
                printf("Sortowanie:\n");
                selection_sort(arr, arr_size);
                printf("Wy:\n");
                print_arr(arr, arr_size);
                break;
            case 3:
                log("Wybrano sortowanie: insertion sort",NULL);
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
                log("Zamknięcie aplikacji\n",NULL);
                free(arr);
                return 0;
            default:
                printf("Nieprawidlowa opcja...\n");
        }
    }
}
