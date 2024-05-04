#include <iostream>
using namespace std;

void comp(int& a, int& b, int& c) {
	int m1, m2, m3;
	if (a > b && a > c) {
		m1 = a;
		if (b > c) {
			m2 = b;
			m3 = c;
		}
		else if (b < c) {
			m2 = c;
			m3 = b;
		}
	}
	else if (b > a && b > c) {
		m1 = b;
		if (a > c) {
			m2 = a;
			m3 = c;
		}
		else if (a < c) {
			m2 = c;
			m3 = a;
		}
	}
	else if (c > b && c > a) {
		m1 = c;
		if (b > a) {
			m2 = b;
			m3 = a;
		}
		else if (b < a) {
			m2 = a;
			m3 = b;
		}
	}
	a = m1;
	b = m2;
	c = m3;
}

int main()
{
	int t;
	cin >> t;
	for (int o = 0; o < t; o++) {
		int q, w, e;
		cin >> q >> w >> e;
		comp(q, w, e);
		cout << q << ' ' << w << ' ' << e << endl;
	}
	return 0;
}
