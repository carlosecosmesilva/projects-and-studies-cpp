void inverte(std::queue<char> *f) {
  std::stack<char> p;

  // Transfere os elementos da fila para a pilha
  while (!f->empty()) {
    p.push(f->front());
    f->pop();
  }

  // Transfere os elementos da pilha de volta para a fila (invertendo a ordem)
  while (!p.empty()) {
    f->push(p.top());
    p.pop();
  }
}

void inverte(std::queue<char> *f) {
  std::queue<char> f1;
  std::queue<char> f2;

  // Transfere os elementos da fila para f1
  while (!f->empty()) {
    f1.push(f->front());
    f->pop();
  }

  // Transfere os elementos de f1 para f2 (invertendo a ordem)
  while (!f1.empty()) {
    f2.push(f1.front());
    f1.pop();
  }

  // Transfere os elementos de f2 de volta para a fila original
  while (!f2.empty()) {
    f->push(f2.front());
    f2.pop();
  }
}
