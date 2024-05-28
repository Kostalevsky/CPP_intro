#include <string>
#include "Vector.h"

#ifndef ISHAPE_H
#define ISHAPE_H
namespace geometry {
    class Point;
    class Segment;
    class IShape {
        public:
            virtual IShape& Move(const Vector& vector) const = 0;
            virtual bool ContainsPoint(const Point&) const = 0;
            virtual bool CrossesSegment(const Segment&) const = 0;
            virtual std::unique_ptr<IShape> Clone() const = 0;
            virtual std::string ToString() const = 0;
    };
}

#endif
