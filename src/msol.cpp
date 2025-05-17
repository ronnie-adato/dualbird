#include <include/msol.hpp>
#include <include/node.hpp>
#include <iostream>

Node *MSol::Clone(Node *root) {
  if (root == nullptr) {
    return nullptr;
  }
  std::cout << "Begin:" << std::endl << root << std::endl << std::endl;

  Node *cr = nullptr;
  for (Node *r = root; r != nullptr; r->next = cr, r = cr->next) {
    cr = new Node();
    cr->value = r->value + 10;
    cr->next = r->next;
  }
  std::cout << "Phase 1:" << std::endl << root << std::endl << std::endl;

  for (Node *r = root; r != nullptr; r = r->next->next) {
    r->next->afriend = r->afriend->next;
  }
  std::cout << "Phase 2:" << std::endl << root << std::endl << std::endl;

  Node *croot = root->next;
  Node *ctmp = croot;

  for (Node *r = root; r != nullptr; r = r->next) {
    r->next = ctmp->next;
    if (ctmp->next != nullptr) {
      ctmp->next = ctmp->next->next;
    }
    ctmp = ctmp->next;
  }

  std::cout << "root:" << std::endl << root << std::endl << std::endl;
  std::cout << "croot:" << std::endl << croot << std::endl << std::endl;
  return croot;
}
