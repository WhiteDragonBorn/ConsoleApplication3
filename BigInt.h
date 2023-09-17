#pragma once

#include <string>

#include "functions.h"

class BigInt {
 private:
  Tlist num;

  void TerminateZeros(std::string&);

 public:
  BigInt(std::string&);
  BigInt(const BigInt&);
  ~BigInt();

  int length();
  std::string toString();

  BigInt& operator=(const BigInt&);

  bool operator>(BigInt&);
  bool operator>=(BigInt&);
  bool operator<(BigInt&);
  bool operator<=(BigInt&);

  BigInt& operator+=(BigInt&);
  BigInt operator+(BigInt&);

  BigInt& operator-=(BigInt&);
  BigInt operator-(BigInt&);
};
