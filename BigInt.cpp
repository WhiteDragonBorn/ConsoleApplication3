#include <algorithm>
#include <iostream>
#include <string>

#include "BigInt.h"
#include "functions.h"

using namespace std;

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
    // ���������� ��� break !
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
  /*delete num;
  num = nullptr;*/
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
//   // ����� �� �������������, � ������� �������� ������������
//   if (result.length() != 1) {
//     reverse(result.begin(), result.end());
//   }
//
//   char ctemp = result[0];
//   while (ctemp == '0') {
//     result = result.substr(1, result.size());
//     ctemp = result[0];
//   }
//   cout << result; // ������ ����� �� �������
// }

// void PrintWithRecursion(Tlist head) {
//   if (head != nullptr) {
//     cout << head->data << " ";  //
//     PrintWithRecursion(head->next);  // ���� �������� ��� ������� �������, ��
//                                      // ����� �������� �����
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
  reverse(result.begin(), result.end());  // ��������� ���� !
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

bool BigInt::operator>(BigInt& W) const {}

bool operator>(BigInt& Q, BigInt& W) {
  bool result = false;
  int lenQ = Length(Q);
  int lenW = Length(W);

  if (lenQ > lenW) {
    result = true;
  } else if (lenQ < lenW) {
    result = false;
  } else {
    string strQ = Q.toString();
    string strW = W.toString();
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

bool operator>=(BigInt& Q, BigInt& W) {
  return !(Q < W);
}

bool operator<(BigInt& Q, BigInt& W) {
  return (W > Q);
}

bool operator<=(BigInt& Q, BigInt& W) {
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