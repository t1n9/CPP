#include <iostream>
using namespace std;

class Date {
	int year, month, day;
public:
	Date();
	Date(int y, int m, int d);
	int getYear();
	int getMonth();
	int getDay();
	void setDate(int y, int m, int d);
	void print();
	void addOneDay();
};

Date::Date() :year(1900), month(1), day(1){}
Date::Date(int y, int m, int d):year(y),month(m),day(d){}
int Date::getDay() { return day; }
int Date::getMonth(){return month;}
int Date::getYear() { return year; }
void Date::setDate(int y, int m, int d) {
	year = y; month = m; day = d;
}

void Date::print() {
	cout << "Today is " << year << '/';
	if (month < 10)
		cout << '0';
	cout << month << '/';
	if (day < 10)
		cout << '0';
	cout << day << endl;
	addOneDay();
	cout << "Tomorrow is " << year << '/';
	if (month < 10)
		cout << '0';
	cout << month << '/';
	if (day < 10)
		cout << '0';
	cout << day << endl;
}
void Date::addOneDay() {
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10) {
		if (day == 31) {
			day = 1; month++;
		}
		else { day++; }
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day == 30) {
			day = 1; month++;
		}
		else { day++; }
	}
	bool isLeap = !(year % 4);
	if (isLeap && month == 2) {		//闰年2月
		if (day == 29) {
			day = 1; month = 3;
		}
		else { day++; }
	}
	else if(month == 2) {			//普通2月
		if (day == 28) {
			day = 1; month = 3;
		}
		else { day++; }
	}
	if (month == 12) {				//12月
		if (day == 31) {			//跨年
			day = 1; month = 1; year++;
		}
		else { day++; }
	}
	
}


int main()
{
	int t;
	cin >> t;
	int o = 0;
	while (t--) {
		int y, m, d;
		cin >> y >> m >> d;
		if (o % 2) {
			Date obj;
			obj.setDate(y, m, d);
			obj.print();
		}
		else {
			Date obj(y, m, d);
			obj.print();
		}		
		o++;
	}
}