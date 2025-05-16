#include <include/node.hpp>
#include <iostream>
#include <ostream>

std::ostream &operator<<(std::ostream &os, const Node &node);
std::ostream &operator<<(std::ostream &os, const Node *node);

Node *Clone(Node *root) {
  if (root == nullptr) {
    std::cerr << "Error: root is nullptr" << std::endl;
    return nullptr;
  }

  std::cout << "Original list:" << std::endl << root << std::endl << std::endl;

  Node *cloned_root = nullptr;
  Node *cloned_node = cloned_root;
  Node *node = root;

  for (; node != nullptr; node = cloned_node->next) {

    cloned_node = new Node;
    if (cloned_root == nullptr) {
      cloned_root = cloned_node;
    }
    cloned_node->value = node->value + 10;
    cloned_node->next = node->next;
    node->next = cloned_node;
  }
  std::cout << "phase 1, Original list:" << std::endl << root << std::endl << std::endl;

  for (node = root, cloned_node = cloned_root; node != nullptr;
       node = cloned_node->next,
      cloned_node = node == nullptr ? nullptr : node->next) {

    if (node->afriend != nullptr) {
      cloned_node->afriend = node->afriend->next;
    }
  }
  std::cout << "phase 2, Original list:" << std::endl << root << std::endl << std::endl;

  for (node = root, cloned_node = cloned_root; node != nullptr;
       node = node->next, cloned_node = cloned_node->next) {

    node->next = cloned_node->next;
    cloned_node->next = node->next == nullptr ? nullptr : node->next->next;
  }

  std::cout << "phase 3, Original list:" << std::endl << root << std::endl << std::endl;
  std::cout << "phase 3, Cloned list:" << std::endl << cloned_root << std::endl << std::endl;

  return cloned_root;
}

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
