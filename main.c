#include <stdio.h>
#include <stdlib.h>

#include "set.c"

//  Ввод элемента
char* enter(){
    int len = 10;
    char *str = malloc(sizeof(char) * len);
    char character;
    int str_size = 0;
    while ((character = getchar()) != '\n' && character != '\r')
    {
        if (str_size + 1 >= len)
        {
            len = 2 * (str_size + 1);
            str = realloc(str, len);
        }
        str[str_size] = character;
        str_size++;
    }
    char *exit = malloc(sizeof(char) * (str_size + 1));
    for (int i = 0; i < str_size; i++) {
        exit[i] = str[i];
    }
    exit[str_size] = '\0';
    free(str);
    return exit;
}


// Задание множества
void establish(tNode **set) {
    int elements;
    printf("Enter the number of elements:\n");
    scanf("%d", &elements);
    fflush(stdin);
    for (int i = 0; i < elements; i++) {
        printf("Enter the element:\n");
        const char* element = enter();
        push(set, element);
    }
}

// Выбор множества
void operations(tNode **set) {
    printf("Enter:\n1 to add new element\n2 to delete\n3 to show the set\nS to interrupt\nC to change the set\n");
    while (1) {
        char opt = getchar();
        if (opt == 'S') {
            printf("Interrupted");
            break;
        }
        fflush(stdin);
        switch (opt) {
            case '1':
                printf("Adding. Enter the element:\n");
                push(set, enter());
                break;
            case '2':
                printf("Deletion. Enter the element:\n");
                del(set, enter());
                break;
            case '3':
                reveal(*set);
                break;
            case 'C':
                break;
            default:
                printf("Unsupported operation!\n");
        }
        printf("What's next?\n");
    }
}


int main() {
    tNode *set_A = NULL;
    tNode *set_B = NULL;

    printf("Enter the set A\n");
    establish(&set_A);
    printf("Enter the set B\n");
    establish(&set_B);

    printf("Choose the set A or B:\n");
    char set_literal = getchar();
    fflush(stdin);
    printf("What do you want to do?\n");
    switch (set_literal) {
        case 'A':
            operations(&set_A);
            break;
        case 'B':
            operations(&set_B);
            break;
        default:
            printf("Unsupported\n");
    }
    return 0;
}
