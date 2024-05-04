#include <iostream>
#include<string>
using namespace std;

struct Student {
    string name;
    int age;
    int score;
};

int main()
{
    int N;
    cin >> N;
    Student* s = new Student[N];
    for (int i = 0; i < N; i++) {
        cin >> s[i].name >> s[i].age >> s[i].score;
    }
    Student temp;
    for (int i = 0; i < N - 1; i++) {
        for (int j = N - 1; j > i; j--) {
            if (s[i].score > s[j].score) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
            else if (s[i].score == s[j].score) {
                if (s[i].name[0] > s[j].name[0]) {
                    temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                }
                else if (s[i].name[0] == s[j].name[0]) {
                    if (s[i].age > s[j].age) {
                        temp = s[i];
                        s[i] = s[j];
                        s[j] = temp;
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << s[i].name <<' '<< s[i].age <<' '<< s[i].score << endl;
    }


}