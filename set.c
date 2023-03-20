#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define EXIST true
#define DOES_NOT_EXIST false

// Определим новый тип – tNode – узел списка
typedef struct sNode {
    struct sNode *next;  // Указатель на следующий элемент списка
    const char *value;  // Значение узла (элемента) списка
} tNode;

// Проверка на существование элемента
bool find(tNode *begin, const char *value) {
    tNode *current = begin;
    while (current != NULL) {
        if (strcmp(current->value, value) == 0) {
            return EXIST;
        }
        current = current->next;
    }
    return DOES_NOT_EXIST;
}

// Добавление нового элемента в список
tNode *push(tNode *begin, const char *value) {
    if (!find(begin, value)) {
        tNode *tmp = (tNode *) malloc(sizeof(tNode));  // Выделяем память для элемента списка
        tmp->value = value;  // Задаём значение элемента списка
        tmp->next = begin;  // Передаём значение указателя на предыдущий узел
        return tmp;  // Теперь указатель на начало списка указывает на только что созданный узел
    }
    return begin;
}

// Вывод всех элементов списка
void reveal(tNode *begin) {

    while (begin != NULL) {
        puts(begin->value);
        begin = begin->next;
    }
}

// Удаление элемента множества (по значению)
tNode *pop(tNode *begin, const char *value) {
    tNode *prev = NULL;
    tNode *current = begin;
    while (current != NULL) {
        if (strcmp(current->value, value) == 0) {
            if (current == begin) {
                begin = current->next;
                free(current);
            } else {
                prev->next = current->next;
                free(current);
            }
            return begin;
        }
        prev = current;
        current = current->next;
    }
    return begin;
}
