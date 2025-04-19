#include <stdio.h>
#include <stdlib.h>
#include "redBlack.h"

void r_remove(struct tree *t, int key){
    struct node *x = search(t->root, key, t);
    if(x == t->nil)
        return;
    rb_remove(t, x);
}

void insert(struct tree *t, int key){
    struct node *x = create_node(key, NULL, t);
    rb_insert(t, x);
}

int main(){
    char op;
    int key;
    struct tree *t = malloc(sizeof(struct tree));
    if(!t)
        perror("Falha na alocação\n");
    t->nil = malloc(sizeof(struct node));
    if(!t->nil)
        perror("Falha na alocação\n");

    t->nil->dad = t->nil;
    t->nil->left = t->nil;
    t->nil->right = t->nil;
    t->nil->color = 0;
    t->root = t->nil;



    while (scanf(" %c %d", &op, &key) == 2 && key != 111){
        switch (op)
        {
            case 'i':
                printf("Inserindo %d na RB\n", key);
                insert(t, key);
                break;

            case 'r':
                if(t->root == NULL)
                    perror("Árvore vazia");
                printf("Retirando %d na RB\n", key);
                r_remove(t, key);
                break;

            default:
                printf("INVÁLIDO");
                break;
        }
    }
    int h = 0;
    print_tree(t->root, h, t);
    rb_destroy(t->root, t);
    free(t->nil);
    free(t);
    return 0;
}
