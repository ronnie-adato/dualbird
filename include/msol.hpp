#pragma once

#include <include/solution.hpp>

class MSol : public Solution {
public:
  Node *Clone(Node *root) override;
};
