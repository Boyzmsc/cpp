#include <iostream>

using namespace std;

int main()
{
    int testcases;
    cin >> testcases;

    for (int i = 0; i < testcases; i++)
    {
        int r;
        int s;
        int t;
        cin >> r >> s >> t;
        int matrix1[r][s];
        int matrix2[s][t];
        int result[r][t];

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < s; j++)
            {
                int num;
                cin >> num;
                matrix1[i][j] = num;
            }
        }
        for (int i = 0; i < s; i++)
        {
            for (int j = 0; j < t; j++)
            {
                int num;
                cin >> num;
                matrix2[i][j] = num;
            }
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < t; j++)
            {
                int sum = 0;
                for (int k = 0; k < s; k++)
                {
                    int n = matrix1[i][k] * matrix2[k][j];
                    sum += n;
                }
                result[i][j] = sum;
            }
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < t; j++)
            {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }
}