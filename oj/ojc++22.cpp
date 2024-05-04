#include <iostream>
using namespace std;

struct Fraction {
	int numerator;		//分子
	int denominator;	//分母
};

//最大公约数
int getGCD(int p1, int p2) {
	int temp;
	if (p2 > p1) {
		temp = p1;
		p1 = p2;
		p2 = temp;
	}
	for (int i = 0;p1%p2 == 0; i++) {
		temp = p1 % p2;
		p1 = p2;
		p2 = temp;
	}
	return p2;
}

//加
int addFS(Fraction a, Fraction b) {

}
//减
int subFS(Fraction a, Fraction b) {

}
//乘
int mulFS(Fraction a, Fraction b) {

}
//除
int divFS(Fraction a, Fraction b) {

}

int main()
{
	int t;
	cin >> t;
	for (int o = 0; o < t; o++) {
		Fraction p, q;
		cin>>


	}
}
