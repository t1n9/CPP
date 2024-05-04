
#include <iostream>
#include<cstring>
using namespace std;

class Employee {
	char name[20];
	char no[10];
	char department[20];
	char position[20];
	char sex[10];
	char pho[20];
public:
	void set(char* na, char* n, char* d, char* po, char* s, char* p) {
		strcpy_s(name, na);
		strcpy_s(no, n);
		strcpy_s(department, d);
		strcpy_s(position, po);
		strcpy_s(sex, s);
		strcpy_s(pho, p);
	}
	void get() {
		cout << name << ' ' << no << ' ' << department << ' ' << position << ' ' << sex << ' ' << pho << endl;
	}


};

int main()
{
	int n;
	cin >> n;
	while (n--) {
		char name[20];
		char no[10];
		char department[20];
		char position[20];
		char sex[10];
		char pho[20];
		cin >> name >> no >> department >> position >> sex >> pho;
		Employee obj;
		obj.set(name, no, department, position, sex, pho);
		obj.get();
	}
	return 0;
}
