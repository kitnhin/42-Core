#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
    const Fixed x;
    const Fixed y;

    public:
    Point();
    Point(const Point &obj);
    ~Point();
    Point operator=(const Point &obj);

    Point(float x, float y);
    const Fixed getX() const;
    const Fixed getY() const;
};

#endif