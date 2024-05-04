#include <iostream>
#include <cstring>
#include<string>
using namespace std;

class Rant {
private:
    int type;
    char name[20];
    int price;
    int state;
    string t1[4] = { "BF","CD","VCD","DVD" };
public:
    //构造函数初始化
    Rant(int t,char* n,int p,int s) {
        type = t;
        strcpy(name, n);
        price = p;
        state = s;
    }
    void print(int d) {
        //state = 1 未出租
        if (state) {
            cout << t1[type-1] << '[' << name << "]rented" << endl;
        }
        else {
            cout << t1[type-1] << '[' << name << "]not rented" << endl;
        }
        if (d) {
            if (state)
                cout << "Rental: " << fee(d) << endl;
            else
                cout << "No rental" << endl;
        }
    }
    
    int fee(int d) {
        return d * price;
    }

};

int main()
{
    int n;
    cin >> n;
    while (n--) {
        int type;
        char name[20];
        int price;
        int state;
        cin >> type >> name >> price >> state;
        Rant obj(type, name, price, state);
        int d;
        cin >> d;
        obj.print(d);
    }
    return 0;
}
