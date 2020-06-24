#include <iostream>

using namespace std;

void printclock(int k)
{
    for (int i = 0; i < k; i++)
    {
        if (i % 2 == 0)
        {
            cout << "*";
        }
        else
        {
            cout << "+";
        }
    }
}

void printloop(int q)
{
    for (int i = 0; i < q; i++)
    {
        cout << "-";
    }
}

int main()
{
    int testcase;
    cin >> testcase;
    for (int i = 0; i < testcase; i++)
    {
        int num;
        cin >> num;
        for (int j = 0; j < num / 2; j++)
        {
            int c = num - 1 - j;
            int minus = num - 1 - c;
            int clock = num - (minus * 2);
            printloop(minus);
            printclock(clock);
            printloop(minus);
            cout << endl;
        }
        printloop(num / 2);
        cout << "*";
        printloop(num / 2);
        cout << endl;

        for (int k = (num / 2 + 1); k < num; k++)
        {
            int minus = num - 1 - k;
            int clock = num - (minus * 2);
            printloop(minus);
            printclock(clock);
            printloop(minus);
            cout << endl;
        }
    }
}