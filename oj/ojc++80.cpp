#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int o = 0; o < t; o++) {
		int matr[2][3];
		int a[3][2];
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> matr[i][j];
			}
		}
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 3; j++) {
				//思考！！！！！！！！！！！！！！！！！！！！！！！
				*(*a + (2 - j) * 2 + i) = *(*matr + i * 3 + j);
			}
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 2; j++) {
				cout << a[i][j] << ' ';
			}
			cout << endl;
		}




	}

}
