#include <iostream>
#include <string>
using namespace std;

struct Birth {
    int Y;
    int M;
    int D;
};

int main()
{
    int t;
    cin >> t;
    Birth* b = new Birth[t];

    for (int i = 0; i < t; i++) {
        cin >> b[i].Y >> b[i].M >> b[i].D;
    }

    for (int i = 0; i < t - 1; i++) {
        for (int j = t - 1; j > i; j--) {
            if (b[i].Y > b[j].Y) {
                swap(b[i], b[j]);
            }
            else if (b[i].Y == b[j].Y) {
                if (b[i].M > b[j].M) {
                    swap(b[i], b[j]);
                }
                else if (b[i].M == b[j].M) {
                    if (b[i].D > b[j].D) {
                        swap(b[i], b[j]);
                    }
                }
            }
        }
    }


    for (int i = 0; i < t; i++) {
        cout << i + 1 << ':' << b[i].Y << '-' << b[i].M << '-' << b[i].D << endl;
    }

}
