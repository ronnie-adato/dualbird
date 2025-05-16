#include <gtest/gtest.h>
#include <include/node.hpp>

// Helper function to create a linked list
Node* CreateLinkedList(const std::vector<int>& values, const std::vector<int>& afriend_indices) {
    if (values.empty()) {
        return nullptr;
    }

    std::vector<Node*> nodes(values.size(), nullptr);
    for (size_t i = 0; i < values.size(); ++i) {
        nodes[i] = new Node{values[i], nullptr, nullptr};
        if (i > 0) {
            nodes[i - 1]->next = nodes[i];
        }
    }

    for (size_t i = 0; i < afriend_indices.size(); ++i) {
        if (afriend_indices[i] >= 0 && afriend_indices[i] < static_cast<int>(nodes.size())) {
            nodes[i]->afriend = nodes[afriend_indices[i]];
        }
    }

    return nodes[0];
}

// Helper function to delete a linked list
void DeleteLinkedList(Node* root) {
    while (root) {
        Node* temp = root;
        root = root->next;
        delete temp;
    }
}

// Test case for the Clone function
TEST(CloneTest, DeepCopy) {
    // Create a linked list: 1 -> 2 -> 3, with afriend pointers: 1->3, 2->1, 3->2
    Node* root = CreateLinkedList({1, 2, 3}, {2, 0, 1});

    // Clone the linked list
    Node* cloned_root = Clone(root);


    // Verify the cloned list is a deep copy
    Node* original = root;
    Node* cloned = cloned_root;
    while (original != nullptr && cloned != nullptr) {
        EXPECT_NE(original, cloned); // Ensure different memory addresses
        EXPECT_EQ(original->value + 10, cloned->value); // Ensure values are the same
        if (original->afriend) {
            EXPECT_NE(original->afriend, cloned->afriend); // Ensure afriend is deep copied
            EXPECT_EQ(original->afriend->value + 10, cloned->afriend->value); // Ensure afriend values match
        } else {
            EXPECT_EQ(cloned->afriend, nullptr);
        }
        original = original->next;
        cloned = cloned->next;
    }

    // Ensure both lists end at the same time
    EXPECT_EQ(original, nullptr);
    EXPECT_EQ(cloned, nullptr);

    // Clean up
    DeleteLinkedList(root);
    DeleteLinkedList(cloned_root);
}
