#include <limits>
#include <stack>

class PilhaMin {
private:
  std::stack<int> pilha;
  std::stack<int> pilhaMin;

public:
  int topo() {
    if (pilha.empty()) {
      throw std::runtime_error("Pilha vazia: não é possível obter o topo.");
    }
    return pilha.top();
  }

  int desempilha() {
    if (pilha.empty()) {
      throw std::runtime_error("Pilha vazia: não é possível desempilhar.");
    }
    int elemento = pilha.top();
    pilha.pop();
    pilhaMin.pop(); // Remove o correspondente da pilhaMin
    return elemento;
  }

  void empilha(int t) {
    pilha.push(t);
    if (pilhaMin.empty() || t <= pilhaMin.top()) {
      pilhaMin.push(t);
    }
  }

  int obterMinimo() {
    if (pilhaMin.empty()) {
      throw std::runtime_error("Pilha vazia: não é possível obter o mínimo.");
    }
    return pilhaMin.top();
  }
};

template <typename Pilha, typename Tipo>
concept bool PilhaTAD = requires(Pilha p, Tipo t) {
                          { p.topo() } -> std::same_as<Tipo &>;
                          { p.desempilha() } -> std::same_as<Tipo>;
                          { p.empilha(t) };
                          { p.obterMinimo() } -> std::same_as<Tipo &>;
                        };

static_assert(PilhaTAD<PilhaMin, int>);
