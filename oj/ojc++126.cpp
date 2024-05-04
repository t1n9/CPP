#include <iostream>
#include <string.h>

using namespace std;

class CDate
{
private:
	int year, month, day;
public:
	CDate() { year = 2000; month = 1; day = 1; }
	CDate(int y, int m, int d) { year = y; month = m; day = d; }
	bool isLeapYear() { return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0; }
	int getYear() { return year; }
	int getMonth() { return month; }
	int getDay() { return day; }
	int getDayofYear()         //计算日期从当年1月1日算起的天数
	{
		int i, sum = day;
		int a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		int b[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };

		if (isLeapYear())
			for (i = 0; i < month; i++)   sum += b[i];
		else
			for (i = 0; i < month; i++)   sum += a[i];

		return sum;
	}
};
CDate Today(2015, 4, 7);
string T[6] = { "original","trial","backup","optical disk","hard disk","USB disk" };

class Software {
private:
	string name;
	char type, media;
	CDate cutoff;
public:
	Software(string n, char t, char m, CDate& d) :name(n), type(t), media(m), cutoff(d) {}
	Software(const Software& S) {
		name = S.name;
		type = 'B';
		media = 'H';
		cutoff = S.cutoff;
	}
	string printType() {
		int i;
		if (type == 'O') i = 0;
		if (type == 'T') i = 1;
		if (type == 'B') i = 2;
		return T[i];
	}
	string printMedia() {
		int i;
		if (media == 'D') i = 3;
		if (media == 'H') i = 4;
		if (media == 'U') i = 5;
		return T[i];
	}

	void print() {
		cout << "name:" << name << endl;
		cout << "type:" << printType() << endl;
		cout << "media:" << printMedia() << endl;
		if (cutoff.getYear() == 0 && cutoff.getMonth() == 0 && cutoff.getDay() == 0) {
			cout << "this software has unlimited use" << endl;
		}
		else {
			int rest = cutoff.getDayofYear() - Today.getDayofYear();
			if (rest >= 0)
				cout << "this software is going to be expired in " << rest << " days" << endl;
			else
				cout << "this software has expired" << endl;
		}
		cout << endl;
	}
};

int main()
{

	int t;
	cin >> t;
	while (t--) {
		string name;
		char type, media;
		int year, month, day;
		cin >> name >> type >> media >> year >> month >> day;
		CDate date(year, month, day);
		Software obj(name, type, media, date);
		obj.print();
		Software obj_cpy = obj;
		obj_cpy.print();
	}
	return 0;
}
