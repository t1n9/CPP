#include <iostream>
using namespace std;

class CPoint {
	int x, y;
public:
	friend class CRect;
	CPoint() :x(0), y(0) {}
	CPoint(int _x, int _y) :x(_x), y(_y) {}

};
class CRect {
	CPoint p1, p2;
public:
	CRect(CPoint& _p1, CPoint& _p2) {
		int temp = 0;
		if (_p1.x > _p2.x) {
			temp = _p1.x;
			_p1.x = _p2.x;
			_p2.x = temp;
		}
		if (_p1.y > _p2.y) {
			temp = _p1.y;
			_p1.y = _p2.y;
			_p2.y = temp;
		}
		p1 = _p1; p2 = _p2;
	}
	bool  isOver(CRect &obj) {
		if ((p1.x < obj.p2.x && p1.y < obj.p2.y) || (obj.p2.x < p1.x && obj.p2.y < p1.y))
			return 1;
		else return 0;
	}

};

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int x1, y1, x2, y2, x3, y3, x4, y4;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		CPoint p1(x1, y1), p2(x2, y2);
		CPoint p3(x3, y3), p4(x4, y4);
		CRect r1(p1, p2);
		CRect r2(p3, p4);
		if (r1.isOver(r2))cout << "overlapped" << endl;
		else cout << "not overlapped" << endl;
	}

}
