#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct No {
    int dado;
    struct No* esquerda;
    struct No* direita;
    int altura;
} No;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int altura(No* no) {
    if (no == NULL)
        return 0;
    return no->altura;
}

No* novoNo(int dado) {
    No* no = (No*)malloc(sizeof(No));
    no->dado = dado;
    no->esquerda = NULL;
    no->direita = NULL;
    no->altura = 1;
    return no;
}

No* rotacaoDireita(No* y) {
    No* x = y->esquerda;
    No* T2 = x->direita;

    x->direita = y;
    y->esquerda = T2;

    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;
    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;

    return x;
}

No* rotacaoEsquerda(No* x) {
    No* y = x->direita;
    No* T2 = y->esquerda;

    y->esquerda = x;
    x->direita = T2;

    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;
    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;

    return y;
}

int pegarBalanceamento(No* no) {
    if (no == NULL)
        return 0;
    return altura(no->esquerda) - altura(no->direita);
}

No* inserir(No* no, int dado) {
    if (no == NULL)
        return novoNo(dado);

    if (dado < no->dado)
        no->esquerda = inserir(no->esquerda, dado);
    else if (dado > no->dado)
        no->direita = inserir(no->direita, dado);
    else
        return no;

    no->altura = 1 + max(altura(no->esquerda), altura(no->direita));

    int balance = pegarBalanceamento(no);

    if (balance > 1 && dado < no->esquerda->dado)
        return rotacaoDireita(no);

    if (balance < -1 && dado > no->direita->dado)
        return rotacaoEsquerda(no);

    if (balance > 1 && dado > no->esquerda->dado) {
        no->esquerda = rotacaoEsquerda(no->esquerda);
        return rotacaoDireita(no);
    }

    if (balance < -1 && dado < no->direita->dado) {
        no->direita = rotacaoDireita(no->direita);
        return rotacaoEsquerda(no);
    }

    return no;
}

No* encontrarMenorNo(No* no) {
    No* atual = no;

    while (atual->esquerda != NULL)
        atual = atual->esquerda;

    return atual;
}

No* removerNo(No* raiz, int dado) {
    if (raiz == NULL)
        return raiz;

    if (dado < raiz->dado)
        raiz->esquerda = removerNo(raiz->esquerda, dado);
    else if (dado > raiz->dado)
        raiz->direita = removerNo(raiz->direita, dado);
    else {
        if ((raiz->esquerda == NULL) || (raiz->direita == NULL)) {
            No* temp = raiz->esquerda ? raiz->esquerda : raiz->direita;

            if (temp == NULL) {
                temp = raiz;
                raiz = NULL;
            } else
                *raiz = *temp;

            free(temp);
        } else {
            No* temp = encontrarMenorNo(raiz->direita);
            raiz->dado = temp->dado;
            raiz->direita = removerNo(raiz->direita, temp->dado);
        }
    }
    if (raiz == NULL)
        return raiz;
    raiz->altura = 1 + max(altura(raiz->esquerda), altura(raiz->direita));
    int balance = pegarBalanceamento(raiz);
    if (balance > 1 && pegarBalanceamento(raiz->esquerda) >= 0)
        return rotacaoDireita(raiz);
    if (balance > 1 && pegarBalanceamento(raiz->esquerda) < 0) {
        raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
        return rotacaoDireita(raiz);
    }
    if (balance < -1 && pegarBalanceamento(raiz->direita) <= 0)
        return rotacaoEsquerda(raiz);
    if (balance < -1 && pegarBalanceamento(raiz->direita) > 0) {
        raiz->direita = rotacaoDireita(raiz->direita);
        return rotacaoEsquerda(raiz);
    }
    return raiz;
}

No* buscar(No* raiz, int dado) {
    if (raiz == NULL || raiz->dado == dado)
        return raiz;

    if (raiz->dado < dado)
        return buscar(raiz->direita, dado);

    return buscar(raiz->esquerda, dado);
}

void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf("%d ", raiz->dado);
        emOrdem(raiz->direita);
    }
}

int main() {
    No* raiz = NULL;
    clock_t inicio, fim;
    double tempoDecorrido;

    int elemento = 30 ; // trocar o elemento para um numero dentro do loop para ver a diferença no tempo de execução do algoritmo.
    int elementoEncontrado = 4;

    //Descomentar trecho de código abaixo ao trocar o elemento para ver a diferença de tempo de execução na remoção

    int i;
    for (i = 100; i >= 1; i--) {
        raiz = inserir(raiz, i);
    }

    printf("Percurso em ordem da árvore AVL: ");
    emOrdem(raiz);
    printf("\n");

    inicio = clock();
    raiz = removerNo(raiz, elemento);
    fim = clock();

    tempoDecorrido = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo de execução da remoção: %.6f segundos\n", tempoDecorrido);

    printf("Percurso em ordem após a remoção do elemento: %d ", elemento);
    printf("\n");
    emOrdem(raiz);
    printf("\n");

    No* encontrado = buscar(raiz, elementoEncontrado);
    if (encontrado != NULL){
        printf("Elemento %d encontrado na árvore AVL\n", elementoEncontrado);
    } else {
        printf("Elemento %d não encontrado na árvore AVL\n", elementoEncontrado);
    }

    return 0;
}
