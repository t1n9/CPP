#include <iostream>
using namespace std;

class Account {
	static int count;
	static float InterestRate;
	string _accno, _accname;
	float _balance;
public:
	friend void Update(Account& a);
	Account(string accno, string name, float balance) :_accno(accno), _accname(name), _balance(balance) {}
	
	void sace(float in) { _balance += in; }
	void withdraw(float out) { _balance -= out; }
	float getBalance() { return _balance; }

};

float Account::InterestRate = 0.01;
int Account::count;
void Update(Account& a) {
	a._balance *= (1 + a.InterestRate);
}



int main()
{
	float rate;
	cin >> rate;
	int n;
	cin >> n;
	float sum = 0;
	while (n--) {
		string no, name;
		float balance, in, out;
		cin >> no >> name >> balance >> in >> out;
		Account obj(no, name, balance);
		cout << no << " " << name << " ";
		obj.sace(in);
		cout << obj.getBalance() << " ";
		Update(obj);
		cout << obj.getBalance() << " ";
		obj.withdraw(out);
		cout << obj.getBalance() << endl;
		sum += obj.getBalance();
	}
	cout << sum;
}