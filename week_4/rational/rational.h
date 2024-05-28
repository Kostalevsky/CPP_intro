#include <numeric>
#include <sstream>
#include <stdexcept>

#ifndef RATIONAL_H
#define RATIONAL_H

class RationalDivisionByZero : public std::runtime_error {
public:
  RationalDivisionByZero() : std::runtime_error("RationalDivisionByZero") {}
};

class Rational {
public:
  Rational();
  Rational(int32_t numerator); // NOLINT
  Rational(int32_t numerator, int32_t denominator);

  int32_t GetNumerator() const;
  int32_t GetDenominator() const;
  void SetNumerator(int32_t);
  void SetDenominator(int32_t);

  Rational operator+(const Rational &rhs) const;
  Rational operator-(const Rational &rhs) const;
  Rational operator/(const Rational &rhs) const;
  Rational operator*(const Rational &rhs) const;

  Rational &operator+=(const Rational &rhs);
  Rational &operator-=(const Rational &rhs);
  Rational &operator/=(const Rational &rhs);
  Rational &operator*=(const Rational &rhs);

  Rational operator+() const;
  Rational operator-() const;

  Rational operator++(int32_t);
  Rational &operator++();
  Rational operator--(int32_t);
  Rational &operator--();

  bool operator==(const Rational &rhs) const;
  bool operator!=(const Rational &rhs) const;
  bool operator<(const Rational &rhs) const;

  bool operator<=(const Rational &rhs) const;
  bool operator>=(const Rational &rhs) const;

  friend std::istream &operator>>(std::istream &istream, Rational &rhs);
  friend std::ostream &operator<<(std::ostream &ostream, const Rational &rhs);

  Rational &ReduceRational();

private:
  int32_t numerator_ = 0;
  int32_t denominator_ = 1;
};

bool operator>(const Rational &lhs, const Rational &rhs);

Rational operator+(const Rational &lhs, const int32_t &rhs);
Rational operator+(const int32_t &lhs, const Rational &rhs);

Rational operator-(const Rational &lhs, const int32_t &rhs);
Rational operator-(const int32_t &lhs, const Rational &rhs);

Rational operator/(const Rational &lhs, const int32_t &rhs);
Rational operator/(const int32_t &lhs, const Rational &rhs);

Rational operator*(const Rational &lhs, const int32_t &rhs);
Rational operator*(const int32_t &lhs, const Rational &rhs);

#endif