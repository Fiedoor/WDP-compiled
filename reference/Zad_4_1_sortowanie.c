#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void fill_arr(int *a, int n, int max){
    srand(time(NULL));
    for(int i=0; i<n; i++){
        a[i] = rand() % (max +1);
    }
}

void print_arr(int *a, int n){
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void swap(int *a, int *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int app_menu(){
    int a;
    printf("1. Sortowanie babelkowe (bubble sort)\n");
    printf("2. Sortowanie przez wybieranie (selection sort)\n");
    printf("3. Sortowanie przez wstawianie (insertion sort)\n");
    printf("0. Zakończ\n");
    printf("Wybierz opcję: ");
    scanf("%d", &a);
    return a;
}

void bubble_sort(int *a, int n){
    printf("Zaimplementuj funkcje bubble_sort(int *a, int n)\n");
}


void selection_sort(int *a, int n) {
    printf("Zaimplementuj funkcje selection_sort(int *a, int n)\n");
}

void insertion_sort(int *a, int n) {
    printf("Zaimplementuj funkcje insertion_sort(int *a, int n)\n");
}


int main(){
    int arr_size = 0;
    int arr_max_value = 99;
    int opt = 1;

    printf("\n=== Podstawowe algorytmy sortowania ===\n");

    printf("Podaj rozmiar tablicy\n? > ");
    scanf("%d", &arr_size);
    int *arr = (int *)malloc(arr_size * sizeof(int));
    while(opt != 0){
        int opt = app_menu();
        switch(opt){
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
            case 0:
                free(arr);
                return 0;
            default:
                printf("Nieprawidlowa opcja...\n");
        }
    };
}
