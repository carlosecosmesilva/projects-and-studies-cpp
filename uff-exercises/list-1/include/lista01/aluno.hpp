// SPDX-License-Identifier:  MIT
// Copyright (C) 2023 - Prof. Igor Machado Coelho

#pragma once

// C includes
//
// helpers
#include <fmt/core.h>
#include <scn/scn.h>
// C++ includes
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <limits>
#include <sstream>
#include <string>
#include <tuple>  // para exercícios com tupla
#include <utility>
#include <vector>
// favor não remover exemplos
#include <revisao-c-cpp/exemplo.hpp>

#include "scn/scan/scan.h"
//

using fmt::print;  // NOLINT
using scn::scan;   // NOLINT

// exercício 0
// NAO APAGUE OU MODIFIQUE O CABEÇALHO DA FUNÇÃO ABAIXO
int exercicio0(std::string entrada) {
  // SOLUCAO: modifique o return 1 para return 0
  return 0;
  // return 0;
}

// resolução exercício 1 (verifique se está correto)
// NAO APAGUE OU MODIFIQUE O CABEÇALHO DA FUNÇÃO ABAIXO
int exercicio1(std::string entrada) {
  int a = 0;
  int b = 0;
  auto resto = scan(entrada, "{}", a, b);
  if (!resto.empty()) return -1;  // ERRO DE LEITURA
  int soma = 0;
  for (int i = a; i <= b; i++) {
    soma += i;
  }
  return soma;
}

// =======================  falta fazer ============================

// NAO APAGUE OU MODIFIQUE O CABEÇALHO DA FUNÇÃO ABAIXO
int exercicio2(std::string entrada) {
  // Edite aqui dentro, somente. Leia todos os dados da string 'entrada'
  int n = 0;
  auto votos = scan(entrada, "{}", n);
  if (!votos) {
    return -1;
  }
  std::vector<int> candidatos(4, 0);
  int voto = 0;
  for (int i = 0; i < n; i++) {
    votos = scan(entrada, "{}", voto);
    if (!votos) {
      return -1;
    }
    if (voto >= 1 && voto <= 3) {
      candidatos[voto]++;
    }
  }
  int vencedor = 0;
  int maxVotos = candidatos[1];
  for (int i = 0; i <= 3; i++) {
    if (candidatos[i] > maxVotos) {
      vencedor = i;
      maxVotos = candidatos[i];
    } else if (candidatos[i] == maxVotos) {
      vencedor = 0;
    }
  }
  return vencedor;
}

// dica: retorna uma tupla com 4 elementos (veja slides com std::make_tuple)
// NAO APAGUE OU MODIFIQUE O CABEÇALHO DA FUNÇÃO ABAIXO
auto exercicio3(std::string entrada) {
  // Edite aqui dentro, somente. Leia todos os dados da string 'entrada'
  std::tuple<double, double, double, double> t1;
  std::istringstream string(entrada);
  int n = 0;
  string >> n;

  double soma = 0;
  double minVal = std::numeric_limits<double>::max();
  double maxVal = std::numeric_limits<double>::min();
  double x = 0.0;

  for (int i = 0; i < n; i++) {
    string >> x;
    soma += x;
    if (x < minVal) minVal = x;
    if (x > maxVal) maxVal = x;
  }
  double media = soma / n;
  return std::make_tuple(soma, media, maxVal, minVal);
}

// NAO APAGUE OU MODIFIQUE O CABEÇALHO DA FUNÇÃO ABAIXO
int exercicio4(std::string entrada) {
  // Edite aqui dentro, somente. Leia todos os dados da string 'entrada'
  std::istringstream iss(entrada);

  int n = 0;
  double notas = 0.0;
  std::vector<std::pair<double, std::string>> alunos;

  iss >> n;

  for (int i = 0; i < n; i++) {
    double nota = 0.0;
    std::string nome;
    iss >> nota >> nome;
    alunos.emplace_back(nota, nome);
  }

  iss >> notas;

  int aprovados = 0;

  for (const auto& aluno : alunos) {
    if (aluno.first >= 6.0) {
      aprovados++;
    }
  }

  double porcentagem =
      static_cast<double>(aprovados) / static_cast<double>(n * 100.0);
  return (porcentagem >= notas) ? 1 : 0;
}

// NAO APAGUE OU MODIFIQUE O CABEÇALHO DA FUNÇÃO ABAIXO
int exercicio5(std::string entrada) {
  // Edite aqui dentro, somente. Leia todos os dados da string 'entrada'
  int n = 0;
  auto numLidos = scan(entrada, "{}", n);
  if (!numLidos) {
    return -1;
  }
  int fatorial = 1;
  for (int i = 2; i <= n; i++) {
    fatorial *= i;
  }
  return fatorial;
}

// NAO APAGUE OU MODIFIQUE O CABEÇALHO DA FUNÇÃO ABAIXO
int exercicio6(std::string entrada) {
  // Edite aqui dentro, somente. Leia todos os dados da string 'entrada'
  std::istringstream iss(entrada);
  int k = 0;
  iss >> k;

  int a = 1, b = 1, c = 0;

  for (int i = 3; i <= k; i++) {
    c = a + b;
    a = b;
    b = c;
  }

  return b;
}

// dica: retorno de 'char', não 'int'
// NAO APAGUE OU MODIFIQUE O CABEÇALHO DA FUNÇÃO ABAIXO
char exercicio7(std::string entrada) {
  // Edite aqui dentro, somente. Leia todos os dados da string 'entrada'
  int n = 0;
  std::vector<std::tuple<char, char>> jogadas;
  auto numLidos = scan(entrada, "{}", n);

  if (!numLidos) {
    return 'X';
  }

  for (int i = 0; i < n; i++) {
    char jogadaMaria = 'X', jogadaJoao = 'X';
    auto numLidos = std::make_tuple(jogadaMaria, jogadaJoao);
    if (std::get<0>(numLidos) == 0) {
      return 'X';
    }
    jogadas.push_back(std::make_tuple(jogadaMaria, jogadaJoao));
  }

  int ptsMaria = 0, ptsJoao = 0;
  for (int i = 0; i < n; i++) {
    char jogadaMaria = std::get<0>(jogadas[i]),
         jogadaJoao = std::get<0>(jogadas[i]);
    if (jogadaMaria == jogadaJoao) {
      continue;
    }
    if ((jogadaMaria == 'd' && jogadaJoao == 't') ||
        jogadaMaria == 'p' && jogadaJoao == 'd' ||
        jogadaMaria == 't' && jogadaJoao == 'p') {
      ptsMaria++;
    } else {
      ptsJoao++;
    }
  }
  if (ptsMaria > ptsJoao) {
    return 'M';
  } else if (ptsJoao > ptsMaria) {
    return 'J';
  } else {
    return 'X';
  }
}

// dica: retorna uma tupla com 2 elementos (veja slides com std::make_tuple)
// NAO APAGUE OU MODIFIQUE O CABEÇALHO DA FUNÇÃO ABAIXO
auto exercicio8(std::string entrada) {
  // Edite aqui dentro, somente. Leia todos os dados da string 'entrada'. Leia
  // todos os dados a partir da string 'entrada'
  int a = 0;
  int b = 0;

  auto numLidos = scan(entrada, "{}", a, b);
  int* ptr = &a;
  int temp = *ptr;
  *ptr = b;
  b = temp;
  return std::make_tuple(a, b);
}

// dica: retorno de 'float', não 'int'
// NAO APAGUE OU MODIFIQUE O CABEÇALHO DA FUNÇÃO ABAIXO
float exercicio9(std::string entrada) {
  // Edite aqui dentro, somente. Leia todos os dados da string 'entrada'
  int n = 0;
  float num = 0.0;
  auto numLidos = scan(entrada, "{}", n);
  if (!numLidos || n <= 0) {
    return -1.0;
  }
  std::vector<float> numeros(n);
  for (int i = 0; i < n; i++) {
    numLidos = scan(entrada, "{}", num);
    if (!numLidos) {
      return -1.0;
    }
    numeros[i] = num;
  }
  std::sort(numeros.begin(), numeros.end());
  if (n % 2 == 0) {
    return (numeros[n / 2 - 1] + numeros[n / 2]) / 2.0f;
  } else {
    return numeros[n / 2];
  }
}
