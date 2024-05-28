#include "rational.h"

Rational::Rational() : numerator_(0), denominator_(1){};

Rational::Rational(int32_t numerator) : numerator_(numerator), denominator_(1){}; // NOLINT

Rational::Rational(int32_t numerator, int32_t denominator) {
  if (denominator == 0) {
    throw RationalDivisionByZero{};
  }
  if (denominator < 0) {
    numerator_ = (-1) * numerator;
    denominator_ = (-1) * denominator;
  } else if (denominator > 0) {
    numerator_ = numerator;
    denominator_ = denominator;
  }
  ReduceRational();
}

int32_t Rational::GetNumerator() const {
  return numerator_;
}

int32_t Rational::GetDenominator() const {
  return denominator_;
}

void Rational::SetNumerator(int32_t numerator) {
  numerator_ = numerator;
  ReduceRational();
}

void Rational::SetDenominator(int32_t denominator) {
  if (denominator == 0) {
    throw RationalDivisionByZero{};
  }
  if (denominator < 0) {
    numerator_ = (-1) * numerator_;
  }
  denominator_ = std::abs(denominator);
  ReduceRational();
}

Rational Rational::operator+(const Rational &rhs) const {
  Rational lhs(numerator_, denominator_);
  lhs += rhs;
  lhs.ReduceRational();
  return lhs;
}

Rational operator+(const Rational &lhs, const int32_t &rhs) {
  Rational sum(lhs);
  sum += rhs;
  return sum;
}

Rational operator+(const int32_t &lhs, const Rational &rhs) {
  Rational sum(rhs);
  sum += lhs;
  return sum;
}

Rational Rational::operator-(const Rational &rhs) const {
  Rational lhs(numerator_, denominator_);
  lhs -= rhs;
  lhs.ReduceRational();
  return lhs;
}

Rational operator-(const Rational &lhs, const int32_t &rhs) {
  Rational sum(lhs);
  sum -= rhs;
  return sum;
}
Rational operator-(const int32_t &lhs, const Rational &rhs) {
  Rational sum(rhs);
  sum -= lhs;
  return (-1) * sum;
}

Rational Rational::operator/(const Rational &rhs) const {
  Rational lhs(numerator_, denominator_);
  lhs /= rhs;
  lhs.ReduceRational();
  return lhs;
}

Rational operator/(const Rational &lhs, const int32_t &rhs) {
  Rational div(lhs);
  div /= rhs;
  div.ReduceRational();
  return div;
}
Rational operator/(const int32_t &lhs, const Rational &rhs) {
  Rational div(lhs);
  div /= rhs;
  div.ReduceRational();
  return div;
}

Rational Rational::operator*(const Rational &rhs) const {
  Rational lhs(numerator_, denominator_);
  lhs *= rhs;
  lhs.ReduceRational();
  return lhs;
}

Rational operator*(const Rational &lhs, const int32_t &rhs) {
  Rational mul(lhs);
  mul *= rhs;
  mul.ReduceRational();
  return mul;
}
Rational operator*(const int32_t &lhs, const Rational &rhs) {
  Rational mul(rhs);
  mul *= lhs;
  mul.ReduceRational();
  return mul;
}

Rational &Rational::operator+=(const Rational &rhs) {
  numerator_ = numerator_ * rhs.denominator_ + rhs.numerator_ * denominator_;
  denominator_ = rhs.denominator_ * denominator_;
  ReduceRational();
  return *this;
}

Rational &Rational::operator-=(const Rational &rhs) {
  numerator_ = numerator_ * rhs.denominator_ - rhs.numerator_ * denominator_;
  denominator_ = rhs.denominator_ * denominator_;
  ReduceRational();
  return *this;
}

Rational &Rational::operator/=(const Rational &rhs) {
  if (rhs.numerator_ != 0) {
    if (rhs.numerator_ < 0) {
      *this *= Rational(-rhs.denominator_, -rhs.numerator_);
    } else {
      *this *= Rational(rhs.denominator_, rhs.numerator_);
    }
    ReduceRational();
    return *this;
  }
  throw RationalDivisionByZero{};
}

Rational &Rational::operator*=(const Rational &rhs) {
  numerator_ = numerator_ * rhs.numerator_;
  denominator_ = denominator_ * rhs.denominator_;
  ReduceRational();
  return *this;
}

Rational Rational::operator+() const {
  return *this;
}

Rational Rational::operator-() const {
  return -1 * (*this);
}

Rational Rational::operator++(int32_t) {
  Rational result = *this;
  ++(*this);
  return result;
}

Rational &Rational::operator++() {
  numerator_ = numerator_ + denominator_;
  return *this;
}

Rational Rational::operator--(int32_t) {
  Rational result = *this;
  --(*this);
  return result;
}

Rational &Rational::operator--() {
  numerator_ = numerator_ - denominator_;
  return *this;
}

bool Rational::operator==(const Rational &rhs) const {
  return (numerator_ * rhs.denominator_ == rhs.numerator_ * denominator_);
}

bool Rational::operator!=(const Rational &rhs) const {
  return (numerator_ * rhs.denominator_ != rhs.numerator_ * denominator_);
}

bool Rational::operator<(const Rational &rhs) const { return !(*this >= rhs); }

bool operator>(const Rational &lhs, const Rational &rhs) {
  return lhs.GetNumerator() * rhs.GetDenominator() > rhs.GetNumerator() * lhs.GetDenominator();
}

bool Rational::operator<=(const Rational &rhs) const {
  return (numerator_ * rhs.denominator_ <= rhs.numerator_ * denominator_);
}

bool Rational::operator>=(const Rational &rhs) const {
  return (numerator_ * rhs.denominator_ >= rhs.numerator_ * denominator_);
}

std::istream &operator>>(std::istream &istream, Rational &rhs) {
  istream >> rhs.numerator_;
  if (istream.peek() == '/') {
    istream.ignore();
    istream >> rhs.denominator_;
  }
  if (rhs.denominator_ == 0) {
    throw RationalDivisionByZero{};
  }
  if (rhs.denominator_ < 0) {
    rhs.numerator_ *= (-1);
    rhs.denominator_ *= (-1);
  }
  rhs.ReduceRational();
  return istream;
}

std::ostream &operator<<(std::ostream &ostream, const Rational &rhs) {
  if (rhs.denominator_ == 1) {
    ostream << rhs.numerator_;
  } else {
    ostream << rhs.numerator_ << '/' << rhs.denominator_;
  }
  return ostream;
}

Rational &Rational::ReduceRational() {
  int32_t reduce_coef = std::gcd(numerator_, denominator_);
  if (reduce_coef != 1) {
    numerator_ /= reduce_coef;
    denominator_ /= reduce_coef;
  }
  return *this;
}
