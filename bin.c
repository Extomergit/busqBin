#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct arvore arvore;

struct arvore {
    int num;
    arvore *esquerda;
    arvore *direita;
};

arvore *inicializa();

arvore *cria_arv();

arvore *insere(arvore *raiz, int num);

void imprime(arvore *raiz);

void lib_arv(arvore *raiz);

int arv_bin_check(struct arvore *raiz);


void main() {
	
    arvore *raiz = inicializa();
	
    raiz = insere(raiz, 14);
	
    raiz = insere(raiz, 20);
	
    raiz = insere(raiz, 26);
	
    raiz = insere(raiz, 12);
	
    raiz = insere(raiz, 5);

    imprime(raiz);
    printf("\n");

    if (arv_bin_check(raiz)) {
        printf("Arvore de busca binaria\n");
	}
    else {
        printf("Esta arvore nao e de busca binaria\n");
	}
    free(raiz);
}


arvore *inicializa() {
    return NULL;
}

arvore *cria_arv() {
	
    arvore* raiz = (arvore*) malloc(sizeof(arvore));
	
    raiz->num = 0;
	
    raiz->esquerda = NULL;
	
    raiz->direita = NULL;
	
    return raiz;
}

arvore *insere(arvore *raiz, int num) {
	
    if(raiz == NULL) {
		
        arvore* raiz = (arvore*) malloc(sizeof(arvore));
		
        raiz->num = num;
		
        raiz->esquerda = NULL;
		
        raiz->direita = NULL;
		
        return raiz;
    }
    else {
		
        if(num > raiz->num) {
			
            raiz->direita = insere(raiz->direita, num);
		}
		
        if(num < raiz->num) {
			
            raiz->esquerda = insere(raiz->esquerda, num);
		}
    }
	
    return raiz;
}

void imprime(arvore *raiz) {
    if (raiz != NULL) {
		
        printf("%d\t", raiz->num);
		
        imprime(raiz->esquerda);
		
        imprime(raiz->direita);
    }
}

void lib_arv(arvore *raiz) {
    if (raiz != NULL) {
		
        lib_arv(raiz->esquerda);
		
        lib_arv(raiz->direita);
		
        lib_arv(raiz);
    }
}

int arv_bin_check(struct arvore *raiz) {
    arvore *anterior = NULL;
    if (raiz) {
        if (!arv_bin_check(raiz->esquerda)) {
            return false;
		}
        if (anterior != NULL && raiz->num <= anterior->num) {
            return false;
		}
		
        anterior = raiz;
		
        return arv_bin_check(raiz->direita);
    }
	
    return true;
}
