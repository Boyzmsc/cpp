#include <iostream>

using namespace std;

int main()
{
    int testcase;
    cin >> testcase;
    for (int i = 0; i < testcase; i++)
    {
        int num;
        cin >> num;
        for (int j = 1; j <= num; j++)
        {
            int m = num - 1;
            int v = j;
            int t = j - 1;
            while (t >= 0)
            {
                cout << v << " ";
                v += m;
                m -= 1;
                t -= 1;
            }
            cout << endl;
        }
    }
}