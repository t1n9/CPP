
#include <iostream>
using namespace std;
class Bulk {
    int length;
    int width;
    int height;
public:
    Bulk(int l, int w, int h) {
        length = l;
        width = w;
        height = h;
    }
    int volume() {
        return length * width * height;
    }
    int areas() {
        return 2 * (length * width + length * height + width * height);
    }
};


int main()
{
    int l; int w; int h;
    cin >> l >> w >> h;
    Bulk obj(l, w, h);
    cout << obj.volume() << endl << obj.areas();

}
