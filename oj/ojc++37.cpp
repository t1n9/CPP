#include <iostream>
#include<string>
using namespace std;


int main()
{
	int t;
	cin >> t;
	for (int o = 0; o < t; o++) {
		string ming, key;
		cin >> ming >> key;
		int len_key = key.length();
		int len_ming = ming.length();

		char* p = &ming[0];
		char* q = &key[0];
		char* s = new char[len_ming];

		for (int i = 0; i<len_ming; i++) {
			if (ming[i] >= 'a' && ming[i] <= 'z') {
				s[i] = char(((ming[i] + int(key[i % len_key]) - '0') - 'a') % 26 + 'a');
			}
			else {
				s[i] = char(((ming[i] + int(key[i % len_key]) - '0') - 'A') % 26 + 'A');
			}



		}

		for(int i = 0;i<len_ming;i++){
			cout << s[i];
		}
		cout << endl;
	}
}
