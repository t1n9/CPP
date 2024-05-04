#include <iostream>
using namespace std;

class Date {
    int year, month, day;
public:
    Date(int y, int m, int d) :year(y), month(m), day(d) {}
    Date(Date& d) {
        year = d.year; month = d.month; day = d.day;
    }
    int getM() { return month; }
    int getD() { return day; }
};

class VIP {
    string no;
    Date birthday;
public:
    VIP(string n, int y, int m, int d) :birthday(y, m, d), no(n) {}
    double Discount(Date&d) {
        if (birthday.getM() == d.getM() && birthday.getD() == d.getD()) {
            return 0.5;
        }
        else {
            return 0.95;
        }
    }
    string getNo() { return no; }
};

int main()
{
    int y, m, d, t;
    cin >> y >> m >> d >> t;
    Date today(y, m, d);
    while (t--) {
        string n;
        cin >> n >> y >> m >> d;
        VIP V(n, y, m, d);
        double price;
        cin >> price;
        price *= V.Discount(today);
        cout << V.getNo() << "'s consumption is " << int(price) << endl;
    }

}
