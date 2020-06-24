#include <iostream>

using namespace std;

int getSingendArea(int x1, int x2, int y1, int y2)
{
    return (x1 + x2) * (y2 - y1);
}

int main()
{
    int datacase;
    cin >> datacase;
    for (int i = 0; i < datacase; i++)
    {
        int edgenum;
        cin >> edgenum;
        int x[edgenum];
        int y[edgenum];
        int result = 0;
        int clock = 0;
        for (int j = 0; j < edgenum; j++)
        {
            cin >> x[j];
            cin >> y[j];
        }

        for (int k = 0; k < edgenum - 1; k++)
        {
            result += getSingendArea(x[k], x[k + 1], y[k], y[k + 1]);
        }
        result += getSingendArea(x[edgenum - 1], x[0], y[edgenum - 1], y[0]);

        if (result < 0)
        {
            clock = -1;
            result *= -1;
        }
        else
        {
            clock = 1;
        }

        cout << result << " " << clock << endl;
    }
}