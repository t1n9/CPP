#include <iostream>
#include<cstring>
using namespace std;

class CAccount {
    long account;
    char name[10];
    float balance;

public:
    CAccount(long a, char* n, float b) {
        account = a;
        strcpy_s(name, n);
        balance = b;
        check();
    }
    void deposit(long in) {
        balance += in;
        cout << "saving ok!" << endl;
        check();
    }
    void withdraw(long out) {
        if (out > balance)
            cout << "sorry! over limit!" << endl;
        else {
            balance -= out;
            cout << "withdraw ok!" << endl;
        }
        check();
    }
    void check() {
        cout << name << "'s balance is " << balance << endl;
    }
};

int main()
{
    int t = 2;
    while (t--) {
        long account;
        char name[10];
        float balance;
        cin >> account >> name >> balance;
        CAccount obj(account, name, balance);
        long in, out;
        cin >> in >> out;
        obj.deposit(in);
        obj.withdraw(out);
    }
}