#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std; 

class Equation {
    double a, b, c;
public:
    Equation() :a(1), b(1), c(0) {}
    void set(double a, double b, double c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }


    void getRoot() {
        double x1, x2, d;
        d = pow(b, 2) - 4 * a * c;
        if (d > 0) {         //两个不相等的实根
            x1 = (sqrt(d) - b) / (2 * a);
            x2 = -(sqrt(d) + b) / (2 * a);
            cout << "x1=" << x1 << " x2=" << x2 << endl;
        }
        else if (d == 0) {    //两个相等的实根
            x1 = (sqrt(d) - b) / (2 * a);
            cout << "x1=x2=" << x1 << endl;
        }
        else {                      //两个共轭复根
            double e = -(b / (2 * a));
            double f = (sqrt(-d) / (2 * a));
            cout << "x1=" << e << "+" << f << "i x2=" << e << '-' << f << 'i' << endl;

        }

    }


};

int main()
{
    int t;
    cin >> t;
    cout << fixed << setprecision(2);
    while (t--) {
        double a, b, c;
        cin >> a >> b >> c;
        Equation e;
        e.set(a, b, c);
        e.getRoot();
    }
}