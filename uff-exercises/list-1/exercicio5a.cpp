/* A complexidade do código é O(N) na maioria dos casos,
pois a operação de inverte efetua duas operações em cada elemento,
uma para transferir os elementos para a pilha e outra para transferi-los de volta para a fila
o que torna o algoritmo custoso, dependendo da quantidade de elementos.*/

#include <iostream>
#include <queue>
#include <stack>

void inverte(std::queue<char> *f)
{
  std::stack<char> p; // pilha auxiliar

  // Transfere elementos da fila para a pilha na ordem inversa
  while (!f->empty())
  {
    p.push(f->front());
    f->pop();
  }

  // Transfere elementos da pilha de volta para a fila
  while (!p.empty())
  {
    f->push(p.top());
    p.pop();
  }
}

int main()
{
  std::queue<char> fila;
  fila.push('A');
  fila.push('B');
  fila.push('C');

  std::cout << "Fila original: ";
  while (!fila.empty())
  {
    std::cout << fila.front() << " ";
    fila.pop();
  }
  std::cout << std::endl;

  inverte(&fila);

  std::cout << "Fila invertida: ";
  while (!fila.empty())
  {
    std::cout << fila.front() << " ";
    fila.pop();
  }
  std::cout << std::endl;

  return 0;
}
