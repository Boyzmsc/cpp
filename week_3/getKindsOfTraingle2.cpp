#include <iostream>
#include <math.h>
using namespace std;

double getLength(double x1, double y1, double x2, double y2)
{
    return pow(x1 - x2, 2) + pow(y1 - y2, 2);
}

int assumeTriangle(double af, double bf, double cf)
{
    double max, min, mid;
    double max_d, min_d, mid_d;
    double a = sqrt(af);
    double b = sqrt(bf);
    double c = sqrt(cf);
    if (a > b)
    {
        if (a > c)
        {
            if (b > c)
            {
                max = a;
                max_d = af;
                mid = b;
                mid_d = bf;
                min = c;
                min_d = cf;
            }
            else
            {
                max = a;
                max_d = af;
                mid = c;
                mid_d = cf;
                min = b;
                min_d = bf;
            }
        }
        else
        {
            max = c;
            max_d = cf;
            mid = a;
            mid_d = af;
            min = b;
            min_d = bf;
        }
    }
    else
    {
        if (b > c)
        {
            if (a > c)
            {
                max = b;
                max_d = bf;
                mid = a;
                mid_d = af;
                min = c;
                min_d = cf;
            }
            else
            {
                max = b;
                max_d = bf;
                mid = c;
                mid_d = cf;
                min = a;
                min_d = af;
            }
        }
        else
        {
            max = c;
            max_d = cf;
            mid = b;
            mid_d = bf;
            min = a;
            min_d = af;
        }
    }
    if (max >= min + mid)
    {
        return 0;
    }
    else
    {
        if ((mid_d + min_d) == max_d)
        {
            return 1;
        }
        else if ((mid_d + min_d) < max_d)
        {
            return 2;
        }
        else if ((mid_d + min_d) > max_d)
        {
            return 3;
        }
    }
}

int main()
{
    int datacase;
    cin >> datacase;
    for (int i = 0; i < datacase; i++)
    {
        double ax, ay, bx, by, cx, cy;
        cin >> ax >> ay >> bx >> by >> cx >> cy;
        int result;
        double a, b, c;
        a = getLength(ax, ay, bx, by);
        b = getLength(bx, by, cx, cy);
        c = getLength(cx, cy, ax, ay);
        result = assumeTriangle(a, b, c);
        cout << result << endl;
    }
}