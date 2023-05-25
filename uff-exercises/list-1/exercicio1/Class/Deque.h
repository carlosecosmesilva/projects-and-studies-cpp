//
// Created by cadu on 24/05/23.
//
#include <iostream>
#ifndef UNTITLED_DEQUE_H
#define UNTITLED_DEQUE_H


class Deque {
private:
    struct Node {
        char data;
        Node* prev;
        Node* next;
    };

    Node* head;
    Node* tail;

public:
    Deque() : head(nullptr), tail(nullptr) {}

    char inicio() const {
        if (head != nullptr) {
            return head->data;
        }
        throw std::runtime_error("Deque vazio: não é possível obter o elemento do início.");
    }

    char fim() const {
        if (tail != nullptr) {
            return tail->data;
        }
        throw std::runtime_error("Deque vazio: não é possível obter o elemento do fim.");
    }

    void insereInicio(char elemento) {
        Node* newNode = new Node{elemento, nullptr, head};
        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
    }

    void insereFim(char elemento) {
        Node* newNode = new Node{elemento, tail, nullptr};
        if (tail != nullptr) {
            tail->next = newNode;
        } else {
            head = newNode;
        }
        tail = newNode;
    }

    char removeInicio() {
        if (head != nullptr) {
            char elemento = head->data;
            Node* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
            delete temp;
            return elemento;
        }
        throw std::runtime_error("Deque vazio: não é possível remover o elemento do início.");
    }

    char removeFim() {
        if (tail != nullptr) {
            char elemento = tail->data;
            Node* temp = tail;
            tail = tail->prev;
            if (tail != nullptr) {
                tail->next = nullptr;
            } else {
                head = nullptr;
            }
            delete temp;
            return elemento;
        }
        throw std::runtime_error("Deque vazio: não é possível remover o elemento do fim.");
    }
};

static_assert(std::is_same_v<Deque, Deque>, "O tipo fornecido não corresponde à classe Deque.");

#endif //UNTITLED_DEQUE_H
