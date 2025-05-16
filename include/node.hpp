#pragma once

#include <string>

struct Node {
  int value;
  Node *next = nullptr;
  Node *afriend = nullptr;
};

Node *Clone(Node *root);

// Node constructor
