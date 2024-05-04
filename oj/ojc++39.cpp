#include <iostream>
using namespace std;

struct Birth {
	int Y;
	int M;
	int D;
};

int sort(int* q,int num) {
	int* k = new int[num];
	for (int i = 0; i < num; i++) {
		k[i] = i;
	}

	//排序
	int temp, temp_n;
	for (int i = 0; i < num - 1; i++) {
		for (int j = 0; j < num - 1 - i; j++) {
			if (q[i] > q[i + 1]) {
				temp = q[i];
				temp_n = k[i];
				q[i] = q[i + 1];
				k[i] = k[i + 1];
				q[i + 1] = temp;
				k[i + 1] = temp_n;
			}
		}
	}

	for (int i = 0; i < num; i++) {
		if (k[i] == 1) return i;
	}

}

int main()
{
	int t;
	cin >> t;
	Birth* p = new Birth[t];
	for (int o = 0; o < t; o++)
		cin >> p[o].Y >> p[o].M >> p[o].D;
	//年份比较
	int* q = new int[t];
	for (int o = 0; o < t - 1; o++) {
		q[o] = p[o].Y * 12 * 30 + p[o].M * 30 + p[o].D;
	}

	int i = sort(q, t);
	cout << p[i].Y << '-' << p[i].M << '-' << p[i].D << endl;


}
