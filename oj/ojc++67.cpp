#include <iostream>
#include <iomanip> //必须包含这个头文件

using namespace std;

void main()
{
	int t;
	cin >> t;
	for (int o = 0; o < t; o++) {
		double a = 3.141596;
		float rate[4] = { 6.2619 ,6.6744 ,0.0516 ,0.8065 };
		float* const p = &rate[0];

		char A;
		double b = 3.141596;
		cin >> A;
		cin >> b;
		if (A == 'D')
			a = b * (*p);
		else if (A == 'E')
			a = b * (*(p + 1));
		else if (A == 'Y')
			a = b * (*(p + 2));
		else if (A == 'H')
			a = b * (*(p + 3));
		cout << fixed << setprecision(4) << a << endl;  //输出小数点后3位
	}
	

}