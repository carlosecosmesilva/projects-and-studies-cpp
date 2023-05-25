#include <iostream>
#include <stack>

class Fila2P {
private:
  std::stack<char> p1;
  std::stack<char> p2;

public:
  void enfileira(char elemento) { p1.push(elemento); }

  char desenfileira() {
    if (p1.empty() && p2.empty()) {
      throw std::runtime_error("Fila vazia: não é possível desenfileirar.");
    }

    if (p2.empty()) {
      while (!p1.empty()) {
        p2.push(p1.top());
        p1.pop();
      }
    }

    char elemento = p2.top();
    p2.pop();
    return elemento;
  }

  char frente() const {
    if (p1.empty() && p2.empty()) {
      throw std::runtime_error("Fila vazia: não é possível obter a frente.");
    }

    if (p2.empty()) {
      while (!p1.empty()) {
        p2.push(p1.top());
        p1.pop();
      }
    }

    return p2.top();
  }
};

template <typename Fila, typename Tipo>
concept bool FilaTAD = requires(Fila f, Tipo t) {
                         { f.enfileira(t) };
                         { f.desenfileira() } -> std::same_as<Tipo>;
                         { f.frente() } -> std::same_as<Tipo &>;
                       };

static_assert(FilaTAD<Fila2P, char>);

int main() {
  Fila2P fila;
  fila.enfileira('A');
  fila.enfileira('B');
  std::cout << "Frente: " << fila.frente() << std::endl;
  fila.desenfileira();
  std::cout << "Frente: " << fila.frente() << std::endl;
  return 0;
}
