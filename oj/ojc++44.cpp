#include <iostream>
using namespace std;

void find(int* num, int n, int& minIndex, int& maxIndex) {
	int* index = new int[n];
	for (int i = 0; i < n; i++)
		index[i] = i;
	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; j > i; j--) {
			if (num[i] > num[j]) {
				swap(num[i], num[j]);
				swap(index[i], index[j]);
			}
		}
	}
	minIndex = index[0];
	maxIndex = index[n - 1];
}
int main()
{
	int t;
	cin >> t;
	for (int o = 0; o < t; o++) {
		int n;
		cin >> n;
		int* num = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> num[i];
		}
		int minIndex, maxIndex;
		find(num, n, minIndex, maxIndex);
		cout << "min=" << num[0] << ' ' << "minindex=" << minIndex << endl;
		cout << "max=" << num[n - 1] << ' ' << "maxindex=" << maxIndex << endl;
		cout << endl;
	}
}
