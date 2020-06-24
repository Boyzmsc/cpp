#include <iostream>

using namespace std;

int main()
{
    int datacase;
    cin >> datacase;
    for (int i = 0; i < datacase; i++)
    {
        int rowlen;
        int columnlen;
        cin >> rowlen >> columnlen;
        int matrix1[rowlen][columnlen];
        int matrix2[rowlen][columnlen];
        int result[rowlen][columnlen];
        ;
        for (int i = 0; i < rowlen; i++)
        {
            for (int j = 0; j < columnlen; j++)
            {
                int num;
                cin >> num;
                matrix1[i][j] = num;
            }
        }
        for (int i = 0; i < rowlen; i++)
        {
            for (int j = 0; j < columnlen; j++)
            {
                int num;
                cin >> num;
                matrix2[i][j] = num;
            }
        }
        for (int i = 0; i < rowlen; i++)
        {
            for (int j = 0; j < columnlen; j++)
            {
                result[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }

        for (int i = 0; i < rowlen; i++)
        {
            for (int j = 0; j < columnlen; j++)
            {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }
}