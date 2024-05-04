#include <iostream>
#include<string.h>
#include<string>
using namespace std;

class STR {
    char* s;
    void backward(char* t1, char* t2) {
        char temp;
        while (t1 < t2) {
            temp = *t1;
            *t1 = *t2;
            *t2 = temp;
            t1++; t2--;
        }
    }

public:
    STR(char* t) :s(t) {
        cout << "constructing..." << endl;
    }
    STR(const STR& obj) {
        s = new char[strlen(obj.s)];
        strcpy(s, obj.s);
        cout << "copy constructing..." << endl;
    }
    ~STR() {
        cout << "delete space..." << endl;
    }

    void fun() {
        int len = strlen(s);
        int head = 0; int tail = 0;
        int i = 0; int j = 1;
        while (j < len + 1) {
            if (s[j] == ' ' || s[j] == '\0') {
                if (i + 1 != j)
                    backward(&s[i], &s[j - 1]);
                i = j + 1;
                j = i + 1;
            }
            else {
                j++;
            }
        }

    }

    void print() {
        for (int i = 0; i < strlen(s); i++)
            cout << s[i];
    }
};


int main()
{
    string s;
    getline(cin, s);
    STR obj(&s[0]);
    STR objcopy = obj;
    objcopy.fun();
    obj.print();
    cout << " can be tranformed to ";
    objcopy.print();
    cout << endl;
}