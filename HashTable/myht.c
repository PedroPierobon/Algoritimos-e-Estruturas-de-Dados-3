#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include "hashTable.h"

int main (int argc, char *argv[]) {
    char option = getopt(argc, argv, "h");
    if (option == 'h') {
        printf("Nome: Pedro Pierobon\n");
        printf("GRR: GRR20241729\n");
        printf("login: ppm24\n");
        printf("Nome: Pedro Endrigo\n");
        printf("GRR: GRR20240956\n");
        printf("login: pesps24\n");
    }else{
        char op;
        int key;
        while (scanf(" %c %d", &op, &key) == 2){
            switch (op) {
                case 'i':
                    printf("Inserindo %d\n", key);
                    break;
                case 'r':
                    printf("Removendo %d\n", key);
                    break;
                default:
                    printf("INVÁLIDO");
                    break;
            }
        }
    }
    return 0;
}