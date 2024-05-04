#include <iostream>
#include<math.h>
using namespace std;

class Point {
	double x, y;
public:
	friend double Distance(Point& a, Point& b);
	Point(double xx, double yy) :x(xx), y(yy) {}

};

double Distance(Point& a, Point& b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		Point p1(x1, y1), p2(x2, y2);
		cout << (int)Distance(p1, p2) << endl;
	}


}
