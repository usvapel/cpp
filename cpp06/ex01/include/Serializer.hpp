#pragma once

#include <cstdint>
#include <iostream>
#include "Data.hpp"

class Serializer {
public:
  Serializer() = delete;
  Serializer(const Serializer &obj) = delete;
  Serializer operator=(const Serializer &obj) = delete;
  ~Serializer() = default;

  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};
