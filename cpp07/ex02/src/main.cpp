#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <random>

Base *generate(void) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(1, 3);
  switch (distrib(gen)) {
  case 1:
    return new A;
  case 2:
    return new B;
  case 3:
    return new C;
  }
  return nullptr;
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p))
    std::cout << "A" << '\n';
  else if (dynamic_cast<B *>(p))
    std::cout << "B" << '\n';
  else if (dynamic_cast<C *>(p))
    std::cout << "C" << '\n';
}

void identify(Base &p) { identify(&p); }

int main() {
  Base *base = generate();
  identify(base);
  identify(*base);
  delete base;
}
