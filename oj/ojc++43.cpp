#include <iostream>
#include<string>
using namespace std;

struct pos {
	string Name;
	string Terminal;
	string Operator;
	string CardIss;
	string Validity;
	string CardNum;
	string Traded;
	string Costs;
};


int main()
{
	int t;
	cin >> t;
	for (int o = 0; o < t; o++) {
		pos p;
		cin >> p.Name >> p.Terminal >> p.Operator >> p.CardIss >> p.Validity >> p.CardNum >> p.Traded >> p.Costs;
		cout << "Name: " << p.Name << endl;
		cout << "Terminal: " << p.Terminal << " operator: " << p.Operator << endl;
		cout << "Card Issuers: " << p.CardIss << " Validity: " << p.Validity << endl;
		cout << "CardNumber: ";
		for (int i = 0; i < 4; i++) cout << p.CardNum[i];
		cout << "********";
		for (int i = 12; i < 16; i++) cout << p.CardNum[i];
		cout << endl << "Traded: " << p.Traded << endl;
		cout << "Costs: $" << p.Costs << endl;
		cout << endl;
	}
	return 0;
}
