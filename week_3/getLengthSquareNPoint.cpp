#include <iostream>
#include <math.h>

using namespace std;

int setEd(int x1, int y1, int x2, int y2)
{
    return pow(x1 - x2, 2) + pow(y1 - y2, 2);
}

int setRd(int x1, int y1, int x2, int y2)
{
    int x, y;
    if (x1 >= x2)
    {
        x = x1 - x2;
    }
    else
    {
        x = x2 - x1;
    }
    if (y1 >= y2)
    {
        y = y1 - y2;
    }
    else
    {
        y = y2 - y1;
    }
    return x + y;
}

int main()
{
    int datacase;
    cin >> datacase;
    for (int i = 0; i < datacase; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int x, y;
        cin >> x >> y;
        int ed, rd;
        if (x > x2)
        {
            if (y > y2)
            {
                ed = setEd(x, y, x2, y2);
                rd = setRd(x, y, x2, y2);
            }
            else if (y < y1)
            {
                ed = setEd(x, y, x2, y1);
                rd = setRd(x, y, x2, y1);
            }
            else
            {
                ed = setEd(x, y, x2, y);
                rd = setRd(x, y, x2, y);
            }
        }
        else if (x < x1)
        {
            if (y > y2)
            {
                ed = setEd(x, y, x1, y2);
                rd = setRd(x, y, x1, y2);
            }
            else if (y < y1)
            {
                ed = setEd(x, y, x1, y1);
                rd = setRd(x, y, x1, y1);
            }
            else
            {
                ed = setEd(x, y, x1, y);
                rd = setRd(x, y, x1, y);
            }
        }
        else
        {
            if (y > y2)
            {
                ed = setEd(x, y, x, y2);
                rd = setRd(x, y, x, y2);
            }
            else if (y < y1)
            {
                ed = setEd(x, y, x, y1);
                rd = setRd(x, y, x, y1);
            }
            else
            {
                ed = 0;
                rd = 0;
            }
        }
        cout << ed << " " << rd << endl;
    }
}