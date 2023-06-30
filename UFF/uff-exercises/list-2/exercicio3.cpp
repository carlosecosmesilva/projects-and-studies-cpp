/*
(a) Escreva um algoritmo para computar a soma das folhas
(b) Escreva um algoritmo para efetuar um percurso de pós-ordem
(c) Escreva um algoritmo para efetuar um percurso de em-ordem
(d) Escreva um algoritmo para efetuar um percurso de pré-ordem
(e) Escreva um algoritmo para computar a altura de um dado nó
(f) Escreva um algoritmo para computar o fator de balanceamento de um
dado nó
(g) Escreva um algoritmo para percorrer a árvore em níveis
(h) Escreva um algoritmo para computar o produto dos nós
*/

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <queue>

class Arvore
{
public:
    No *raiz;
    Arvore() : raiz(nullptr){};
};

class No
{
public:
    int valor;
    No *esq;
    No *dir;
    No(int valor) : valor(valor), esq(nullptr), dir(nullptr){};
};

int somarFolhas(No *node)
{
    if (node == nullptr)
    {
        return 0;
    };
    if (node->esq == nullptr && node->dir == nullptr)
    {
        return 1;
    };

    return somarFolhas(node->esq + somarFolhas(node->dir));
};

int posOrdem(No *node)
{
    if (node == nullptr)
    {
        return 0;
    };
    posOrdem(node->esq);
    posOrdem(node->dir);
};

int emOrdem(No *node)
{
    if (node == nullptr)
    {
        return 0;
    };
    emOrdem(node->esq);
    printf("Nó visitado: ", node);
    emOrdem(node->dir);
};

int preOrdem(No *node)
{
    if (node == nullptr)
    {
        return 0;
    };
    printf("Nó visitado: ", node);
    preOrdem(node->esq);
    preOrdem(node->dir);
};

int computarAltura(No *node)
{
    if (node == nullptr)
    {
        return 0;
    };

    int alturaEsq = computarAltura(node->esq);
    int alturaDir = computarAltura(node->dir);

    return std::max(alturaEsq, alturaDir) + 1;
};

int fatorBalanceamento(No *node)
{
    if (node == nullptr)
    {
        return 0;
    };
    int alturaEsq = computarAltura(node->esq);
    int alturaDir = computarAltura(node->dir);

    return (alturaEsq - alturaDir);
};

int percorrerNiveis(Arvore arvore)
{
    if (arvore.raiz == nullptr)
    {
        return 0;
    };
    std::queue<No *> fila;
    fila.push(arvore.raiz);

    while (!fila.empty())
    {
        No *node = fila.front();
        fila.pop();

        std::cout << node->valor << " ";

        if (node->esq != nullptr)
        {
            fila.push(node->esq);
        }
        if (node->dir != nullptr)
        {
            fila.push(node->dir);
        }
    };
    std::cout << std::endl;
};

int calcularProduto(No *node)
{
    if (node == nullptr)
    {
        return 1;
    };

    int produtoEsq = calcularProduto(node->esq);
    int produtoDir = calcularProduto(node->dir);

    return node->valor * produtoEsq * produtoDir;
};

int main()
{
    Arvore arvore;
    arvore.raiz = new No(1);
    arvore.raiz->esq = new No(2);
    arvore.raiz->dir = new No(3);
    arvore.raiz->esq->esq = new No(4);
    arvore.raiz->esq->dir = new No(5);
    arvore.raiz->dir->esq = new No(6);
    arvore.raiz->dir->dir = new No(7);

    int soma = somarFolhas(arvore.raiz);
    printf("Soma das folhas: \n", soma);
    printf("\nPercurso em pré ordem: \n", preOrdem(arvore.raiz));
    printf("\nPercurso em ordem: \n", emOrdem(arvore.raiz));
    printf("\nPercurso em pós ordem: \n", posOrdem(arvore.raiz));
    printf("\nAltura da árvore: \n", computarAltura(arvore.raiz));

    int fator = fatorBalanceamento(arvore.raiz);
    printf("\nFator de balanceamento da raiz: \n", fator);

    printf("\nPercorrendo a árvore em níveis: \n", percorrerNiveis(arvore));

    int produto = calcularProduto(arvore.raiz);
    printf("\nProduto dos nós da árvore: \n", produto);

    return 0;
};