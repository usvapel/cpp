#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data *ptr) {
  uintptr_t s = (uintptr_t)(void *)ptr;
  return s;
}
Data *Serializer::deserialize(uintptr_t raw) {
  Data *d = (Data *)raw;
  return d;
}
