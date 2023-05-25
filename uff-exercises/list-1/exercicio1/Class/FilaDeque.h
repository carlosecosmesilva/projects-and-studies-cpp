//
// Created by cadu on 24/05/23.
//

#ifndef UNTITLED_FILADEQUE_H
#define UNTITLED_FILADEQUE_H


#include <type_traits>
#include "Deque.h"

class FilaDeque {
private:
    Deque d;

public:
    void enfileira(char elemento) {
        d.insereFim(elemento);
    }

    char desenfileira() {
        return d.removeInicio();
    }

    char frente() const {
        return d.inicio();
    }
};

static_assert(std::is_same_v<FilaDeque, FilaDeque>, "O tipo fornecido não corresponde à classe Deque.");

#endif //UNTITLED_FILADEQUE_H
