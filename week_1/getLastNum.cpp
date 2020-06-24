#include <iostream>

using namespace std;

int firstnum(int num)
{
    int k = 1;
    while ((num / k) > 0)
    {
        k *= 10;
    }
    k = k / 10;

    while (k >= 10)
    {
        num = num % k;
        k /= 10;
    }
    return num;
}

int main()
{
    int datacase;
    cin >> datacase;
    for (int i = 0; i < datacase; i++)
    {
        int casenum;
        cin >> casenum;
        int result = 1;
        int num;
        for (int j = 0; j < casenum; j++)
        {
            cin >> num;
            firstnum(num);
            result *= firstnum(num);
            result = firstnum(result);
        }
        cout << result << endl;
    }
    return 0;
}
