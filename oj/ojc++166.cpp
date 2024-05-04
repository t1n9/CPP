#include <iostream>
using namespace std;

class CDate;
class CTime {
	int hour, minute, second;
public:
	friend void Display(CDate& d, CTime& t);
	CTime() :hour(1), minute(1), second(1) {}
	CTime(int h, int m, int s) :hour(h), minute(m), second(s) {}
};

class CDate {
	int year, month, day;
public:
	friend void Display(CDate& d, CTime& t);
	CDate() :year(2000), month(1), day(1) {}
	CDate(int y, int m, int d) :year(y), month(m), day(d) {}
};

void Display(CDate& d, CTime& t) {
	cout << d.year << '-';
	if (d.month < 10) cout << '0';
	cout<< d.month << '-';
	if (d.day < 10) cout << '0';
	cout<< d.day << ' ';
	if (t.hour < 10)cout << '0';
	cout<< t.hour << ':';
	if (t.minute < 10)cout << '0';
	cout << t.minute << ':';
	if (t.second < 10)cout << '0';
	cout << t.second;
	cout << endl;
}


int main()
{
	int t;
	cin >> t;
	while (t--) {
		int y, mo, d, h, mi, s;
		cin >> y >> mo >> d;
		cin >> h >> mi >> s;
		CDate day(y, mo, d);
		CTime time(h, mi, s);
		Display(day, time);
	}


}