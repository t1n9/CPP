#include <iostream>
using namespace std;

class Tree {
	int ages;
public:
	Tree() :ages(1) {}
	Tree(int a) :ages(a) {}
	void grow(int years) { ages += years; }
	void age() { cout << ages << endl; }
};

int main()
{
	int t1, y, t2;
	cin >> t1;
	Tree tree1;
	tree1.grow(t1);
	tree1.age();

	cin >> y >> t2;
	Tree tree2(y);
	tree2.grow(t2);
	tree2.age();
	return 0;
}
