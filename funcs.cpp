#include <algorithm>
#include <iostream>
#include <string>

#include "header.h"

using namespace std;

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
  delete p;
  p = NULL;
}

void deleteAfterNode(Tlist pnode) {
  Tlist p = pnode->next;
  pnode->next = p->next;
  p->next = nullptr;
  delete p;
  p = nullptr;
}

bool isEmpty(Tlist head) {
  return (head == nullptr);
}

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
  while (isEmpty(head))
    deleteFromHead(head);
}

// void createAsStack(Tlist& list, int n) {
//
// }

Tlist findPlace(Tlist list, int elem) {
  Tlist temp = list;
  // Tlist result = nullptr;
  while (temp->next && temp->next->data <= elem) {
    // result = temp;
    temp = temp->next;
  }
  return temp;
}

void createByOrder(Tlist& list, int n) {
  srand(time(0));
  list = nullptr;
  int temp = rand() % 100;
  addToHead(list, temp);

  for (size_t i = 0; i < n + 1; i++) {
    temp = rand() % 100;
  }
}

int returnSum(Tlist list) {
  int sum = 0;
  while (list->next->next != nullptr) {
    list = list->next;
  }
  sum += list->data + list->next->data;
  return sum;
}

BigInt::BigInt(string& str) {
  num = new Node;
  num->data = str[0] - '0';
  num->next = nullptr;
  // cout << "---" << num->data << "---";
  for (int i = 1; i < str.length(); ++i) {
    // cout << "---" << (str[i] - '0') << "---";
    addToHead(num, (str[i] - '0'));
  }
}

BigInt::BigInt(const BigInt& Q) {
  num = new Node;
  num->data = Q.num->data;
  if (Length(Q) > 1) {
    Tlist moveQ = Q.num->next;
    Tlist moveNum = num;
    // переделать без break !
    while (true) {
      if (moveQ->next == nullptr) {
        addAfterNode(moveNum, moveQ->data);
        break;
      }
      addAfterNode(moveNum, moveQ->data);
      moveNum = moveNum->next;
      moveQ = moveQ->next;
    }
  }
}

BigInt::~BigInt() {
  clear(num);
  delete num;
  num = nullptr;
}

// string BigInt::Print() {
//   string result = "";
//   Tlist moveQ = Q.num;
//
//   while (moveQ->next != nullptr) {
//     result += to_string(moveQ->data);
//     moveQ = moveQ->next;
//   }
//
//   result += to_string(moveQ->data);
//   // можно не разворачивать, а сделать обратную конкатенацию
//   if (result.length() != 1) {
//     reverse(result.begin(), result.end());
//   }
//
//   char ctemp = result[0];
//   while (ctemp == '0') {
//     result = result.substr(1, result.size());
//     ctemp = result[0];
//   }
//   cout << result; // убрать сяуты из классов
// }

void PrintWithRecursion(Tlist head) {
  if (head != nullptr) {
    cout << head->data << " ";  //
    PrintWithRecursion(head->next);  // если поменять две строчки местами, то
                                     // будет обратный вывод
  }
}

int SumList(Tlist head) {
  int result = 0;
  Tlist moveHead = head;
  while (moveHead != nullptr) {
    result += moveHead->data;
    moveHead = moveHead->next;
  }
  return result;
}

int SumListRecurse(Tlist head) {
  if (head)
    return 0;
  else if (head != nullptr) {
    return (head->data + SumListRecurse(head->next));
  }
}

int Length(const BigInt& Q) {
  Tlist moveQ = Q.num;
  int result = 1;
  while (moveQ->next != nullptr) {
    ++result;
    moveQ = moveQ->next;
  }
  return result;
}

std::string BigInt::toString() {
  string result = "";
  Tlist moveQ = num;

  while (moveQ->next != nullptr) {
    result += to_string(moveQ->data);
    moveQ = (moveQ->next);
  }
  result += to_string(moveQ->data);
  reverse(result.begin(), result.end());  // отбросить нули !
  return result;
}

BigInt& operator+=(BigInt& Q, const BigInt& W) {
  int remain = 0;
  int n = Length(Q);
  int m = Length(W);
  Tlist moveQ = Q.num;
  Tlist moveW = W.num;
  int biggest = (n > m) ? n : m;
  int smallest = (n < m) ? n : m;

  if (n == m) {
    // cout << endl << "in" << endl;
    for (int i = 0; i < biggest; ++i) {
      // cout << "i: " << i << endl;
      int tempSum = moveQ->data + moveW->data + remain;
      // cout << endl << "tempSum: " << tempSum << endl;
      moveQ->data = (tempSum) % 10;
      // cout << endl << "data: " << (tempSum)%10<< endl;
      remain = tempSum / 10;
      // cout << endl << "remain: " << remain << endl;
      if (moveQ->next != nullptr)
        moveQ = moveQ->next;
      if (moveW->next != nullptr)
        moveW = moveW->next;
    }
    if (remain != 0)
      addAfterNode(moveQ, remain);

    return Q;
  } else if (n > m) {
    for (int i = 0; i < smallest; ++i) {
      int tempSum = moveQ->data + moveW->data + remain;
      // cout << endl << "tempSum: " << tempSum << endl;
      moveQ->data = (tempSum) % 10;
      // cout << endl << "data: " << (tempSum)%10<< endl;
      remain = tempSum / 10;
      // cout << endl << "remain: " << remain << endl;
      if (moveQ->next != nullptr)
        moveQ = moveQ->next;
      if (moveW->next != nullptr)
        moveW = moveW->next;
    }

    if (remain != 0) {
      for (int i = 0; i < biggest - smallest; ++i) {
        int tempSum = moveQ->data + remain;
        moveQ->data = (tempSum) % 10;
        remain = tempSum / 10;

        if (moveQ->next != nullptr)
          moveQ = moveQ->next;
      }
    }

    if (remain != 0)
      addAfterNode(moveQ, remain);

    return Q;
  } else {
    for (int i = 0; i < smallest; ++i) {
      int tempSum = moveQ->data + moveW->data + remain;
      moveQ->data = (tempSum) % 10;
      remain = tempSum / 10;

      if (moveQ->next != nullptr)
        moveQ = moveQ->next;
      if (moveW->next != nullptr)
        moveW = moveW->next;
    }

    for (int i = 0; i < biggest - smallest; ++i) {
      int tempSum = moveW->data + remain;
      addAfterNode(moveQ, (tempSum) % 10);
      moveQ = moveQ->next;
      remain = tempSum / 10;

      if (moveW->next != nullptr)
        moveW = moveW->next;
    }

    if (remain != 0) {
      addAfterNode(moveQ, remain);
    }

    return Q;
  }
}

BigInt operator+(const BigInt& Q, const BigInt& W) {
  BigInt temp(Q);
  temp += W;
  return temp;
}

bool operator>(const BigInt& Q, const BigInt& W) {
  bool result = false;
  int lenQ = Length(Q);
  int lenW = Length(W);

  if (lenQ > lenW) {
    result = true;
  } else if (lenQ < lenW) {
    result = false;
  } else {
    string strQ = toString(Q);
    string strW = toString(W);
    int k = 0;

    for (int i = 0; i < lenQ; ++i) {
      int QDigit = strQ[i] - '0';
      int WDigit = strW[i] - '0';
      if (QDigit > WDigit) {
        result = true;
        break;
      } else if (QDigit < WDigit) {
        result = false;
        break;
      } else {
        k++;
      }
    }
    if (k == lenQ) {
      result = false;
    }
  }
  return result;
}

bool operator>=(const BigInt& Q, const BigInt& W) {
  return !(Q < W);
}

bool operator<(const BigInt& Q, const BigInt& W) {
  return (W > Q);
}

bool operator<=(const BigInt& Q, const BigInt& W) {
  return !(Q > W);
}

BigInt& operator-=(BigInt& Q, const BigInt& W) {
  if (Q < W) {
    throw("Underflow");
  }

  int lenQ = Length(Q);
  int lenW = Length(W);

  Tlist moveQ = Q.num;
  Tlist moveW = W.num;

  if (lenQ > lenW) {
    for (int i = 0; i < lenW; ++i) {
      int QDigit = moveQ->data;
      int WDigit = moveW->data;

      int diff = QDigit - WDigit;
      if (diff >= 0) {
        moveQ->data = diff;

        moveQ = moveQ->next;
        moveW = moveW->next;
      } else {
        (moveQ->next)->data -= 1;
        moveQ->data += 10;
        moveQ->data -= moveW->data;

        moveQ = moveQ->next;
        moveW = moveW->next;
      }
    }

    for (int i = 0; i < lenQ - lenW - 1; ++i) {
      if (moveQ->data < 0) {
        (moveQ->next)->data -= 1;
        moveQ->data += 10;

        moveQ = moveQ->next;
      } else {
        break;
      }
    }
    return Q;
  } else if (lenQ == lenW) {
    for (int i = 0; i < lenW; ++i) {
      int QDigit = moveQ->data;
      int WDigit = moveW->data;

      int diff = QDigit - WDigit;
      if (diff >= 0) {
        moveQ->data = diff;

        moveQ = moveQ->next;
        moveW = moveW->next;
      } else {
        (moveQ->next)->data -= 1;
        moveQ->data += 10;
        moveQ->data -= moveW->data;

        moveQ = moveQ->next;
        moveW = moveW->next;
      }
    }

    return Q;
  } else {
    throw("Underflow");
  }
  // return Q;
}

BigInt operator-(const BigInt& Q, const BigInt& W) {
  BigInt temp(Q);
  temp -= W;
  return temp;
}
