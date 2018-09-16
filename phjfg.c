#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    int info;
    struct elemento *esquerda;
    struct elemento *direita;
}elemento;

elemento* criarArvore(int num){
    elemento* raiz = (elemento*)malloc(sizeof(elemento));

    raiz->info = num;
    raiz->esquerda=NULL;
    raiz->direita=NULL;

    return raiz;
}

elemento* inserir(elemento* arvore, int num){
    if(arvore==NULL){
        arvore = criarArvore(num);
    }else if(num<=arvore->info){
        arvore->esquerda = inserir(arvore->esquerda, num);
    }else if(num>arvore->info){
        arvore->direita = inserir(arvore->direita, num);
    }

    return arvore;
}

void preOrdem(elemento *arvore){
    if(arvore != NULL){
        printf(" %d", arvore->info);
        preOrdem(arvore->esquerda);
        preOrdem(arvore->direita);
    }
}

void inOrdem(elemento* arvore){
    if(arvore != NULL){
        inOrdem(arvore->esquerda);
        printf(" %d", arvore->info);
        inOrdem(arvore->direita);
    }
}

void posOrdem(elemento* arvore){
    if(arvore != NULL){
        posOrdem(arvore->esquerda);
        posOrdem(arvore->direita);
        printf(" %d", arvore->info);
    }
}
int main(){
    int c, n, num;
    elemento* arvore;
    
    scanf("%d", &c);
    for(int i = 1; i<=c; i++){
        
        scanf("%d", &n);
        scanf("%d", &num);
        elemento* arvore = criarArvore(num);
        for(int j = 1; j<n; j++){
            scanf("%d", &num);      
            inserir(arvore, num);
        } 
        printf("Case %d:\n", i);
        printf("Pre.:");
        preOrdem(arvore); 
        printf("\n"); 
        printf("In..:");
        inOrdem(arvore);
        printf("\n");
        printf("Post:");
        posOrdem(arvore);   
        printf("\n\n");
        }

    return 0;
}