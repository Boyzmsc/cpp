#include <iostream>
#include <math.h>

using namespace std;

int setSignedArea(int ax, int ay, int bx, int by, int cx, int cy)
{
    return ((bx - ax) * (cy - ay)) - ((cx - ax) * (by - ay));
}

int main()
{
    int datacase;
    cin >> datacase;
    for (int i = 0; i < datacase; i++)
    {
        int ax, ay, bx, by, cx, cy;
        cin >> ax >> ay >> bx >> by >> cx >> cy;
        int result;
        result = setSignedArea(ax, ay, bx, by, cx, cy);
        if (result > 0)
        {
            cout << result << " "
                 << "1" << endl;
        }
        else if (result < 0)
        {
            cout << -result << " "
                 << "-1" << endl;
        }
        else
        {
            cout << result << " "
                 << "0" << endl;
        }
    }
}