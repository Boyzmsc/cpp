#include <iostream>

using namespace std;

int main()
{
    int datacase;
    cin >> datacase;
    for (int i = 0; i < datacase; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int result;
        if (c >= (a + b))
        {
            result = 0;
        }
        else if (a == b and b == c)
        {
            result = 1;
        }
        else if (a * a + b * b == c * c)
        {
            result = 2;
        }
        else if (a == b or b == c or a == c)
        {
            result = 3;
        }
        else
        {
            result = 4;
        }
        cout << result << endl;
    }
}