#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(5, 10);
    Point p(5, 5);
    bool result = bsp(a,b,c,p);
    bool expected = true;
    cout << "vertices: " << "(" << a.getX().toFloat() << "," << a.getY().toFloat() << ")"
    "(" << b.getX().toFloat() << "," << b.getY().toFloat() << ")"
    "(" << c.getX().toFloat() << "," << c.getY().toFloat() << ")" << endl;
    cout << "point: " << "(" << p.getX().toFloat() << "," << p.getY().toFloat() << ")" << endl;
    cout << "expected results: " << expected << endl;
    if(result == expected)
        cout << "results calculated match expected" << endl;
    else
        cout << "results dont match :(" << endl;
}