#include <iostream>
#include<math.h>
using namespace std;

class Point {
    double x, y;
public:
    Point() :x(0), y(0) {}
    Point(double x_value, double y_value) :x(x_value), y(y_value) {}
    ~Point() {}
    double getX() { return x; }
    double getY() { return y; }
    void setXY(double x1, double y1) { x = x1; y = y1; }
    void setX(double x_value) { x = x_value; }
    void setY(double y_value) { y = y_value; }
    double getDisTo(Point& p) {
        return sqrt(pow(x - p.getX(), 2) + pow(y - p.getY(), 2));
    }
};

class Circle {
    Point centre;
    double radius;
public:
    Circle() :centre(0, 0), radius(1) {}
    Circle(double x, double y, double r) :centre(x, y), radius(r) {}
    double getArea() {
        return 3.14 * radius * radius;
    }
    void moveCentreTo(double x1, double y1) {
        centre.setXY(x1, y1);
    }
    int contain(Point& p) {
        if (centre.getDisTo(p) <= radius) return 1;
        else return 0;
    }
};

int main()
{
    double x0, y0, r0;
    cin >> x0 >> y0 >> r0;
    Circle c(x0, y0, r0);
    int t;
    cin >> t;
    Point* p = new Point[t];
    int i = 0;
    for (i = 0; i < t; i++) {
        double x1, y1;
        cin >> x1 >> y1;
        p[i].setXY(x1, y1);
    }
    for (i = 0; i < t; i++) {
        if (!c.contain(p[i])) cout << "outside" << endl;
        else cout << "inside" << endl;
    }
    cin >> x0 >> y0;
    c.moveCentreTo(x0, y0);
    cout << "after move the centre of circle:" << endl;
    for (i = 0; i < t; i++) {
        if (!c.contain(p[i])) cout << "outside" << endl;
        else cout << "inside" << endl;
    }


}