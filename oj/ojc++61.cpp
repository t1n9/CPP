#include <iostream>
using namespace std;

struct Team {
    int num;
    int score;
};

int main()
{
    int N;
    cin >> N;
    Team* t = new Team[N];
    for (int i = 0; i < N; i++) {
        cin >> t[i].num >> t[i].score;
    }
    for (int i = 0; i < N - 1; i++) {
        Team temp;
        temp = t[i];
        int sub = 0;
        for (int j = i + 1; j < N; j++) {
            if (t[j].score> temp.score) {
                sub = j;
                temp = t[j];
            }
        }
        for (int k = sub; k > i ; k--) {
            t[k] = t[k - 1];
        }
        t[i] = temp;
    }

    //for (int i = 0; i < N - 1; i++) {
    //    for (int j = i+1; j <N; j++) {
    //        if (t[i].score < t[j].score)
    //            swap(t[i], t[j]);
    //    }
    //}

    for (int i = 0; i < N; i++) {
        cout << t[i].num << ' ' << t[i].score << endl;
    }
}