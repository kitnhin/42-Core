#include "Point.hpp"

Point::Point() :x(0), y(0)
{
}

Point::~Point()
{
}

Point::Point(const Point &obj): x(obj.getX()), y(obj.getY())
{
}

Point Point::operator=(const Point &obj)
{
    //stupid thing
    //cannot modify const variables
    //since this contains only const variables, which we cant fking modify, need to work arn it and create another object with the changed variables
    //since we created another obj, need to remove the reference cuz no longer the same object lol
    return Point(obj.getX().toFloat(), obj.getY().toFloat());
	//(void)obj;
	//return *this; // <- do this if want to do wif reference but it basically doesnt do anything
}

Point::Point(float x_, float y_): x(x_), y(y_)
{
}

const Fixed Point::getX() const
{
    return this->x;
}

const Fixed Point::getY() const
{
    return this->y;
}