#include <iostream>
#include <iomanip>
using namespace std;

class Point {
	double x, y;
public:
	Point();
	Point(double x_value, double y_value);
	double getX();
	double getY();
	void setX(double x_value);
	void setY(double y_value);
	double distanceToAnotherPoint(Point P);
};

Point::Point():x(0),y(0) {}
Point::Point(double x_value, double y_value) :x(x_value), y(y_value) {}
double Point::getX() { return x; }
double Point::getY() { return y; }
void Point::setX(double x_value) { x = x_value; }
void Point::setY(double y_value) { y = y_value; }
double Point::distanceToAnotherPoint(Point P) {	return sqrt(pow((x - P.getX()), 2) + pow((y - P.getY()), 2));}



int main()
{
	int t;
	cin >> t;
	while (t--) {
		double p1x, p1y, p2x, p2y;
		cin >> p1x >> p1y >> p2x >> p2y;
		Point P1(p1x, p1y);
		Point P2; P2.setX(p2x); P2.setY(p2y);
		cout << fixed << setprecision(2) << "Distance of Point(" << P1.getX() << "," << P1.getY() << ") to Point(" << P2.getX() << "," << P2.getY() << ") is " << P1.distanceToAnotherPoint(P2) << endl;


	}
	return 0;
}
