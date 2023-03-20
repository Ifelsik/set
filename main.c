#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define BASE_STRING_LEN 10
#include "set.c"

//  Ввод элемента
char *enter() {
    int64_t len = BASE_STRING_LEN;
    char *str = malloc(sizeof(char) * (len + 1));
    char character;
    int64_t str_size = 0;
    for(;(character = getchar()) != '\n' && character != '\r'; str_size++) {
        if (str_size + 1 >= len) {
            len = 2 * str_size + 1;
            str = realloc(str, len);
        }
        str[str_size] = character;
    }
    char *exit = malloc(sizeof(char) * (str_size + 1));
    for (int64_t i = 0; i < str_size; i++) {
        exit[i] = str[i];
    }
    exit[str_size] = '\0';
    free(str);
    return exit;
}


// Задание множества
tNode* establish(tNode *set) {
    int64_t elements;
    puts("Enter the number of elements:");
    scanf("%d", &elements);
    fflush(stdin);
    for (int64_t i = 0; i < elements; i++) {
        puts("Enter the element:");
        const char *element = enter();
        set = push(set, element);
    }
    return set;
}

// Выбор множества
tNode* operations(tNode *set) {
    puts("Enter:\n1 to add new element\n2 to delete\n3 to show the set\nS to interrupt");
    char opt;
    while ((opt = getchar()) != 'S') {
        fflush(stdin);
        switch (opt) {
            case '1':
                puts("Adding. Enter the element:");
                set = push(set, enter());
                break;
            case '2':
                puts("Deletion. Enter the element:");
                set = pop(set, enter());
                break;
            case '3':
                reveal(set);
                break;
            case 'S':
                puts("Interrupted");
            default:
                puts("Unsupported operation!\n");
        }
        puts("What's next?");
    }
    return set;
}


int64_t main() {
    tNode* set_A = NULL;
    tNode* set_B = NULL;

    puts("Enter the set A");
    set_A = establish(set_A);
    puts("Enter the set B");
    set_B = establish(set_B);

    puts("Choose the set A or B:");
    char set_literal = getchar();
    fflush(stdin);
    puts("What do you want to do?");
    switch (set_literal) {
        case 'A':
            set_A = operations(set_A);
            break;
        case 'B':
            set_B = operations(set_B);
            break;
        default:
            puts("Unsupported");
    }
    return 0;
}
