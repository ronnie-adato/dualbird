A linked list with friends is defined by the following node structure:
Struct Node {
  int value;
  Node *next = nullptr;
  Node *friend = nullptr;
};

‘friend’ may point to any other node in the list or be null. Friendship doesn’t have to be mutual (i.e. a node pointed to by a friend pointer of another node, doesn’t have to point back).
Implement a clone function for such a list.