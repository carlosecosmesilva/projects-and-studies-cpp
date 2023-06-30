/* No algoritmo abaixo foi criada a classe Deque que efetua a implementaçãlo de uma lista duplamente encadeada, 
que será tratada para receber as operações contidas em cada função.
Foi desenvolvido função de operações básicas, como inicio onde é pego o inicio do Deque, fim, que retorna o fim do Deque,
já nas operações de inserção repetimos o padrão com inserção no inicio do deque e inserção no final do Deque*/

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

static_assert(std::is_same_v<Deque, Deque>,
              "O tipo fornecido não corresponde à classe Deque.");

int main()
{
  Deque deque;
  deque.insereInicio('A');
  deque.insereFim('B');
  std::cout << "Início: " << deque.inicio() << std::endl;
  std::cout << "Fim: " << deque.fim() << std::endl;
  deque.removeInicio();
  deque.removeFim();
  return 0;
}

/* No caso do algoritmo ser executado em uma ordem cronológica correta o mesmo não teria problemas
e sua complexidade seria de O(1) sempre, devido o mesmo utilizar de uma lista duplamente encadeada,
que irá facilitar o "trânsito" de informações, 
e principalmente porque o tempo de execução não vai depender da quantidade de elementos. */
