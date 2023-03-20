//
// Created by misha on 12.03.2023.
//

#ifndef SET_H
#define SET_H

#include <stdbool.h>

typedef struct sNode tNode;

bool find(tNode *begin, const char *value);

tNode *push(tNode *begin, const char *value);

void reveal(tNode *begin);

tNode *pop(tNode *begin, const char *value);

#endif //SET_H
