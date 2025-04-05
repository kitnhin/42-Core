#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);

	cout << "\nTest1 (inside triangle):" << endl;
	cout << "-------------" << endl;
    Point p1(5.0f, 5.0f);
    bool result = bsp(a,b,c,p1);
    bool expected = true;
    cout << "vertices: " << "(" << a.getX().toFloat() << "," << a.getY().toFloat() << ")"
    "(" << b.getX().toFloat() << "," << b.getY().toFloat() << ")"
    "(" << c.getX().toFloat() << "," << c.getY().toFloat() << ")" << endl;
    cout << "point: " << "(" << p1.getX().toFloat() << "," << p1.getY().toFloat() << ")" << endl;
    cout << "expected results: " << expected << endl;
    if(result == expected)
        cout << "results calculated match expected" << endl;
    else {
        cout << "results dont match :(" << endl; } 

	
	cout <<"\nTest2 (outside triangle):" << endl;
	cout << "-------------" << endl;
    Point p2(100.0f, 100.0f);
    result = bsp(a,b,c,p2);
    expected = false;
    cout << "vertices: " << "(" << a.getX().toFloat() << "," << a.getY().toFloat() << ")"
    "(" << b.getX().toFloat() << "," << b.getY().toFloat() << ")"
    "(" << c.getX().toFloat() << "," << c.getY().toFloat() << ")" << endl;
    cout << "point: " << "(" << p2.getX().toFloat() << "," << p2.getY().toFloat() << ")" << endl;
    cout << "expected results: " << expected << endl;
    if(result == expected)
        cout << "results calculated match expected" << endl;
    else {
        cout << "results dont match :(" << endl; } 

	cout <<"\nTest3 (on the vertices triangle):" << endl;
	cout << "-------------" << endl;
    Point p3(0.0f, 0.0f);
    result = bsp(a,b,c,p3);
    expected = false;
    cout << "vertices: " << "(" << a.getX().toFloat() << "," << a.getY().toFloat() << ")"
    "(" << b.getX().toFloat() << "," << b.getY().toFloat() << ")"
    "(" << c.getX().toFloat() << "," << c.getY().toFloat() << ")" << endl;
    cout << "point: " << "(" << p3.getX().toFloat() << "," << p3.getY().toFloat() << ")" << endl;
    cout << "expected results: " << expected << endl;
    if(result == expected)
        cout << "results calculated match expected" << endl;
    else {
        cout << "results dont match :(" << endl; } 

	cout <<"\nTest4 (on the edge triangle):" << endl;
	cout << "-------------" << endl;
    Point p4(7.5f, 5.0f);
    result = bsp(a,b,c,p4);
    expected = false;
    cout << "vertices: " << "(" << a.getX().toFloat() << "," << a.getY().toFloat() << ")"
    "(" << b.getX().toFloat() << "," << b.getY().toFloat() << ")"
    "(" << c.getX().toFloat() << "," << c.getY().toFloat() << ")" << endl;
    cout << "point: " << "(" << p4.getX().toFloat() << "," << p4.getY().toFloat() << ")" << endl;
    cout << "expected results: " << expected << endl;
    if(result == expected)
        cout << "results calculated match expected" << endl;
    else {
        cout << "results dont match :(" << endl; } 

    return 0;
	//take note negative points wouldnt work cuz my fixed class doesnt allow that
}

//main logic:
//total area of triangle = total of total area of triangles made up by 2 vertices and the point
//if any of the areas of the triangles of 2 vertices and the point is 0, means the point on the lines or vertices, so false