#include <include/node.hpp>
#include <iostream>
#include <ostream>

std::ostream &operator<<(std::ostream &os, const Node &node) {
  os << "[Value: " << node.value;
  if (node.afriend) {
    os << ", afriend: " << node.afriend->value;
  } else {
    os << ", afriend: nullptr";
  }
  os << ']' << std::endl << node.next;
  return os;
}

std::ostream &operator<<(std::ostream &os, const Node *node) {
  if (node) {
    os << *node;
  } else {
    os << "nullptr";
  }
  return os;
}
