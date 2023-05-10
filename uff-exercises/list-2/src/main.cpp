// SPDX-License-Identifier:  MIT
// Copyright (C) 2023 - Prof. Igor Machado Coelho
#include <cstddef>
#include <memory>
#include <vector>
//
#include <fmt/core.h>  // NOLINT

#include <lista01/get_data.hpp>

#include "scn/scan/scan.h"

using fmt::print;
using std::tuple;

struct XY {
  int x;
  int y;
};

int main() {
  print("exercicio7(\"3 t p d p d t\")={}\n", exercicio7("3 t p d p d t"));
  //
  auto ptr = std::make_shared<XY>(XY{.x = 1, .y = 2});
  return 0;
}


// Ctrl+Shift+P
// CMake: build
// CMake: configure
// CMake: debug
// [aplicacao]
