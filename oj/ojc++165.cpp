#include <iostream>
#include<string.h>
using namespace std;



class Customer {
	static int TotalCustomerNum;
	static int Rent;
	static int Year;
	int CustID;
	char* CustName;
public:
	Customer() :CustName(new char[2]) {}
	Customer(char* name) {
		CustName = name;

	}
	~Customer() {}
	static void changerYear(int r);
	void Display(Customer &a) {
		a.TotalCustomerNum++;
		CustID = a.TotalCustomerNum + 1;
		cout << CustName << " " << a.Year << "000" << a.TotalCustomerNum << " " << a.TotalCustomerNum << " " << 150 * a.TotalCustomerNum << endl;
	}

};

int Customer::TotalCustomerNum = 0;
int Customer::Rent = 150;
int Customer::Year = 2014;

Customer ALL;
void Customer::changerYear(int r) { Year = r; }




int main()
{
	int t;
	cin >> t;
	while (t--) {
		int year;
		cin >> year;
		ALL.changerYear(year);
		char* name = new char[10];
		cin >> name;
		while (strcmp(name,"0")) {
			Customer obj(&name[0]);
			obj.Display(ALL);
			cin >> name;
		}

	}

}
