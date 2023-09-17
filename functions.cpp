#include "functions.h"

#include <algorithm>
#include <iostream>
#include <string>

void addToHead(Tlist& head, int elem) {
  Tlist p = new Node;
  p->data = elem;
  p->next = head;
  head = p;
}

void addAfterNode(Tlist pnode, int elem) {
  Tlist p = new Node;
  p->data = elem;
  p->next = pnode->next;
  pnode->next = p;
}

void deleteFromHead(Tlist& head) {
  Tlist p = head;
  head = head->next;
  p->next = nullptr;
  p->data = NULL;
  delete p;
  p = nullptr;
}

void deleteAfterNode(Tlist pnode) {
  Tlist p = pnode->next;
  pnode->next = p->next;
  p->next = nullptr;
  delete p;
  p = nullptr;
}

bool isEmpty(Tlist head) { return (head == nullptr); }

Tlist search(Tlist head, int elem) {
  Tlist p = head;
  Tlist result = nullptr;
  while (p != nullptr && result == nullptr) {
    if (p->data == elem) {
      result = p;
    }
    p = p->next;
  }
  return result;
}

void clear(Tlist& head) {
  while (!(isEmpty(head))) deleteFromHead(head);
}

// void PrintWithRecursion(Tlist head) {
//   if (head != nullptr) {
//     cout << head->data << " ";  //
//     PrintWithRecursion(head->next);  // если поменять две строчки местами, то
//                                      // будет обратный вывод
//   }
// }
//
// int SumList(Tlist head) {
//   int result = 0;
//   Tlist moveHead = head;
//   while (moveHead != nullptr) {
//     result += moveHead->data;
//     moveHead = moveHead->next;
//   }
//   return result;
// }
//
// int SumListRecurse(Tlist head) {
//   if (head)
//     return 0;
//   else if (head != nullptr) {
//     return (head->data + SumListRecurse(head->next));
//   }
// }
// void createAsStack(Tlist& list, int n) {
//
// }

// Tlist findPlace(Tlist list, int elem) {
//   Tlist temp = list;
//   // Tlist result = nullptr;
//   while (temp->next && temp->next->data <= elem) {
//     // result = temp;
//     temp = temp->next;
//   }
//   return temp;
// }
//
// void createByOrder(Tlist& list, int n) {
//   srand(time(0));
//   list = nullptr;
//   int temp = rand() % 100;
//   addToHead(list, temp);
//
//   for (int i = 0; i < n + 1; i++) {
//     temp = rand() % 100;
//   }
// }
//
// int returnSum(Tlist list) {
//   int sum = 0;
//   while (list->next->next != nullptr) {
//     list = list->next;
//   }
//   sum += list->data + list->next->data;
//   return sum;
// }
