#include <iostream>
using namespace std;

class Matrix {
    int x, y;
    int** mat;
public:
    Matrix(int a, int b,int **m){
        x = a; y = b;
        mat = new int* [x];
        for (int i = 0; i < x; i++)
            mat[i] = new int[y];
        for (int i = 0; i < x; i++)
            for (int j = 0; j < y; j++)
                mat[i][j] = m[i][j];
    }
    Matrix(const Matrix& obj) {
        x = obj.y; y = obj.x;
        mat = new int* [x];
        for (int i = 0; i < x; i++)
            mat[i] = new int[y];
         
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                mat[x - 1 - j][i] = obj.mat[y - 1 - i][x - 1 - j];
            }
        }

    }

    void print() {
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                cout << mat[i][j];
                if (j != y - 1)
                    cout << ' ';
            }
            cout << endl;
        }
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        int** m = new int* [x];
        for (int i = 0; i < x; i++)
            m[i] = new int[y];

        for (int i = 0; i < x; i++)
            for (int j = 0; j < y; j++)
                cin >> m[i][j];

        Matrix obj1(x, y, m);
        Matrix obj2 = obj1;
        cout << "before:" << endl;
        obj1.print();
        cout << "after:" << endl;
        obj2.print();
        cout << endl;
    }

}
