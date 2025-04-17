#include <stdio.h>
#include <stdlib.h>
//#include "redBlack.h"

int main(){
    char op;
    int key;

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
    return 0;
}
