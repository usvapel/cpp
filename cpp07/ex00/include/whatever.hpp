#pragma once

#include <iostream>

template <typename T> void swap(T &a, T &b) { std::swap(a, b); }

template <typename T> T min(T &a, T &b) { return std::min(a, b); }

template <typename T> T max(T &a, T &b) { return std::max(a, b); }

