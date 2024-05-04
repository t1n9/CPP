#include <iostream>
using namespace std;

class CPoint {
    int x, y, z;
public:
    CPoint() :x(0), y(0), z(0) {}
    CPoint(int _x, int _y, int _z) :x(_x), y(_y), z(_z) {}
    ~CPoint() {}
    void setX(int _x) { x = _x; }
    void setY(int _y) { y = _y; }
    void setZ(int _z) { z = _z; }
    void setXYZ(int _x, int _y, int _z) { x = _x; y = _y; z = _z; }
    int getX() { return x; }
    int getY() { return y; }
    int getZ() { return z; }
};

class CCube {
    CPoint* point;
public:
    CCube(int x1,int y1,int z1,int x2,int y2,int z2){
        int temp;
        if (x1 > x2) {
            temp = x1; x1 = x2; x2 = temp;
        }
        if (y1 > y2) {
            temp = y1; y1 = y2; y2 = temp;
        }
        if (z1 > z2) {
            temp = z1; z1 = z2; z2 = temp;
        }
        point = new CPoint[2];
        point[0].setXYZ(x1, y1, z1);        //靠近O点
        point[1].setXYZ(x2, y2, z2);        //远离O点
    }
    int collide(CCube r) {
        if (point[0].getX() <= r.point[1].getX()&&
            point[0].getY() <= r.point[1].getY()&&
            point[0].getZ() <= r.point[1].getZ()
            ) {
            return 1;
        }
        else {
            return 0;
        }

    }
};



int main()
{
    int t;
    cin >> t;
    while (t--) {
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        CCube c1(x1, y1, z1, x2, y2, z2);
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        CCube c2(x1, y1, z1, x2, y2, z2);
        if (!c1.collide(c2))cout << "have distance" << endl;
        else cout << "collide" << endl;
    }
}
