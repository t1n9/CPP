#include <iostream>
#include <cstring>
using namespace std;

class Cat {
    char name[20];
    int weight;

public:
    int get_w() {
        return weight;
    }
    char* get_n() {
        return name;
    }
    void set(char* n,int w) {
        strcpy_s(name, n);
        weight = w;
    }
};





int main()
{
    int n;
    cin >> n;
    Cat* c = new Cat[n];
    char p[20];
    int w;
    for (int i = 0; i < n; i++) {
        cin >> p >> w;
        c[i].set(p, w);
    }


    for (int i = 0; i < n-1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (c[i].get_w() > c[j].get_w()) {
                swap(c[i], c[j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << c[i].get_n() << ' ';
    }

    cout << endl;
    return 0;
}
