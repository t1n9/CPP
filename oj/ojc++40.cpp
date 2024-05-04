#include <iostream>
#include<string>
using namespace std;

struct Paper {
	int num;
	string a[3];
};

int comp(Paper*p , int t) {
	string temp1, temp2;
	int sum = 0;
	float aver;
	int l;
	//每两张试卷两两对比
	for (int q = 0; q < t-1; q++) {
		for (int w = q + 1; w < t; w++) {
			//两张试卷的每一道题对比
			for (int i = 0; i < 3; i++) {
				sum = 0;
				aver = 0;
				string temp1 = p[q].a[i];
				string temp2 = p[w].a[i];
				l = (temp1.length() > temp2.length()) ? temp2.length() : temp1.length();
				for (int j = 0; j < l; j++) {
					if (temp1[j] == temp2[j]) sum++;
				}
				if (10 * sum / l>=9) {
					cout << p[q].num << ' ' << p[w].num << ' ' << i + 1 << endl;
				}
			}
		}
	}
	//string temp1, temp2;
	//int sum = 0;
	//float aver;
	//for (int i = 0; i < 3; i++) {
	//	string temp1 = p[1].a[i];
	//	string temp2 = p[2].a[i];
	//	for (int j = 0; j < temp1.length(); j++) {
	//		if (temp1[j] == temp2[j]) sum++;
	//	}
	//	aver = sum / temp1.length();
	//	if (aver > 0.90) return i+1;
	//}
	return 0;
}

int main()
{
	int t;
	cin >> t;
	//总共有t个人(t张试卷)
	Paper* p = new Paper[t];
	for (int i = 0; i < t; i++) {
		cin >> p[i].num >> p[i].a[0] >> p[i].a[1] >> p[i].a[2];
	}
	comp(p, t);
	//for (int i = 0; i < t; i++) {
	//	for (int j = i + 1; j < t; j++) {
	//		if (comp(p)) {
	//			cout << p[i].num << ' ' << p[j].num << ' ';
	//		}
	//	}
	//}

}
