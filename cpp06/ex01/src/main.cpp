#include "Serializer.hpp"

int main() {
  Data data;

  std::cout << data.string << ' ' << data.value << '\n';
  std::cout << &data << '\n';

  uintptr_t ptr = Serializer::serialize(&data);
  data = *Serializer::deserialize(ptr);

  std::cout << data.string << ' ' << data.value << '\n';
  std::cout << &data << '\n';

  Data *data2 = new Data;

  std::cout << data2->string << ' ' << data2->value << '\n';
  std::cout << &data2 << '\n';

  uintptr_t ptr2 = Serializer::serialize(data2);
  data2 = Serializer::deserialize(ptr2);

  std::cout << data2->string << ' ' << data2->value << '\n';
  std::cout << &data2 << '\n';
  delete data2;
}
