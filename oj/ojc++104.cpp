#include <iostream>
#include<cstring>
#include<iomanip>
using namespace std;


class Human {
private:
	char name[20];
	float height;
	float weight;
	float wline;

public:
	Human(char* n, float h, float we, float wl) {
		strcpy_s(name, n);
		height = h; weight = we; wline = wl;
	}
	int BMI() {
		int temp = weight * 10 / (height * height);
		if (temp %10>= 5) {
			return (int)(weight / (height * height)) + 1;
		}
		else {
			return (int)(weight / (height * height));
		}
	}
	float BFR() {
		return (wline * 0.74 - weight * 0.082 - 34.89) / weight;
	}

	void show() {
		cout << name << "'s BMI: " << BMI() << "--BFR: ";
		cout << fixed << setprecision(2) << BFR() << endl;
	}
};

int main()
{
	int t;
	cin >> t;
	while (t--) {
		char name[20];
		float height;
		float weight;
		float wline;
		cin >> name >> height >> weight >> wline;
		Human obj(name, height, weight, wline);
		obj.show();
	}
	return 0;
}
