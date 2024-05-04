#include <iostream>
using namespace std;

class Student {
private:
	int id;//学号
	int score; //成绩
	static int  maxscore;//最高分数
	static int maxid;//最高分数学生学号
public:
	Student(int ti = 0, int ts = 0)	:id(ti), score(ts){}
	void set(int ti, int ts) { id = ti; score = ts; }
	static void findMax(Student& st); //寻找最高成绩和学号
	static int getMaxScore(); //返回最高成绩
	static int getMaxID();//返回最高成绩的学号
};

int Student::maxid = 0;
int Student::maxscore = 0;
Student Max;

void Student::findMax(Student& st) {
	if (st.score > maxscore) {
		maxscore = st.score;
		maxid = st.id;
	}
}
int Student::getMaxID() { return maxid; }
int Student::getMaxScore() { return maxscore; }

int main()
{
	int n;
	cin >> n;
	Student* obj = new Student[n];
	Student max(0, 0);
	int id, score;
	for (int i = 0; i < n; i++) {
		cin >> id >> score;
		obj[i].set(id, score);
	}
	for (int i = 0; i < n; i++)
		Max.findMax(obj[i]);
	cout << Max.getMaxID() << "--" << Max.getMaxScore() << endl;
}
