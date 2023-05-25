#include <iostream>
#include <queue>

class Pilha2F {
private:
  std::queue<char> f1;
  std::queue<char> f2;

public:
  char topo() const {
    if (f1.empty() && f2.empty()) {
      throw std::runtime_error("Pilha vazia: não é possível obter o topo.");
    }
    if (f1.empty()) {
      while (f2.size() > 1) {
        f1.push(f2.front());
        f2.pop();
      }
      return f2.front();
    }
    return f1.back();
  }

  void empilha(char elemento) {
    if (!f1.empty()) {
      f1.push(elemento);
    } else {
      f2.push(elemento);
    }
  }

  char desempilha() {
    if (f1.empty() && f2.empty()) {
      throw std::runtime_error("Pilha vazia: não é possível desempilhar.");
    }
    char elemento;
    if (f1.empty()) {
      while (f2.size() > 1) {
        f1.push(f2.front());
        f2.pop();
      }
      elemento = f2.front();
      f2.pop();
    } else {
      while (f1.size() > 1) {
        f2.push(f1.front());
        f1.pop();
      }
      elemento = f1.front();
      f1.pop();
    }
    return elemento;
  }
};

template <typename Pilha, typename Tipo>
concept bool PilhaTAD = requires(Pilha p, Tipo t) {
                          { p.topo() } -> std::same_as<Tipo>;
                          { p.empilha(t) };
                          { p.desempilha() } -> std::same_as<Tipo>;
                        };

static_assert(PilhaTAD<Pilha2F, char>);

int main() {
  Pilha2F pilha;
  pilha.empilha('A');
  pilha.empilha('B');
  std::cout << "Topo: " << pilha.topo() << std::endl;
  pilha.desempilha();
  std::cout << "Topo: " << pilha.topo() << std::endl;
  return 0;
}
