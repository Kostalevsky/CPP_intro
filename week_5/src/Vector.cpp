#include "../Vector.h"

namespace geometry {
    Vector::Vector() : x_(0), y_(0) {};
    Vector::Vector(int x, int y) : x_(x), y_(y) {};

    int Vector::GetX() const{
        return x_;
    }

    int Vector::GetY() const{
        return y_;
    }

    void Vector::SetX(int x_coord) {
        x_ = x_coord;
    }

    void Vector::SetY(int y_coord) {
        y_ = y_coord;
    }

    Vector Vector::operator+(const Vector &rhs) const {
        return Vector(x_ + rhs.x_, y_ + rhs.y_);
    }

    Vector Vector::operator-(const Vector &rhs) const {
        return Vector(x_ - rhs.x_, y_ - rhs.y_);
    }

    Vector Vector::operator/(int number) const {
        return Vector(x_ / number, y_ / number);
    }

    Vector Vector::operator*(int number) const {
        return Vector(x_ * number, y_ * number);
    }

    Vector Vector::operator+() const {
        return *this;
    }

    Vector Vector::operator-() const {
        return Vector(-x_, -y_);
    }

    Vector& Vector::operator+=(const Vector &rhs) {
        x_ += rhs.x_;
        y_ += rhs.y_;
        return *this;
    }

    Vector& Vector::operator-=(const Vector &rhs) {
        x_ -= rhs.x_;
        y_ -= rhs.y_;
        return *this;
    }

    Vector& Vector::operator/=(int number) {
        x_ /= number;
        y_ /= number;
        return *this;
    }

    Vector& Vector::operator*=(int number) {
        x_ *= number;
        y_ *= number;
        return *this;
    }

    bool Vector::operator==(const Vector &rhs) const{
        return x_ == rhs.x_ && y_ == rhs.y_;
    }
}
