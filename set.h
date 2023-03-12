//
// Created by misha on 12.03.2023.
//

#ifndef SET_H
#define SET_H

typedef struct sNode tNode;

int find(tNode *begin, const char *value);

void push(tNode **begin, const char *value);

void reveal(tNode *begin);

void del(tNode **begin, const char *value);

#endif //SET_H
