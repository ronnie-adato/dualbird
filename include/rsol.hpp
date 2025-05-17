#pragma once

#include <include/solution.hpp>

class RSol : public Solution {
public:
  Node *Clone(Node *root) override;
};
