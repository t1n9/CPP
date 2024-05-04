#include <iostream>
#include<string.h>
#include<math.h>
using namespace std;

class CDate
{
private:
    int year, month, day;
public:
    CDate() {
        year = 2000; month = 1; day = 1;
    }
    CDate(int y, int m, int d) :year(y), month(m), day(d) {}
    CDate(CDate& d) {
        year = d.year; month = d.month; day = d.day;
    }
    bool check() {//检验日期是否合法
        if (month < 1 || month>12)return 0;
        if (day < 1 || day>31)return 0;
        if (month == 4 || month == 6 || month == 8 || month == 9 || month == 11)
            if (day > 30)return 0;
        if (month == 2) {
            if (!(year % 4)) { if (day > 29)return 0; }
            else { if (day > 28)return 0; }
        }
        return 1;
    }
    int getY() { return year; }
    int getM() { return month; }
    int getD() { return day; }
    void print() {
        cout << year << "年" << month << "月" << day << "日" << " ";
    }
};

int checkNUM[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
char corrCH[11] = { '1','0','X','9','8','7','6','5','4','3','2' };

class CStudentID
{
    string p_id,  p_name; //身份证号码，姓名
    CDate birthday; //出生日期
    int registered; //登记否
public:
    CStudentID(string p_idval, string p_nameval, CDate& day):birthday(day) {
        //构造函数，若:日期非法;日期与id日期不符;id有非法字符;
        // id不是15位或18位;id是18位但检验码不对,
        // 则输出"illegal id"并置registered=0。
        // 否则输出对象的属性并置registered=1.
        p_id = p_idval;
        p_name = p_nameval;
        registered = checked();
    }
    CStudentID(const CStudentID& r) {
        //拷贝构造函数，若r.p_id为15位则升到18位(加年份的19和校验位)
        birthday = r.birthday;
        p_id = r.p_id; p_name = r.p_name;
        p_name = r.p_name;
        p_id.insert(6, "19");
        p_id.push_back(checkN());
        registered = 1;
    }
    int checked() { 
        if (!birthday.check()) return 0;      //非法日期
        int len = p_id.size();
        int y = 0, m = 0, d = 0, i = 0; //日期和id不符
        if (len == 15) {
            for (i = 6; i < 8; i++) y += (pow(10, 7 - i)) * ((int)p_id[i] - 48);
            for (i = 8; i < 10; i++) m += (pow(10, 9 - i)) * ((int)p_id[i] - 48);
            for (i = 10; i < 12; i++)d += (pow(10, 11 - i)) * ((int)p_id[i] - 48);
            if ((birthday.getY() - 1900) != y || birthday.getM() != m || birthday.getD() != d) { return 0; }
        }
        else if (len == 18) {
            for (i = 6; i < 10; i++) y += (pow(10, 9 - i)) * ((int)p_id[i] - 48);
            for (i = 10; i < 12; i++) m += (pow(10, 11 - i)) * ((int)p_id[i] - 48);
            for (i = 12; i < 14; i++)d += (pow(10, 13 - i)) * ((int)p_id[i] - 48);
            if (birthday.getY() != y || birthday.getM() != m || birthday.getD() != d) { return 0; }
            if (checkN() != p_id[17]) return 0;
        }
        else {
            return 0;   //长度不是15，也不是18
        }
        for (int i = 0; i < len; i++)       
            if (p_id[i] > '9' || p_id[i] < '0') return 0;   //有非法字符

        
        return 1;
    }
    char checkN() {     //校验码
        int sum = 0;
        for (int i = 0; i < 17; i++)
            sum += ((int)p_id[i] - 48) * checkNUM[i];
        return corrCH[sum % 11];
    }
    int getReg() { return registered; }
    void print() {
        cout << p_name << ' ';
        birthday.print();
        if(p_id.size() == 15)
            for (int i = 0; i < 15; i++)
                cout << p_id[i];
        else
            for (int i = 0; i < 18; i++)
                cout << p_id[i];
    }
};
int main()
{

    int t;
    cin >> t;
    while (t--) {
        int y, m, d;
        string name;
       string id;
        cin >> y >> m >> d >> name >> id;
        CDate date(y, m, d);
        CStudentID obj(id, name, date);
        if (!obj.getReg()) {        //非法
            cout << name << " illegal id" << endl;
            continue;
        }
        else {
            obj.print();
            cout << endl;
            if (id.size() == 15) {
                CStudentID obj_copy = obj;
                obj_copy.print();
            }
        }
        if (t != 0)cout << endl;
    }
    return 0;
}