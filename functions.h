#pragma once

struct Node {
  int data;
  Node* next;

  Node() {
    data = 0;
    next = nullptr;
  }
};

typedef Node* Tlist;

void addToHead(Tlist& head, int elem);
void addAfterNode(Tlist pnode, int elem);
void deleteFromHead(Tlist& head);
void deleteAfterNode(Tlist pnode);
bool isEmpty(Tlist head);
void clear(Tlist& head);
// void createAsStack(Tlist& list, int n);
// void createAsQueue(Tlist& list, int n);
// void createByOrder(Tlist& list, int n);