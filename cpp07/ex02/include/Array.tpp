template <typename T> Array<T>::Array() : elements(nullptr), array_size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : elements(new T[n]), array_size(n) {}

// copy
template <typename T>
Array<T>::Array(const Array &obj) : array_size(obj.array_size) {
  if (obj.elements) {
    elements = new T[array_size];
    for (unsigned int i = 0; i < array_size; i++) {
      elements[i] = obj.elements[i];
    }
  } else {
    elements = nullptr;
  }
}

// assignment
template <typename T> Array<T> &Array<T>::operator=(const Array &obj) {
  if (this != &obj) {
    delete[] elements;
    array_size = obj.array_size;
    if (obj.elements) {
      elements = new T[array_size];
      for (unsigned int i = 0; i < array_size; i++) {
        elements[i] = obj.elements[i];
      }
    } else {
      elements = nullptr;
    }
  }
  return *this;
}

template <typename T> unsigned int Array<T>::size() { return array_size; }

template <typename T> T &Array<T>::operator[](const unsigned int index) {
  if (index >= array_size)
    throw std::out_of_range("index out of bounds");
  return elements[index];
}

template <typename T> Array<T>::~Array() { delete[] elements; }
