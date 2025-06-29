#include <stdio.h>
#include <stdlib.h>
typedef struct element {
  	struct element *prev;
    double e;
    struct element *next;
} NODE;
typedef struct {
    NODE *front;
    NODE *rear;
} kolejka;
void enqueue(kolejka *q, double value) {
    NODE *new_element = (NODE *)malloc(sizeof(NODE));
    if (!new_element) {
        printf("Błąd alokacji pamięci!\n");
        return;
    }
    new_element->e = value;
    new_element->next = q->rear;
    new_element->prev=NULL;
    if (q->front == NULL) {
        q->front = new_element;
        q->rear  = new_element;
    }
    else {
        q->rear->prev = new_element;
        q->rear = new_element;
    }
    printf("Dodano %f do kolejki.\n", value);
}
void dequeue(kolejka *q) {
    if (q->front == NULL) {
        printf("Kolejka jest pusta.\n");
        return;
    }
    NODE *temp = q->front;
    printf("Usunięto: %f\n", temp->e);
    q->front = q->front->prev;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
}