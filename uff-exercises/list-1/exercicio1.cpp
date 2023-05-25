#include <iostream>
#include <stdlib.h>
#include <vector>

class Deque {
private:
  std::vector<char> deque;

public:
  char inicio() const {
    if (!deque.empty()) {
      return deque.front();
    }
    throw std::runtime_error(
        "Deque vazio: não é possível obter o elemento do início.");
  }

  char fim() const {
    if (!deque.empty()) {
      return deque.back();
    }
    throw std::runtime_error(
        "Deque vazio: não é possível obter o elemento do fim.");
  }

  void insereInicio(char elemento) { deque.insert(deque.begin(), elemento); }

  void insereFim(char elemento) { deque.push_back(elemento); }

  char removeInicio() {
    if (!deque.empty()) {
      char elemento = deque.front();
      deque.erase(deque.begin());
      return elemento;
    }
    throw std::runtime_error(
        "Deque vazio: não é possível remover o elemento do início.");
  }

  char removeFim() {
    if (!deque.empty()) {
      char elemento = deque.back();
      deque.pop_back();
      return elemento;
    }
    throw std::runtime_error(
        "Deque vazio: não é possível remover o elemento do fim.");
  }
};

static_assert(DequeTAD<Deque, char>);

int main() {
  Deque deque;
  deque.insereInicio('A');
  deque.insereFim('B');
  std::cout << "Início: " << deque.inicio() << std::endl;
  std::cout << "Fim: " << deque.fim() << std::endl;
  deque.removeInicio();
  deque.removeFim();
  return 0;
}
