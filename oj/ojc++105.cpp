#include <iostream>
#include<cstring>
#include<string.h>
using namespace std;

class Goods {		//商品
	char no[10], color[10], size[10], name[30];
	double price;
	int num;
public:
	Goods() :no(), color(), size(), name(), price(0),num(0) {}
	Goods(char*n,char*na,char*s,char*c,double p,int nu) {
		//no = n; name = na; size = s; color = c;
		strcpy(no, n); 
		strcpy(name, na); 
		strcpy(size, s);
		strcpy(color, c);
		price = p; num = nu;
	}
	void set(char* n, char* na, char* s, char* c, double p,int nu) {
		//no = n; name = na; size = s; color = c;
		strcpy(no, n); 
		strcpy(name, na);
		strcpy(size, s);
		strcpy(color, c);
		price = p; num = nu;
	}
	void show() {
		cout << name << ',' << color << ',' << size << ',' << price << ',' << num << ',' << price * num << endl;
	}
	void addNum(int i) { num += i; }
	char* getNo() { return no; }
	int getNum() { return num; }
	double getPrice() { return price; }
};

class Cart {		//购物车
	Goods* G;
	int number;
	double price_sum;
public:
	Cart() {
		G = new Goods[20];
		number = 0;
		price_sum = 0;
	}
	void add(char* no, char* name, char* size, char* color, double price,int num) {
		G[number].set(no, name, size, color, price, num);
		number++;
		price_sum += price * num;
	}
	void dele(char* no) {
		for (int i = 0; i < number; i++)		//删除第i个
			if (strcmp(G[i].getNo(), no)) {
				number -= G[i].getNum();
				price_sum -= G[i].getNum() * G[i].getPrice();
				for (int j = i; j < number; j++) {
					G[j] = G[j + 1];
				}
				break;
			}
	}
	void up(char* no) {
		for (int i = 0; i < number; i++)
			if (strcmp(G[i].getNo(), no)) {
				G[i].addNum(1);
				price_sum += G[i].getPrice();
				break;
			}
		number++;
	}
	void down(char* no) {
		for (int i = 0; i < number; i++)
			if (strcmp(G[i].getNo(), no)) {
				G[i].addNum(-1);
				if (G[i].getNum() == 0) G[i].addNum(1);		//减少失败
				else price_sum -= G[i].getPrice();			//减少成功
				break;
			}
	}
	void list() {
		for (int i = 0; i < number; i++) {
			G[i].show();
		}
		cout << "----------" << endl;
		cout << number << "件商品,总商品金额" << price_sum << endl;
	}
};



int main()
{
	int t;
	cin >> t;
	while (t--) {
		Cart obj;
		int n;
		cin >> n;
		while (n--) {
			double price;
			int number;
			char oper[10];
			cin >> oper;
			if (!strcmp(oper, "ADD")) {
				char no[10], name[30], size[10], color[10];
				cin >> no >> name >> size >> color >> price >> number;
				obj.add(no, name, size, color, price, number);
			}
			else if (!strcmp(oper, "DELETE")) {
				char no[10];
				cin >> no;
				obj.dele(no);
			}
			else if (!strcmp(oper, "UP")) {
				char no[10];
				cin >> no;
				obj.up(no);
			}
			else if (!strcmp(oper, "DOWN")) {
				char no[10];
				cin >> no;
				obj.down(no);
			}
		}
		cout << "商品清单:" << endl << "商品, 颜色, 尺码, 单价, 数量, 小计" << endl;
		obj.list();
	}
}
