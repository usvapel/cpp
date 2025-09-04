
#include "Fixed.hpp"

void comparisonTests() {
    std::cout << "\n--- Comparison Operator Tests ---\n";
    Fixed a(1);
    Fixed b(3);

    std::cout << "a = " << a << ", b = " << b << "\n";
    std::cout << "a < b  : " << (a < b) << "\n";
    std::cout << "a > b  : " << (a > b) << "\n";
    std::cout << "a <= b : " << (a <= b) << "\n";
    std::cout << "a >= b : " << (a >= b) << "\n";
    std::cout << "a == b : " << (a == b) << "\n";
    std::cout << "a != b : " << (a != b) << "\n";
}

void arithmeticTests() {
    std::cout << "\n--- Arithmetic Operator Tests ---\n";
    Fixed a(3);
    Fixed b(1);

    std::cout << "a = " << a << ", b = " << b << "\n";
    std::cout << "a + b = " << (a + b) << "\n";
    std::cout << "a - b = " << (a - b) << "\n";
    std::cout << "a * b = " << (a * b) << "\n";
    std::cout << "b / a = " << (b / a) << "\n";
}

void incrementDecrementTests() {
    std::cout << "\n--- Increment / Decrement Tests ---\n";
    Fixed a(5);

    std::cout << "Initial a: " << a << "\n";
    std::cout << "a++ : " << a++ << " (after: " << a << ")\n";
    std::cout << "++a : " << ++a << " (after: " << a << ")\n";
    std::cout << "a-- : " << a-- << " (after: " << a << ")\n";
    std::cout << "--a : " << --a << " (after: " << a << ")\n";
}

void minMaxTests() {
    std::cout << "\n--- Min / Max Tests ---\n";
    Fixed a(7);
    Fixed b(9);

    std::cout << "a = " << a << ", b = " << b << "\n";
    std::cout << "min(a, b) = " << Fixed::min(a, b) << "\n";
    std::cout << "max(a, b) = " << Fixed::max(a, b) << "\n";
}

void copyAndAssignmentTests() {
    std::cout << "\n--- Copy & Assignment Tests ---\n";
    Fixed a(42);
    Fixed b(a);
    Fixed c;
    c = a;

    std::cout << "a = " << a << ", b(copy) = " << b << ", c(assigned) = " << c << "\n";
}

void rawBitsTests() {
    std::cout << "\n--- Raw Bits Tests ---\n";
    Fixed a;
    a.setRawBits(128);
    std::cout << "a raw = " << a.getRawBits() << "\n";
}

int main() {

    comparisonTests();
    arithmeticTests();
    incrementDecrementTests();
    minMaxTests();
    copyAndAssignmentTests();
    rawBitsTests();

    return 0;
}
