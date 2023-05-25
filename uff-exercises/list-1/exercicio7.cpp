#include <cstring>
#include <stack>

bool isOperador(char c) { return c == '+' || c == '-' || c == '*' || c == '/'; }

bool isParenteseAberto(char c) { return c == '('; }

bool isParenteseFechado(char c) { return c == ')'; }

int precedencia(char c) {
  if (c == '+' || c == '-')
    return 1;
  else if (c == '*' || c == '/')
    return 2;
  return 0;
}

void polonesa(char *expressao, int N, char *saida_polonesa) {
  std::stack<char> pilha;
  int j = 0; // Índice para escrever no string 'saida_polonesa'

  for (int i = 0; i < N; i++) {
    char caractere = expressao[i];

    if (isOperador(caractere)) {
      while (!pilha.empty() && isOperador(pilha.top()) &&
             precedencia(pilha.top()) >= precedencia(caractere)) {
        saida_polonesa[j++] = pilha.top();
        pilha.pop();
      }
      pilha.push(caractere);
    } else if (isParenteseAberto(caractere)) {
      pilha.push(caractere);
    } else if (isParenteseFechado(caractere)) {
      while (!pilha.empty() && !isParenteseAberto(pilha.top())) {
        saida_polonesa[j++] = pilha.top();
        pilha.pop();
      }
      if (!pilha.empty() && isParenteseAberto(pilha.top()))
        pilha.pop(); // Remove o parentese aberto correspondente
    } else {
      saida_polonesa[j++] = caractere;
    }
  }

  while (!pilha.empty()) {
    saida_polonesa[j++] = pilha.top();
    pilha.pop();
  }

  saida_polonesa[j] = '\0'; // Adiciona o caractere de terminação de string
}
