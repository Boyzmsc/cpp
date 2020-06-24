#include <iostream>

using namespace std;

int main()
{
    int datacase;
    cin >> datacase;
    for (int i = 0; i < datacase; i++)
    {
        int numlen;
        cin >> numlen;
        int factor[numlen];
        for (int i = 0; i < numlen; i++)
        {
            int num;
            cin >> num;
            factor[i] = num;
        }
        int k;
        cin >> k;
        cout << numlen - k + 1 << " ";
        for (int i = 0; i < numlen - k + 1; i++)
        {
            int averageNum = 0;
            for (int j = i; j < k + i; j++)
            {
                averageNum += factor[j];
            }
            averageNum /= k;
            cout << averageNum << " ";
        }
        cout << endl;
    }
}