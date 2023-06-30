/* A complexidade do código é O(N) na maioria dos casos,
pois a operação de inverte efetua duas operações em cada elemento da pilha,
o que torna o algoritmo custoso, dependendo da quantidade de elementos.*/

#include <iostream>
#include <stack>

void inverte(std::stack<char> *p)
{
  std::stack<char> p1; // Primeira pilha auxiliar
  std::stack<char> p2; // Segunda pilha auxiliar

  // Transfere os elementos da pilha para a primeira pilha auxiliar
  while (!p->empty())
  {
    p1.push(p->top());
    p->pop();
  }

  // Transfere os elementos da primeira pilha auxiliar para a segunda pilha auxiliar (invertendo a ordem)
  while (!p1.empty())
  {
    p2.push(p1.top());
    p1.pop();
  }

  // Transfere os elementos da segunda pilha auxiliar de volta para a pilha original
  while (!p2.empty())
  {
    p->push(p2.top());
    p2.pop();
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