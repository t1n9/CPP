#include <iostream>
#include<string>
using namespace std;

int main()
{
	int t = 0;
	cin >> t;
	for (int o = 0; o < t; o++) {
		int num;
		cin >> num;
		string a[12] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
		string* p = &a[0];
		if (num < 1 || num>12) {
			cout << "error" << endl;
		}
		else {
			cout << *(p + num - 1) << endl;
		}
		
		

	}

}
