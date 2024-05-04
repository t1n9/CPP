#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
using namespace std;

string Type[6] = {
"isosceles triangle",
"right triangle",
"isosceles right triangle",
"equilateral triangle",
"general triangle",
"no triangle"
};

class CTriangle {
	double x, y, z;
	string type;
public:
	CTriangle(double a, double b, double c) :x(a), y(b), z(c) {
		type = Type[judge()];
	}
	~CTriangle() { x = 0; y = 0; z = 0; type = "none"; }

	double area() {
		double p = (x + y + z) / 2;
		return sqrt(p * (p - x) * (p - y) * (p - z));
	}

	int judge() {
		if (x + y <= z) return 5;		//非三角形
		if (x == y) {					//等腰
			if (x*1.414 == z) {
				return 2;
			}
			else {
				return 0;
			}
		}
		else{
			if ((pow(x, 2) + pow(y, 2)) == pow(z, 2)) {
				return 1;
			}
		}
		if (x == y && y == z) return 3;

		return 4;
	}
	void show() {
		cout << type;
		if (type != "no triangle")
			cout << fixed << setprecision(1) << ", " << area() << endl;
		else cout << endl;
	}

};


int main()
{
	int t;
	cin >> t;
	while (t--) {
		double a, b, c;
		cin >> a >> b >> c;
		CTriangle ct(a, b, c);
		ct.show();
	}
}
