#include <iostream>
#include <string>
using namespace std;

class STR {
    char* s;
public:
    STR(char* t) :s(t) {}
    ~STR() {}
    void backward(char* t1, char* t2) {
        while (t1 < t2) {
            char temp = *t1;
            *t1 = *t2;
            *t2 = temp;
            t1++;
            t2--;
        }
    }

    void fun(int len) {
        int head = 0;
        int tail = 0;
        while (tail <= len) {
            if((s[tail] >= 'A' && s[tail] <= 'Z') || (s[tail] >= 'a' && s[tail] <= 'z')) {
                tail++;
                continue;
            }
            else {
                if (head+1 != tail)
                    backward(&s[head], &s[tail-1]);
                tail++;
                head = tail;
            }
        }
        

    }

    void print(int len) {
        for (int i = 0; i < len; i++)
            cout << s[i];
    }
};

int main()
{
    string S;

    getline(cin, S);
    char* str = new char[S.length()];
    str = &S[0];
    STR s(str);
    s.fun(S.length());
    s.print(S.length());
}