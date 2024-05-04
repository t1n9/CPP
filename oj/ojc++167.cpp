#include <iostream>
using namespace std;

class Time {
    int hour, minute, second;
public:
    friend int diff(Time& t1, Time& t2);
    Time(int h, int m, int s) :hour(h), minute(m), second(s) {}




};

int diff(Time& t1, Time& t2) {
    int diff_h = t1.hour - t2.hour;
    if (diff_h < 0) diff_h = -diff_h;
    int diff_m = t1.minute - t2.minute;
    if (diff_m < 0)diff_m = -diff_m;
    int diff_s = t1.second - t2.second;
    if (diff_s < 0) diff_s = -diff_s;

    return 3600 * diff_h + 60 * diff_m + diff_s;

}



int main()
{
    int n;
    cin >> n;
    while (n--) {
        int h1, m1, s1, h2, m2, s2;
        cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
        Time t1(h1, m1, s1), t2(h2, m2, s2);
        cout << h1 << "时" << m1 << "分" << s1 << "秒--" <<
            h2 << "时" << m2 << "分" << s2 << "秒时间差为" <<
            diff(t1, t2) << "秒" << endl;
    }


}
