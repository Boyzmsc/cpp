#include <iostream>

using namespace std;

void printline(int k, int num)
{
    for (int i = 0; i < num; i++)
    {
        if (i == (num / 2))
        {
            cout << "I";
        }
        else if (i == num - k - 1)
        {
            cout << "*";
        }
        else
        {
            cout << ".";
        }
    }
}

void printloop(int q)
{
    for (int i = 0; i < q; i++)
    {
        cout << "+";
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
            printline(j, num);
            cout << endl;
        }
        printloop(num / 2);
        cout << "O";
        printloop(num / 2);
        cout << endl;

        for (int k = (num / 2 + 1); k < num; k++)
        {
            printline(k, num);
            cout << endl;
        }
    }
}