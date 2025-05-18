#include <include/msol.hpp>
#include <include/node.hpp>
#include <ng-log/logging.h>

Node *MSol::Clone(Node *root) {
  if (root == nullptr) {
    LOG(ERROR) << "Error: root is nullptr";
    return nullptr;
  }
  LOG(INFO) << "Begin: " << root;

  Node *cr = nullptr;
  for (Node *r = root; r != nullptr; r->next = cr, r = cr->next) {
    cr = new Node();
    cr->value = r->value + 10;
    cr->next = r->next;
  }
  LOG(INFO) << "Phase 1: " << root;

  for (Node *r = root; r != nullptr; r = r->next->next) {
    r->next->afriend = r->afriend->next;
  }
  LOG(INFO) << "Phase 2: " << root;

  Node *croot = root->next;
  Node *ctmp = croot;

  for (Node *r = root; r != nullptr; r = r->next) {
    r->next = ctmp->next;
    if (ctmp->next != nullptr) {
      ctmp->next = ctmp->next->next;
    }
    ctmp = ctmp->next;
  }

  LOG(INFO) << "root: " << root;
  LOG(INFO) << "croot: " << croot;
  return croot;
}
