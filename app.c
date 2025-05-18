/*
Stanisław Fiedoruk, WCY24KY1S1
 Zajęcia: 13.05.2025 Rozliczenie: 20.05.2025
 Temat: Stos danych osobowych
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element {
    char imie[30];
    char nazwisko[30];
    struct Element *next;
} Element;

typedef struct {
    Element *top;
} Queue;

void init_queue(Queue *q) {
    printf("Inicjalizacja kolejki\n");
    q->top = NULL;
}

int is_empty(Queue *q) {
    // printf("Sprawdzenie czy kolejka jest pusta\n");
    return q->top == NULL;
}

void enqueue(Queue *q, char imie[30], char nazwisko[30]) {
    Element *el = (Element *) malloc(sizeof(Element));
    if (!el) {
        printf("Blad alokacji\n");
        return;
    }
    strcpy(el->imie, imie);
    strcpy(el->nazwisko, nazwisko);
    if (is_empty(q)) {
        el->next = NULL;
    } else {
        el->next = q->top;
    }
    q->top = el;
    printf("Dodano element do kolejki\n");
}

void dequeue(Queue *q) {
    if (is_empty(q)) {
        printf("Kolejka jest pusta, nie pobrano elementu\n");
        return;
    }
    Element *bye = q->top;
    printf("Pobrano element z kolejki:\n");
    printf("Imie: %s\nNazwisko: %s\n", q->top->imie, q->top->nazwisko);
    q->top = q->top->next;
    free(bye);
}

void peek(Queue *q) {
    if (is_empty(q)) {
        printf("Kolejka jest pusta\n");
        return;
    }
    printf("Pierwszy element w kolejce:\n");
    printf("Imie: %s\nNazwisko: %s\n", q->top->imie, q->top->nazwisko);
}

void flush_queue(Queue *q) {
    printf("Wyczyszczenie kolejki\n");
    while (q->top != NULL) {
        Element *bye = q->top;
        q->top = q->top->next;
        free(bye);
    }
}

void print_queue(Queue *q) {
    if (is_empty(q)) {
        printf("Kolejka jest pusta\n");
        return;
    }
    Element *temp = q->top;
    while (temp!=NULL) {
        printf("Imie: %s\nNazwisko: %s\n",temp->imie,temp->nazwisko);
        temp=temp->next;
    }
}

void menu() {
    printf("1. enqueue (dodaj element do kolejki)\n");
    printf("2. dequeue (pobierz element)\n");
    printf("3. peek (podejrzyj pierwszy element)\n");
    printf("4. flush_queue (wyczysc kolejke)\n");
    printf("5. print_stack (Wyswietl cala kolejke)\n");
    printf("0. Wyjscie\n");
    printf("Wybierz opcje: ");
}

int main() {
    Queue q;
    init_queue(&q);
    int opcja;
    do {
        menu();
        scanf("%d", &opcja);
        switch (opcja) {
            case 1:
                char imie[30], nazwisko[30];
                printf("Podaj imie: ");
                scanf("%s", imie);
                printf("Podaj nazwisko: ");
                scanf("%s", nazwisko);
                enqueue(&q, imie, nazwisko);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                peek(&q);
                break;
            case 4:
                flush_queue(&q);
                break;
            case 5:
                print_queue(&q);
                break;
            case 0:
                flush_queue(&q);
                printf("Koniec programu.\n");
                break;
            default:
                printf("Nieznana opcja. Spróbuj ponownie.\n");
        }
        printf("\n");
    } while (opcja != 0);

    return 0;
}
