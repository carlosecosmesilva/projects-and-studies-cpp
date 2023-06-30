/* A classe Deque é implementada juntamente com uma lista duplamente encadeada.
Mais abaixo na classe Pilha é utilizado o objeto da classe Deque para implementação da Pilha.
As operações seguem o mesmo padrão de anteriormente, como inicio, fim, inserção e remoção.
Entretanto foram adicionadas as operações de pilha, que são empilha, desempilha e a operação que busca o topo da pilha*/

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

class PilhaDeque
{
private:
  Deque d;

public:
  char topo() const { return d.inicio(); }

  void empilha(char elemento) { d.insereInicio(elemento); }

  char desempilha() { return d.removeInicio(); }
};

template <typename Pilha, typename Tipo>
concept bool PilhaTAD = requires(Pilha p, Tipo t) {
  {
    p.topo()
  } -> std::same_as<Tipo &>;
  {
    p.empilha(t)
  };
  {
    p.desempilha()
  } -> std::same_as<Tipo>;
};

static_assert(DequeTAD<Deque, char>);
static_assert(PilhaTAD<PilhaDeque, char>);

int main()
{
  PilhaDeque pilha;
  pilha.empilha('A');
  pilha.empilha('B');
  std::cout << "Topo: " << pilha.topo() << std::endl;
  pilha.desempilha();
  std::cout << "Topo: " << pilha.topo() << std::endl;
  return 0;
}

/*No algoritmo acima não há dependencia do número de elementos executados nas operações,
tanto as operações de pilha quanto as operações que já existiam no execicio anterior na Deque, em resumo 
a sua complexidade será sempre constante O(1)*/
