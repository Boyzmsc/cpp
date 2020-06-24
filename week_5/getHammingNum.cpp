#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int datacase;
    cin >> datacase;
    for (int i = 0; i < datacase; i++)
    {
        int indexnum;
        cin >> indexnum;
        int count = 1;
        vector<int> hamming;
        hamming.push_back(1);
        int min;
        int max;
        while (hamming.size() <= indexnum)
        {
            min = hamming.back() * 5;
            max = hamming.back();
            for (int i = 0; i < hamming.size(); i++)
            {
                if (hamming[i] * 2 < min and hamming[i] * 2 > max)
                {
                    min = hamming[i] * 2;
                }
                if (hamming[i] * 3 < min and hamming[i] * 3 > max)
                {
                    min = hamming[i] * 3;
                }
                if (hamming[i] * 5 < min and hamming[i] * 5 > max)
                {
                    min = hamming[i] * 5;
                }
            }
            hamming.push_back(min);
        }

        cout << hamming[indexnum - 1] << endl;
    }
}