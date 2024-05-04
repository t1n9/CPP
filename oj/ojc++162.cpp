#include <iostream>
using namespace std;

class complex {
	double real, imag;
public:
	friend complex addCom(complex c1, complex c2);
	friend void outCom(complex c);
	complex() :real(0), imag(0) {}
	complex(double r, double i) :real(r), imag(i) {}
	void set(double r, double i) { real = r; imag = i; }
};

complex addCom(complex c1, complex c2) {
	return complex(c1.real + c2.real, c1.imag + c2.imag);
}
void outCom(complex c) {
	cout << '(' << c.real << ',' << c.imag << ')' << endl;
}


int main()
{
	double real, imag;
	cin >> real >> imag;
	complex bace(real, imag);
	int t;
	cin >> t;
	while (t--) {
		char op;
		cin >> op >> real >> imag;
		complex obj;
		if (op == '+') obj.set(real, imag);
		else obj.set(-real, -imag);
		bace = addCom(bace, obj);
		outCom(bace);

	}
}