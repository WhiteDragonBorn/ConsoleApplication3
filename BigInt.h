#pragma once

#include <string>

#include "functions.h"

class BigInt {
 private:
  Tlist num;

 public:
  BigInt(std::string&);
  BigInt(const BigInt&);
  ~BigInt();

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
