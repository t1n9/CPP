#include <iostream>
using namespace std;

struct SPoint {
	int x;
	int y;
};
struct SRect {
	SPoint p1;
	SPoint p2;
};

bool isoverlap(const SRect& rect1, const SRect& rect2) {
	
	if (rect1.p1.x >= rect2.p1.x && rect1.p1.x<=rect2.p2.x && rect1.p1.y>=rect2.p1.y && rect1.p1.y <= rect2.p2.y) {
		return 1;
	}
	else if (rect2.p1.x >= rect1.p1.x && rect2.p1.x<=rect1.p2.x && rect2.p1.y>=rect1.p1.y && rect2.p1.y <= rect1.p2.y) {
		return 1;
	}
	return 0;
}

int main()
{
	int t;
	cin >> t;
	for (int o = 0; o < t; o++) {
		SRect rect1, rect2;
		cin >> rect1.p1.x >> rect1.p1.y >> rect1.p2.x >> rect1.p2.y;
		cin>> rect2.p1.x >> rect2.p1.y >> rect2.p2.x >> rect2.p2.y;

		//找出每个矩形左下角的点
		if (rect1.p1.x > rect1.p2.x)
			swap(rect1.p1.x, rect1.p2.x);
		if (rect1.p1.y > rect1.p2.y)
			swap(rect1.p1.y, rect1.p2.y);
		if (rect2.p1.x > rect2.p2.x)
			swap(rect2.p1.x, rect2.p2.x);
		if (rect2.p1.y > rect2.p2.y)
			swap(rect2.p1.y, rect2.p2.y);



		if (isoverlap(rect1, rect2)) {
			cout << "overlapped" << endl;
		}
		else {
			cout << "not overlapped" << endl;
		}
	}
}
