#include <stdio.h>
#include <stdlib.h>
//#include "redBlack.h"

void print_tree(struct tree* tree){
    return;
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
            break;
        }
    }

    print_tree(tree);
    return 0;
}
