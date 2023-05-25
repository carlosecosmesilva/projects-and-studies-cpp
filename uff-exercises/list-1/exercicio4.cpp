void inverte(std::stack<char> *p) {
  std::queue<char> f;

  // Transfere os elementos da pilha para a fila
  while (!p->empty()) {
    f.push(p->top());
    p->pop();
  }

  // Transfere os elementos da fila de volta para a pilha (invertendo a ordem)
  while (!f.empty()) {
    p->push(f.front());
    f.pop();
  }
}

void inverte(std::stack<char> *p) {
  std::stack<char> p1;
  std::stack<char> p2;

  // Transfere os elementos da pilha para p1
  while (!p->empty()) {
    p1.push(p->top());
    p->pop();
  }

  // Transfere os elementos de p1 para p2 (invertendo a ordem)
  while (!p1.empty()) {
    p2.push(p1.top());
    p1.pop();
  }

  // Transfere os elementos de p2 de volta para a pilha original
  while (!p2.empty()) {
    p->push(p2.top());
    p2.pop();
  }
}

void inverte(std::stack<char> *p) {
  std::stack<char> p1;

  // Transfere os elementos da pilha para p1
  while (!p->empty()) {
    p1.push(p->top());
    p->pop();
  }

  // Transfere os elementos de p1 de volta para a pilha original (invertendo a
  // ordem)
  while (!p1.empty()) {
    p->push(p1.top());
    p1.pop();
  }
}
