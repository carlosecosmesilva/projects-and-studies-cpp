/* Na classe PilhaMin utiliza-se duas pilhas, uma para armazenar os elementos da pilha principal
e pilhaMinima para manter o mínimo atual.
O método empilha verifica se o elemento empilhado é menor ou igual ao mínimo atual
e atualiza a pilha auxiliar, se necessário */

#include <iostream>
#include <stack>

class PilhaMin
{
private:
  std::stack<int> pilha;       // pilha principal
  std::stack<int> pilhaMinima; // pilha auxiliar para manter o mínimo

public:
  int topo()
  {
    return pilha.top();
  }

  int desempilha()
  {
    int elemento = pilha.top();
    pilha.pop();

    // Verifica se o elemento removido é o mínimo atual
    if (elemento == pilhaMinima.top())
    {
      pilhaMinima.pop(); // Remove o mínimo da pilha auxiliar
    }

    return elemento;
  }

  void empilha(int t)
  {
    pilha.push(t);

    // Verifica se o elemento empilhado é o novo mínimo
    if (pilhaMinima.empty() || t <= pilhaMinima.top())
    {
      pilhaMinima.push(t); // Atualiza o mínimo na pilha auxiliar
    }
  }

  int obterMinimo()
  {
    return pilhaMinima.top();
  }
};

template <typename Pilha, typename Tipo>
concept bool PilhaTAD = requires(Pilha p, Tipo t) {
  {
    p.topo()
  } -> std::same_as<Tipo>;
  {
    p.empilha(t)
  };
  {
    p.desempilha()
  } -> std::same_as<Tipo>;
};

static_assert(PilhaTAD<PilhaMin, int>);

int main()
{
  PilhaMin pilha;
  pilha.empilha(3);
  pilha.empilha(1);
  pilha.empilha(5);
  pilha.empilha(2);

  std::cout << "Topo: " << pilha.topo() << std::endl;
  std::cout << "Mínimo: " << pilha.obterMinimo() << std::endl;

  pilha.desempilha();
  std::cout << "Topo: " << pilha.topo() << std::endl;
  std::cout << "Mínimo: " << pilha.obterMinimo() << std::endl;

  return 0;
}

/* A complexidade de tempo é constante O(1), incluindo o método adicional,
isso ocorre porque no algoritmo o minimo é sempre mantido e atualizado na na pilha auxiliar. */
