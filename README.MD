# Problem Description

A linked list with friends is defined by the following node structure:
```
Struct Node {
  int value;
  Node *next = nullptr;
  Node *afriend = nullptr;
};
```

`afriend` may point to any other node in the list or be null. Friendship doesn’t have to be mutual (i.e. a node pointed to by a friend pointer of another node, doesn’t have to point back).
Implement a clone function for such a list.

## Compile

If you don't have `meson` download and install `meson` and `ninja`

Run: `meson setup build`

For compilation run: `ninja -C build`

## Running Tests

Run: `./build/tests/tests-dual-bird`

## Inspecting logs

Open the file `/tmp/tests-dual-bird.INFO`
