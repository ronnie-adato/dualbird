#pragma once

struct Node;

#include <vector>

Node* CreateLinkedList(const std::vector<int>& values, const std::vector<int>& afriend_indices);
void DeleteLinkedList(Node* root);
