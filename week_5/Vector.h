#include <iostream>

#ifndef VECTOR_H
#define VECTOR_H

namespace geometry {
    class Vector {
    public:
        Vector();
        Vector(int x, int y);

        int GetX() const;
        int GetY() const;
        void SetX(int x_coord);
        void SetY(int y_coord);

        Vector operator+(const Vector &rhs) const;
        Vector operator-(const Vector &rhs) const;
        Vector operator/(int number) const;
        Vector operator*(int number) const;

        Vector operator+() const;
        Vector operator-() const;

        Vector &operator+=(const Vector &rhs);
        Vector &operator-=(const Vector &rhs);
        Vector &operator/=(int number);
        Vector &operator*=(int number);

        bool operator==(const Vector &rhs) const;
    private:
        int x_;
        int y_;
    };
}

#endif