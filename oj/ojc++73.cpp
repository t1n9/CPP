#include <iostream>
#include <cstring>
using namespace std;

class Student {
private:
	char name[20];
	char no[20];
	char coll[20];
	char maj[20];
	char sex[20];
	char addr[100];
	char pho[20];

public:
	void set(char* na,char* n,char* c,char* m,char* s,char* a,char* p){
		strcpy(name, na);
		strcpy(no, n);
		strcpy(coll, c);
		strcpy(maj, m);
		strcpy(sex, s);
		strcpy(addr, a);
		strcpy(pho, p);
	}
	//void show() {
	//	cout << name << ' ' << no << ' ' << coll << ' ' << maj << ' ' << sex << ' ' << addr << ' ' << pho << endl;
	//}
};

int main()
{
	int n;
	cin >> n;
	Student obj;
	char name[20];
	char no[20];
	char coll[20];
	char maj[20];
	char sex[20];
	char addr[100];
	char pho[20];
	while (n--) {
		cin >> name >> no >> coll >> maj >> sex >> addr >> pho;
		obj.set(name, no, coll, maj, sex, addr, pho);
		//obj.show();
	}
	return 0;
}