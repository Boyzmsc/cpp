// 문제 : 두정수사이의모든정수의합구하기
// 제출자 : 문성찬(20171620)

#include <iostream>

using namespace std;

int main()
{
    int testcases;
    cin >> testcases;

    for (int i = 0; i < testcases; i++)
    {
        int result = 0;
        int firstnum;
        int lastnum;
        cin >> firstnum >> lastnum;
        for (int j = firstnum; j <= lastnum; j++)
        {
            result += j;
        }
        cout << result << endl;
    }
}