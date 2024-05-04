//头文件和日期类声明
#include<iostream>
#include<iomanip>
using namespace std;

class TDate {
private:
    int year, month, day;
public:
    int getYear() { return year; }
    int getMonth() { return month; }
    int getDay() { return day; }
    void set(int y, int m, int d);
    void print();
    void addOneDay();
};

//----在以下区域完成部分成员函数的类外定义----
/********** Write your code here! **********/
void TDate::set(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}

void TDate:: print() {
	cout << year;
	if (month < 10)
		cout << '0' << month;
	else
		cout << month;
	if (day < 10)
		cout << '0' << day;
	else
		cout << day;
}

void TDate::addOneDay() {
	int run_Y = 0; int run_M = 0;
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		run_M = 1;
	if (year % 4 == 0)
		run_Y = 1;


	if (month == 2) {		//2月
		if (run_Y) {	// 闰年2月
			if (day + 1 == 30) {
				month = 3;
				day = 1;
			}
			else {
				day++;
			}
		}
		else {			//非闰年2月
			if (day + 1 == 29) {
				month = 3;
				day = 1;
			}

			else {
				day++;
			}
		}

	}
	else if (month == 12) {		//12月
		if (day + 1 == 32) {
			year++;
			month = 1;
			day = 1;
		}
		else {
			day++;
		}
	}
	else {						//1、3~11月
		if (run_M) {
			if (day + 1 == 32) {
				month++;
				day = 1;
			}
			else {
				day++;
			}
		}
		else {
			if (day + 1 == 31) {
				month++;
				day = 1;
			}
			else {
				day++;
			}
		}
	}


}



/*******************************************/
//主函数如下
int main()
{
    int t, y, m, d;
    cin >> t;
    while (t--)
    {
        TDate d1;
        cin >> y >> m >> d;
        d1.set(y, m, d);
        cout << "Today-";
        d1.print();
        d1.addOneDay();
        cout << " Tomorrow-";
        d1.print();
        cout << endl;
    }
    return 0;
}
