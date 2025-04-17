#include <stdio.h>
#include <stdlib.h>


struct nodo {
    int chave;
    struct nodo *esq;
    struct nodo *dir;
    struct nodo *pai;
};

struct nodo *cria_nodo(int chave, struct nodo *pai){
    struct nodo *n = malloc(sizeof(struct nodo));
    n->chave = chave;
    n->esq = NULL;
    n->dir = NULL;
    n->pai = pai;
    
    return n;
}

//v2
// n é raiz
struct nodo *binary(struct nodo *raiz, struct nodo *pai, int chave){
    if(raiz == NULL)
        return cria_nodo(chave, pai);
    if(raiz->chave > chave){
        raiz->esq = binary(raiz->esq, raiz, chave);
    } else if(raiz->chave < chave){
        raiz->dir = binary(raiz->dir, raiz, chave);
    }
    return raiz;
}

struct nodo *busca(struct nodo *no, int chave){
    if(!no)
        return NULL;
    if(chave == no->chave)
        return no;
    if(chave < no->chave)
        return busca(no->esq, chave);
    return busca(no->dir, chave);
}




//
void printTree(struct nodo *raiz){
    if(raiz == NULL) return;
    printTree(raiz->esq);
    printf("%d ", raiz->chave);
    printTree(raiz->dir);
    return;
}

int main() {
    int n, chave;

    printf("Digite o tamanho da árvore: ");
    scanf("%d", &n);

    printf("Digite os valores: ");
    scanf("%d", &chave);
    // Cria raiz
    struct nodo *raiz = cria_nodo(chave, NULL);

    for(int i = 1; i < n; i++){
        scanf("%d", &chave);
        binary(raiz, NULL, chave);
    }

    printf("Aqui está sua árvore ordenada:\n");
    printTree(raiz);
    printf("\n");

    return 0;
}
