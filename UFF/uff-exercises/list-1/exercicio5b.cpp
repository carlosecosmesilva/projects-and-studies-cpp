/* A complexidade do código é O(N) na maioria dos casos,
pois a operação de inverte efetua duas operações em cada elemento,
uma para transferir os elementos para a pilha e outra para transferi-los de volta para a fila
o que torna o algoritmo custoso, dependendo da quantidade de elementos.*/

#include <iostream>
#include <queue>

void inverte(std::queue<char> *f)
{
  std::queue<char> f1; // primeira fila auxiliar
  std::queue<char> f2; // segunda fila auxiliar

  // Transferir elementos da fila original para a primeira fila auxiliar na ordem inversa
  while (!f->empty())
  {
    f1.push(f->front());
    f->pop();
  }

  // Transferir elementos da primeira fila para a segunda fila auxiliar
  while (!f1.empty())
  {
    f2.push(f1.front());
    f1.pop();
  }

  // Transferir elementos da segunda fila de volta para a fila original
  while (!f2.empty())
  {
    f->push(f2.front());
    f2.pop();
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
