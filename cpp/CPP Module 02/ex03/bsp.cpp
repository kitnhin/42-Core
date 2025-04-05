#include "Point.hpp"

float calculate_area(Point const a, Point const b, Point const c)
{
    //igcse shoelace method booooooooo :(((((
    //area = 1/2(x1y2 + x2y3 + x3y1 - y1x2 - y2x3 - y3x1)

    float area = 0.5f * (a.getX().toFloat()*b.getY().toFloat() + b.getX().toFloat()*c.getY().toFloat() + c.getX().toFloat()*a.getY().toFloat()
                        - a.getY().toFloat()*b.getX().toFloat() - b.getY().toFloat()*c.getX().toFloat() - c.getY().toFloat()*a.getX().toFloat());
    
        // float term1 = a.getX().toFloat() * b.getY().toFloat();
        // float term2 = b.getX().toFloat() * c.getY().toFloat();
        // float term3 = c.getX().toFloat() * a.getY().toFloat();
        // float term4 = a.getY().toFloat() * b.getX().toFloat();
        // float term5 = b.getY().toFloat() * c.getX().toFloat();
        // float term6 = c.getY().toFloat() * a.getX().toFloat();
    
        // std::cout << "Term1 (x1y2): " << term1 << std::endl;
        // std::cout << "Term2 (x2y3): " << term2 << std::endl;
        // std::cout << "Term3 (x3y1): " << term3 << std::endl;
        // std::cout << "Term4 (y1x2): " << term4 << std::endl;
        // std::cout << "Term5 (y2x3): " << term5 << std::endl;
        // std::cout << "Term6 (y3x1): " << term6 << std::endl;

    return(area > 0? area: area*-1);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	// cout << "++++++++" <<endl;
	//  cout << "vertices: " << "(" << a.getX().toFloat() << "," << a.getY().toFloat() << ")"
    // "(" << b.getX().toFloat() << "," << b.getY().toFloat() << ")"
    // "(" << c.getX().toFloat() << "," << c.getY().toFloat() << ")" << endl;
    // cout << "point: " << "(" << point.getX().toFloat() << "," << point.getY().toFloat() << ")" << endl;
	// cout << "++++++++++" << endl;

    float total_area = calculate_area(a,b,c);
    float area1 = calculate_area(a,b,point);
    float area2 = calculate_area(a,c, point);
    float area3 = calculate_area(b,c,point);
	
    // cout << "totalarea" << total_area << endl;
    // cout << "area1: " << area1 << endl;
    // cout << "area2: " << area2 << endl;
    // cout << "area3: " << area3 << endl;
    if(area1 != 0 && area2 != 0 && area3 != 0 && area1+area2+area3 == total_area)
		return true;
    return false;
}