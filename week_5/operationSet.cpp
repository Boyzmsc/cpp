#include <iostream>

using namespace std;

int main()
{
    int datacase;
    cin >> datacase;
    for (int i = 0; i < datacase; i++)
    {
        int setlen1;
        cin >> setlen1;
        unsigned int set1[132] = {
            0,
        };
        unsigned int set2[132] = {
            0,
        };

        for (int i = 0; i < setlen1; i++)
        {
            int num;
            cin >> num;
            set1[num] = 1;
        }

        int setlen2;
        cin >> setlen2;
        for (int i = 0; i < setlen2; i++)
        {
            int num;
            cin >> num;
            set2[num] = 1;
        }
        //교집합
        int count = 0;
        for (int i = 0; i < 132; i++)
        {
            if (set1[i] == set2[i] and set1[i] == 1)
            {
                count++;
            }
        }
        cout << count << ' ';
        for (int i = 0; i < 132; i++)
        {
            if (set1[i] == set2[i] and set1[i] == 1)
            {
                cout << i << " ";
            }
        }
        cout << endl;

        //합집합
        count = 0;
        for (int i = 0; i < 132; i++)
        {
            if (set1[i] == 1)
            {
                count++;
            }
            if (set1[i] == 0 and set2[i] == 1)
            {
                count++;
            }
        }
        cout << count << ' ';
        for (int i = 0; i < 132; i++)
        {
            if (set1[i] == 1)
            {
                cout << i << " ";
            }
            if (set1[i] == 0 and set2[i] == 1)
            {
                cout << i << " ";
            }
        }
        cout << endl;

        //차집합
        count = 0;
        for (int i = 0; i < 132; i++)
        {
            if (set1[i] == 1 and set2[i] == 0)
            {
                count++;
            }
        }
        cout << count << ' ';
        for (int i = 0; i < 132; i++)
        {
            if (set1[i] == 1 and set2[i] == 0)
            {
                cout << i << " ";
            }
        }
        cout << endl;
    }
}