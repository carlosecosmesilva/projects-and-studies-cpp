/* No código busca-se implementar uma estrutura de dados chamada deque,
 e uma fila utilizando o deque, e dentro das operações de fila 
 são executadas as operações de enfileirar, desenfileirar e uma operação para pegar a frente da fila.*/

#include <iostream>

class Deque
{
private:
  struct Node
  {
    char data;
    Node *prev;
    Node *next;
  };

  Node *head;
  Node *tail;

public:
  Deque() : head(nullptr), tail(nullptr) {}

  char inicio() const
  {
    if (head != nullptr)
    {
      return head->data;
    }
    throw std::runtime_error(
        "Deque vazio: não é possível obter o elemento do início.");
  }

  char fim() const
  {
    if (tail != nullptr)
    {
      return tail->data;
    }
    throw std::runtime_error(
        "Deque vazio: não é possível obter o elemento do fim.");
  }

  void insereInicio(char elemento)
  {
    Node *newNode = new Node{elemento, nullptr, head};
    if (head != nullptr)
    {
      head->prev = newNode;
    }
    else
    {
      tail = newNode;
    }
    head = newNode;
  }

  void insereFim(char elemento)
  {
    Node *newNode = new Node{elemento, tail, nullptr};
    if (tail != nullptr)
    {
      tail->next = newNode;
    }
    else
    {
      head = newNode;
    }
    tail = newNode;
  }

  char removeInicio()
  {
    if (head != nullptr)
    {
      char elemento = head->data;
      Node *temp = head;
      head = head->next;
      if (head != nullptr)
      {
        head->prev = nullptr;
      }
      else
      {
        tail = nullptr;
      }
      delete temp;
      return elemento;
    }
    throw std::runtime_error(
        "Deque vazio: não é possível remover o elemento do início.");
  }

  char removeFim()
  {
    if (tail != nullptr)
    {
      char elemento = tail->data;
      Node *temp = tail;
      tail = tail->prev;
      if (tail != nullptr)
      {
        tail->next = nullptr;
      }
      else
      {
        head = nullptr;
      }
      delete temp;
      return elemento;
    }
    throw std::runtime_error(
        "Deque vazio: não é possível remover o elemento do fim.");
  }
};

class FilaDeque
{
private:
  Deque d;

public:
  void enfileira(char elemento) { d.insereFim(elemento); }

  char desenfileira() { return d.removeInicio(); }

  char frente() const { return d.inicio(); }
};

template <typename Fila, typename Tipo>
concept bool FilaTAD = requires(Fila f, Tipo t) {
  {
    f.enfileira(t)
  };
  {
    f.desenfileira()
  } -> std::same_as<Tipo>;
  {
    f.frente()
  } -> std::same_as<Tipo &>;
};

static_assert(DequeTAD<Deque, char>);
static_assert(FilaTAD<FilaDeque, char>);

int main()
{
  FilaDeque fila;
  fila.enfileira('A');
  fila.enfileira('B');
  std::cout << "Frente: " << fila.frente() << std::endl;
  fila.desenfileira();
  std::cout << "Frente: " << fila.frente() << std::endl;
  return 0;
}

/* O algoritmo possui a complexidade de O(1), ou seja, 
a mesma é constante independente da quantidade de elementos que serão executadas nas operações */
