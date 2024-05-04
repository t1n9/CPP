#include <iostream>
#include<string>

using namespace std;

struct Student {
    string number;
    string name;
    int a1;
    int a2;
    int a3;
    int sum;
};

int main()
{
    int t;
    cin >> t;
    Student* p = new Student[t];
    for (int i = 0; i < t; i++) {
        cin >> p[i].number >> p[i].name >> p[i].a1 >> p[i].a2 >> p[i].a3;
        p[i].sum = p[i].a1 + p[i].a2 + p[i].a3;
    }
    int max = 0;
    int num_best = 0;
    for (int i = 0; i < t; i++) {
        if (p[i].sum > max) {
            max = p[i].sum;
            num_best = i;
        }
    }
    cout << p[num_best].name << ' ' << p[num_best].number << ' ' << p[num_best].sum;
    return 0;
}