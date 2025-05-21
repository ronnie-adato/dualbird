#include "rsol.hpp"
#include "node.hpp"

#include "ng-log/logging.h"

Node *RSol::Clone(Node *root) {
  if (root == nullptr) {
    LOG(ERROR) << "Error: root is nullptr";
    return nullptr;
  }

  LOG(INFO) << "Original list: " << root;

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
  LOG(INFO) << "phase 1, Original list: " << root;

  for (node = root, cloned_node = cloned_root; node != nullptr;
       node = cloned_node->next,
      cloned_node = node == nullptr ? nullptr : node->next) {

    if (node->afriend != nullptr) {
      cloned_node->afriend = node->afriend->next;
    }
  }
  LOG(INFO) << "phase 2, Original list: " << root;

  for (node = root, cloned_node = cloned_root; node != nullptr;
       node = node->next, cloned_node = cloned_node->next) {

    node->next = cloned_node->next;
    cloned_node->next = node->next == nullptr ? nullptr : node->next->next;
  }

  LOG(INFO) << "phase 3, Original list: " << root;
  LOG(INFO) << "phase 3, Cloned list: " << cloned_root;

  return cloned_root;
}
