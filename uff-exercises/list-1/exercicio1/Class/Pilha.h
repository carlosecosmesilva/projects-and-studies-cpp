//
// Created by cadu on 24/05/23.
//

#ifndef UNTITLED_PILHA_H
#define UNTITLED_PILHA_H


#include "Deque.h"

class Pilha {
    private:
        Deque d;
    public:
    char topo() const {
        return d.inicio();
    }

    void empilha(char elemento) {
        d.insereInicio(elemento);
    }

    char desempilha() {
        return d.removeInicio();
    }
};

static_assert(std::is_same_v<Pilha, Pilha>, "O tipo fornecido não corresponde à classe Deque.");

#endif //UNTITLED_PILHA_H
