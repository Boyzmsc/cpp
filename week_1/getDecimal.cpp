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
        int result = 1;
        for (int j = 2; j < num; j++)
        {
            if (num % j == 0)
            {
                result = 0;
                break;
            }
        }
        cout << result << endl;
    }
}