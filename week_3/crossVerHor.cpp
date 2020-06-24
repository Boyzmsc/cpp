#include <iostream>

using namespace std;

int sortHigh(int x1, int x2)
{
    int max;
    if (x1 > x2)
    {
        max = x1;
    }
    else
    {
        max = x2;
    }
    return max;
}
int sortLow(int x1, int x2)
{
    int min;
    if (x1 > x2)
    {
        min = x2;
    }
    else
    {
        min = x1;
    }
    return min;
}
int main()
{
    int datacase;
    cin >> datacase;
    for (int i = 0; i < datacase; i++)
    {
        int x1, y1, x2, y2;
        int k1, q1, k2, q2;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> k1 >> q1 >> k2 >> q2;
        int result;
        int xh, yh, xl, yl;
        int kh, qh, kl, ql;
        xh = sortHigh(x1, x2);
        xl = sortLow(x1, x2);

        yh = sortHigh(y1, y2);
        yl = sortLow(y1, y2);

        kh = sortHigh(k1, k2);
        kl = sortLow(k1, k2);

        qh = sortHigh(q1, q2);
        ql = sortLow(q1, q2);

        if (xh == xl)
        {
            if (((qh >= yl and qh <= yh) and kh == xh) or ((qh >= yl and qh <= yh) and kl == xh) or ((kh >= xh and kl <= xh) and qh == yh) or ((kh >= xh and kl <= xh) and qh == yl))
            {
                result = 2;
            }
            else if (kh > xh and kl < xh and qh > yl and qh < yh)
            {
                result = 1;
            }
            else
            {
                result = 0;
            }
        }
        else
        {
            if (((yh >= ql and yh <= qh) and kh == xh) or ((yh >= ql and yh <= qh) and kh == xl) or ((xh >= kh and xl <= kh) and qh == yh) or ((xh >= kh and xl <= kh) and ql == yh))
            {
                result = 2;
            }
            else if (kh < xh and kh > xl and qh > yh and ql < yh)
            {
                result = 1;
            }
            else
            {
                result = 0;
            }
        }
        cout << result << endl;
    }
}