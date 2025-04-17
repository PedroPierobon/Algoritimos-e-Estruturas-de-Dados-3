#include <stdio.h>
#include <stdlib.h>
#include "redBlack.h"

void remove(struct tree *t, int key){
    struct no *x = search(t->root, key);
    rb_remove(t, x);
}

void insert(struct tree *t, int key){
    struct no *x = create_nodo(key, NULL);
    rb_insert(t, x);
}

void rb_print(struct tree *t){
    // imprimir nodo, altura e cor
}

int main(){
    char op;
    int key;
    struct tree *tree;

    while (scanf(" %c %d", &op, &key) == 2){
        switch (op)
        {
            case 'i':
                printf("Inserindo %d na RB\n", key);
                break;

            case 'r':
                printf("Retirando %d na RB\n", key);
                break;

            default:
                printf("INVÁLIDO");
                break;
        }
    }

    rb_print(tree);
    return 0;
}
