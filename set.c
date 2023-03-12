#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define EXIST 1
#define DOES_NOT_EXIST 0

// Определим новый тип – tNode – узел списка
typedef struct sNode {
    struct sNode *next;  // Указатель на следующий элемент списка
    const char *value;  // Значение узла (элемента) списка
} tNode;

// Проверка на существование элемента
int find(tNode *begin, const char *value) {
    tNode *current = begin;
    while (current != NULL) {
        if (strcmp((*current).value, value) == 0) {
            return EXIST;
        }
        current = (*current).next;
    }
    return DOES_NOT_EXIST;
}

// Добавление нового элемента в список
void push(tNode **begin, const char *value) {
    if (!find(*begin, value)) {
        tNode *tmp = (tNode *) malloc(sizeof(tNode));  // Выделяем память для элемента списка
        (*tmp).value = value;  // Задаём значение элемента списка
        (*tmp).next = (*begin);  // Передаём значение указателя на предыдущий узел
        (*begin) = tmp;  // Теперь указатель на начало списка указывает на только что созданный узел
    }
}

// Вывод всех элементов списка
void reveal(tNode *begin) {
    while (begin != NULL) {
        printf("%s\n", (*begin).value);
        begin = (*begin).next;
    }
}

// Удаление элемента множества (по значению)
void del(tNode **begin, const char *value) {
    tNode *prev = NULL;
    tNode *current = (*begin);
    while (current != NULL) {
        if (strcmp((*current).value, value) == 0) {
            if (current == (*begin)) {
                *begin = (*current).next;
                free(current);
            } else {
                (*prev).next = (*current).next;
                free(current);
            }
            break;
        }
        prev = current;
        current = (*current).next;
    }
}
