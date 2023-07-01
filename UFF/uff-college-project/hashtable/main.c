#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct aluno {
    int matricula;
    float cr;
} TAluno;

typedef TAluno *Hash; // Hash é um vetor que será alocado dinamicamente

TAluno *aloca(int mat, float cr) {
    TAluno *novo = (TAluno *)malloc(sizeof(TAluno));
    novo->matricula = mat;
    novo->cr = cr;
    return novo;
}

void inicializa(Hash *tab, int m) {
    int i;
    for (i = 0; i < m; i++) {
        tab[i] = NULL;
    }
}

int hash_linha(int mat, int m) {
    return mat % m;
}

int hash(int mat, int m, int k) {
    return (hash_linha(mat, m) + k * k) % m; // Tratamento de colisão quadrática
}

void libera(Hash *tab, int m) {
    int i;
    for (i = 0; i < m; i++) {
        if (tab[i]) {
            free(tab[i]);
        }
    }
}

int busca(Hash *tab, int m, int mat, int *achou) {
    *achou = 0;
    int end = -1;
    int pos_livre = -1;
    int k = 0;
    while (k < m) {
        end = hash(mat, m, k);
        if (tab[end] != NULL && tab[end]->matricula == mat) {
            *achou = 1;
            k = m; // Força saída do loop
        } else {
            if (tab[end] == NULL) {
                if (pos_livre == -1) {
                    pos_livre = end;
                }
            }
            k = k + 1;
        }
    }
    if (*achou) {
        return end;
    } else {
        return pos_livre;
    }
}

void insere(Hash *tab, int m, int mat, float cr) {
    int achou;
    int end = busca(tab, m, mat, &achou);
    if (!achou) {
        if (end != -1) {
            tab[end] = aloca(mat, cr);
        } else {
            printf("A tabela esta cheia. Ocorreu overflow. Insercao nao realizada!\n");
        }
    } else {
        printf("Matricula ja existe. Insercao invalida!\n");
    }
}

void exclui(Hash *tab, int m, int mat) {
    int achou;
    int end = busca(tab, m, mat, &achou);
    if (achou) {
        free(tab[end]);
        tab[end] = NULL;
        printf("Matricula %d removida.\n", mat);
    } else {
        printf("Matricula nao encontrada. Remocao nao realizada!\n");
    }
}

void imprime(Hash *tab, int m) {
    int i, h;
    for (i = 0; i < m; i++) {
        h = i;
        printf("%d:\n", h);
        if (tab[h] != NULL) {
            TAluno *p = tab[h];
            printf("\tMatricula: %d\n", p->matricula);
            printf("\tCR: %.2f\n", p->cr);
        }
    }
}

void imprime_tabela(Hash *tab, int m) {
    printf("Tabela:\n");
    imprime(tab, m);
    printf("\n");
}

int main() {
    int m = 5; // Tamanho da tabela hash
    int n = 5; // Quantidade de matrículas

    Hash *tab = malloc(m * sizeof(Hash));
    inicializa(tab, m);

    int matriculas[] = {123, 456, 789, 234, 567};
    float crs[] = {7.5, 8.0, 9.2, 6.7, 8.5};

    int i;
    clock_t start_time, end_time;
    double cpu_time_used;

    start_time = clock();

    for (i = 0; i < n; i++) {
        int mat = matriculas[i];
        float cr = crs[i];
        insere(tab, m, mat, cr);
        imprime_tabela(tab, m);
    }

    end_time = clock();
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %f segundos\n", cpu_time_used);

    printf("Tabela antes da remocao:\n");
    imprime_tabela(tab, m);

    int matriculas_remover[] = {123, 789}; // Matrículas a serem removidas
    int num_matriculas_remover = sizeof(matriculas_remover) / sizeof(matriculas_remover[0]);

    start_time = clock();

    for (i = 0; i < num_matriculas_remover; i++) {
        int mat = matriculas_remover[i];
        exclui(tab, m, mat);
    }

    end_time = clock();
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %f segundos\n", cpu_time_used);

    printf("Tabela após a remocao:\n");
    imprime_tabela(tab, m);

    libera(tab, m);
    return 0;
}
