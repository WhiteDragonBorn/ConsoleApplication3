#pragma once
#include <string>

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
//void createAsStack(Tlist& list, int n);
//void createAsQueue(Tlist& list, int n);
//void createByOrder(Tlist& list, int n);

class BigInt {
 private:
  Tlist num;

 public:
  BigInt(std::string&);
  BigInt(const BigInt&);
  ~BigInt();

  //std::string Print();
  friend int Length(const BigInt&);
  std::string toString();
  
  bool operator>(BigInt&) const;

  friend bool operator>(BigInt&, BigInt&);
  friend bool operator>=(BigInt&, BigInt&);
  friend bool operator<(BigInt&, BigInt&);
  friend bool operator<=(BigInt&, BigInt&);

  friend BigInt& operator+=(BigInt&, const BigInt&);
  friend BigInt operator+(const BigInt&, const BigInt&);
  friend BigInt& operator-=(BigInt&, const BigInt&);
  friend BigInt operator-(const BigInt&, const BigInt&);
};
