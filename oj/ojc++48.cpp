
#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int o = 0; o < t; o++) {
		int num;
		cin >> num;
		int** p = new int* [num];
		for (int i = 0; i < num; i++) {
			p[i] = new int[num];
		}
		
		int min = 1;
		int max = num * num;
		//蛇形矩阵按照右下左上顺序,右1上2左3下4
		int turn = 1;
		int w = 0; int h = 0;
		int a = 0;
		for (int i = 0; i < max; i++) {
			if (turn == 1) {
				p[h][w] = ++a;
				if (w == num - 1 || (p[h][w + 1] >= min && p[h][w + 1] <= max)) {
					turn = 2;
					h++;
					continue;
				}
				else {
					w++;
				}
			}
			if (turn == 2) {
				p[h][w] = ++a;
				if (h == num - 1 || (p[h + 1][w] >= min && p[h + 1][w] <= max)) {
					turn = 3;
					w--;
					continue;
				}
				else {
					h++;
				}
			}
			if (turn == 3) {
				p[h][w] = ++a;
				if (w == 0 || (p[h][w - 1] >= min && p[h][w - 1] <= max)) {
					turn = 4;
					h--;
					continue;
				}
				else {
					w--;
				}
			}
			if (turn == 4) {
				p[h][w] = ++a;
				if (p[h - 1][w] >= min && p[h - 1][w] <= max) {
					turn = 1;
					w++;
					continue;
				}
				else {
					h--;
				}
			}

		}

		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				cout << p[i][j];
				if (j != num - 1)
					cout << ' ';
			}
			cout << endl;
		}
		cout << endl;
	}

}

