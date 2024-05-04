
#include <iostream>
#include<string>
using namespace std;

int comp(char* S, char* T,int len) {
	int max = 0;
	int min = 0;
	for (int i = 0; i < len; i++) {
		if (S[i] > T[i]) max++;
		else if (S[i] < T[i])min++;
		else;
	}
	if (max > min) return 1;
	else if (max < min) return -1;
	else return 0;

}


int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string s, t;
		cin >> s >> t;
		char* S = &s[0];
		char* T = &t[0];
		int lenS = s.length();
		int lenT = t.length();

		
		if (lenS > lenT) { 
			cout << 1 << endl; 
		}
		else if (lenT  > lenS) {
			cout << -1 << endl;
		}
		else {
			cout << comp(S, T, lenT) << endl;
		}


	}

}
