#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    double data;
    struct node *next;
}node;
typedef struct LIFO {
    node *top;
}LIFO;
void push(int dane, LIFO *lifo) {
    node *new_element=(node *)malloc(sizeof(node));
    if (!new_element) {
        printf("Blad alokacji");
        return;
    }
    new_element->data=dane;
    if (lifo->top==NULL) {
        new_element->next=NULL;
    }else {
        new_element->next=lifo->top;
    }
    lifo->top=new_element;
}
void pop (LIFO *q) {
    if (q->top==NULL) {
        printf("Kolejka jest pusta, nie pobrano elementu\n");
        return;
    }
    node *tmp=q->top;
    printf("%f",tmp->data);
    q->top=q->top->next;
    free(tmp);
}
