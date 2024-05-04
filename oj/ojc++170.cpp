#include <iostream>
using namespace std;

class CCow {
	int num;
	static int sum;
public:
	CCow(int n) :num(n) {}
	CCow() :num(1) {}
	static void init() { sum = 1; }
	void decrease_n(int i) { num -= i; }
	void decrease_s(int i) { sum -= i; }
	void increase_n(int i) { num += i; }
	void increase_s(int i) { sum += i; }
	void set(int i) { num = i; }
	int getNum() { return num; }
	static int getSum() { return sum; }
};

int CCow::sum = 1;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		CCow* c = new CCow[n];
		CCow::init();		//每次测试初始化
		for (int i = 1; i < n; i++) {
			c[i].set(c[i - 1].getNum());
			if (i >= 10) {		//母牛11年死亡
				c[i].decrease_s(c[i - 10].getNum());	//总数减去十年前的牛
				for (int j = i; j > i - 10; j--) {	
					c[j].decrease_n(c[i - 10].getNum());	//死去的牛后面都要将其减去
				}
			}
			if (i >= 3) {
				c[i].increase_n(c[i - 3].getNum());
				c[i].increase_s(c[i - 3].getNum());
			}
		}
		cout << CCow::getSum() << endl;
		delete c;

	}

}
