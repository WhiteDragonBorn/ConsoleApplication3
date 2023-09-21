#include "BigInt.h"

#include <algorithm>
#include <iostream>
#include <string>

#include "functions.h"

using namespace std;

void BigInt::TerminateZeros(string& str) {
  char startchar = str[0];
  while (startchar == '0' && str.size() > 1) {
    str = str.substr(1, str.size());
    startchar = str[0];
  }
}

BigInt::BigInt() {
  num = new Node;
  //num->data = 0;
  //num->next = nullptr;
}

BigInt::BigInt(string& str) {
  BigInt::TerminateZeros(str);
  num = new Node;
  num->data = str[0] - '0';
  num->next = nullptr;
  for (int i = 1; i < str.length(); ++i) {
    addToHead(num, (str[i] - '0'));
  }
}

BigInt::BigInt(const BigInt& Q) {
  num = new Node;
  Tlist moveNum = num;
  Tlist moveQ = Q.num;

  num->data = moveQ->data;
  moveQ = moveQ->next;

  while (moveQ != nullptr) {
    addAfterNode(moveNum, moveQ->data);

    moveNum = moveNum->next;
    moveQ = moveQ->next;
  }
}

BigInt::~BigInt() {
  clear(num);
  /*delete num;
  num = nullptr;*/
}

int BigInt::length() {
  Tlist moveQ = num;
  int length = 0;
  while (moveQ != nullptr) {
    length++;
    moveQ = moveQ->next;
  }
  delete moveQ;

  return length;
}

std::string BigInt::toString() {
  string result = "";
  Tlist moveQ = num;

  while (moveQ != nullptr) {
    result = to_string(moveQ->data) + result;
    moveQ = moveQ->next;
  }
  BigInt::TerminateZeros(result);
  return result;
}

BigInt& BigInt::operator=(const BigInt& W) {
  Tlist moveQ = this->num;
  Tlist moveW = W.num;

  if (moveW) {
    moveQ->data = moveW->data;

    moveW = moveW->next;

    while (moveW != nullptr) {
      addAfterNode(moveQ, moveW->data);

      moveQ = moveQ->next;
      moveW = moveW->next;
    }
  }

  return *(this);
}
bool BigInt::operator>(BigInt& W) {
  bool result = false;
  int lenQ = this->length();
  int lenW = W.length();

  if (lenQ > lenW) {
    result = true;
  } else if (lenQ < lenW) {
    result = false;
  } else {
    string strQ = this->toString();
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

bool BigInt::operator>=(BigInt& W) { return !(*(this) < W); }

bool BigInt::operator<(BigInt& W) { return (W > *(this)); }

bool BigInt::operator<=(BigInt& W) { return !(*(this) > W); }

BigInt& BigInt::operator+=(BigInt& W) {
  int remain = 0;

  int n = this->length();
  int m = W.length();

  Tlist moveQ = num;
  Tlist moveW = W.num;

  int biggest = (n > m) ? n : m;
  int smallest = (n < m) ? n : m;

  if (n == m) {
    for (int i = 0; i < biggest; ++i) {
      int tempSum = moveQ->data + moveW->data + remain;
      moveQ->data = (tempSum) % 10;
      remain = tempSum / 10;
      if (moveQ->next != nullptr) moveQ = moveQ->next;
      if (moveW->next != nullptr) moveW = moveW->next;
    }
    if (remain != 0) addAfterNode(moveQ, remain);

    //return *(this);
  } else if (n > m) {
    for (int i = 0; i < smallest; ++i) {
      int tempSum = moveQ->data + moveW->data + remain;
      moveQ->data = (tempSum) % 10;
      remain = tempSum / 10;
      if (moveQ->next != nullptr) moveQ = moveQ->next;
      if (moveW->next != nullptr) moveW = moveW->next;
    }

    if (remain != 0) {
      for (int i = 0; i < biggest - smallest; ++i) {
        int tempSum = moveQ->data + remain;
        moveQ->data = (tempSum) % 10;
        remain = tempSum / 10;

        if (moveQ->next != nullptr) moveQ = moveQ->next;
      }

      addAfterNode(moveQ, remain);
    }

    //return *(this);
  } else {
    for (int i = 0; i < smallest; ++i) {
      int tempSum = moveQ->data + moveW->data + remain;
      moveQ->data = (tempSum) % 10;
      remain = tempSum / 10;

      if (moveQ->next != nullptr) moveQ = moveQ->next;
      if (moveW->next != nullptr) moveW = moveW->next;
    }

    for (int i = 0; i < biggest - smallest; ++i) {
      int tempSum = moveW->data + remain;
      addAfterNode(moveQ, (tempSum) % 10);
      moveQ = moveQ->next;
      remain = tempSum / 10;

      if (moveW->next != nullptr) moveW = moveW->next;
    }

    if (remain != 0) {
      addAfterNode(moveQ, remain);
    }

    //return *(this);
  }

  return *this;
}

BigInt BigInt::operator+(BigInt& W) {
  BigInt toReturn(*(this));
  toReturn += W;
  return toReturn;
}

BigInt& BigInt::operator-=(BigInt& W) {
  if (*(this) < W) {
    throw("Underflow");
  }

  int lenQ = this->length();
  int lenW = W.length();

  Tlist moveQ = this->num;
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
    //return *(this);
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

    //return *(this);
  } else {
    throw("Underflow");
  }
  return *(this);
}

BigInt BigInt::operator-(BigInt& W) {
  BigInt toReturn(*(this));
  toReturn -= W;
  return toReturn;
}
