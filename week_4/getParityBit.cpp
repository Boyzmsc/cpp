#include <iostream>

using namespace std;

int main()
{
    int datacase;
    cin >> datacase;
    for (int i = 0; i < datacase; i++)
    {
        int num;
        cin >> num;
        int count = 0;
        int temp = num;
        long result = 0;
        while (temp > 1)
        {
            if (temp % 2 == 1)
            {
                count++;
            }
            temp /= 2;
        }
        if (temp == 1)
        {
            count++;
        }

        if (count % 2 == 1)
        {
            result = num + 2147483648;
        }
        else
        {
            result = num;
        }

        cout << result << endl;
    }
}