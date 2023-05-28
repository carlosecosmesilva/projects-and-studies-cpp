/* A complexidade do código é O(N) na maioria dos casos,
pois a operação de inverte efetua duas operações em cada elemento da pilha,
o que torna o algoritmo custoso, dependendo da quantidade de elementos.*/

#include <iostream>
#include <stack>

void inverte(std::stack<char> *p)
{
  std::stack<char> p1; // Pilha auxiliar
  char aux;

  // Transfere os elementos da pilha para a pilha auxiliar
  while (!p->empty())
  {
    aux = p->top();
    p->pop();
    p1.push(aux);
  }

  // Transfere os elementos da pilha auxiliar de volta para a pilha original (invertendo a ordem)
  while (!p1.empty())
  {
    aux = p1.top();
    p1.pop();
    p->push(aux);
  }
}

int main()
{
  std::stack<char> pilha;
  pilha.push('A');
  pilha.push('B');
  pilha.push('C');

  std::cout << "Pilha original: ";
  while (!pilha.empty())
  {
    std::cout << pilha.top() << " ";
    pilha.pop();
  }

  inverte(&pilha);

  std::cout << "\nPilha invertida: ";
  while (!pilha.empty())
  {
    std::cout << pilha.top() << " ";
    pilha.pop();
  }

  return 0;
}
