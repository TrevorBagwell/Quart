#include "dot.h"

template <typename T>
quart::dot<T>() { /* Do nothing as there is nothing to do */ }

template <typename T>
~quart::dot<T>() { /* Do nothing as there is nothing to do */ }

template <typename T>
inline T quart::dot<T> operator()(T t1, T t2) { this->operator(t1,t2); }
