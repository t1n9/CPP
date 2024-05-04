#include <iostream>
#include<cstring>
#include<iomanip>
using namespace std;

class Student {
	char id[10];
	char name[10];
	char birthday[20];
	float score;

public:
	void set(char* i, char* n, char* b, float s) {
		score = s;
		strcpy_s(name, n);
		strcpy_s(id, i);
		strcpy_s(birthday, b);
	}
	char* get_id() {
		return id;
	}
	char* get_name() {
		return name;
	}
	void get_birth() {		//输出格式转换
		char* Y = &birthday[0];
		char* M = &birthday[5];
		char* D = &birthday[8];
		for (int i = 0; i < 4; i++)
			cout << Y[i];
		cout << '_';
		if (M[0] == '0') cout << M[1];
		else cout << M[0] << M[1];
		cout << '_';
		if (D[0] == '0') cout << D[1];
		else cout << D[0] << D[1];
	}
	float get_score() {
		return score;
	}

};

int main()
{
	int n;
	cin >> n;
	Student* s = new Student[n];
	char id[10];
	char name[10];
	char birthday[20];
	float score;
	//写入与覆盖
	for (int i = 0; i < n; i++) {
		cin >> id >> name >> birthday >> score;
		s[i].set(id, name, birthday, score);
		for (int j = i-1; j >= 0; j--) {
			if (!strcmp(s[i].get_id(), s[j].get_id())) {
				s[j] = s[i];
				i--;
				n--;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << "id:" << s[i].get_id() << " name:" << s[i].get_name() << " birthday:";
		s[i].get_birth() ;
		cout << " score:" << fixed << setprecision(1) << s[i].get_score() << endl;
	}


}
