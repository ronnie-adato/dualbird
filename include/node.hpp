#pragma once

#include <ostream>

struct Node {
  int value;
  Node *next = nullptr;
  Node *afriend = nullptr;
};

std::ostream &operator<<(std::ostream &os, const Node &node);
std::ostream &operator<<(std::ostream &os, const Node *node);

// Node constructor
