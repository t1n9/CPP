//头文件区域
#include <iostream>
using namespace std;
//填空区域1：类CDate的定义
/********** Write your code here! **********/
class CDate {
	int year, month, day, flag;
public:
	CDate(int d, int m, int y) :year(y), month(m), day(d),flag(0) {}
	CDate(const CDate& obj) {
		year = obj.year; month = obj.month; day = obj.day; flag = obj.flag;
		if (month == 2) {		//二月
			if (!(year % 4)) {	//闰
				if (day == 29) { month = 3; day = 1; flag = 1; }
				else { day++; }
			}
			else {
				if (day == 28) { month = 3; day = 1; flag = 1; }
				else { day++; }
			}
		}
		if (month == 12 && flag == 0) {
			if (day == 31) { year++; month = 1; day = 1; flag = 1; }
			else { day++; }
		}
		if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10)&&flag == 0) {
			if (day == 31) { month++; day = 1; }
			else { day++; }
		}
		if ((month == 4 || month == 6 || month == 9 || month == 11)&&flag == 0) {
			if (day == 30) { month++; day = 1; }
			else { day++; }
		}
	}
	void print() {
		cout << year << '/' << month << '/' << day  << endl;
	}
};



/*******************************************/
//主函数区域
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	CDate d1(a, b, c);
	CDate d2 = d1;
	CDate d3(d2);
	d1.print();
	d2.print();
	d3.print();
	return 0;
}

