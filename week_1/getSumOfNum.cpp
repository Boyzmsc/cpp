// 문제 : 주어진 정수의 합 구하기
// 제출자 : 문성찬(20171620)

#include <iostream>

using namespace std;

int main()
{
    int testcases;
    cin >> testcases;

    for (int i = 0; i < testcases; i++)
    {
        int caselen;
        cin >> caselen;
        int casenum;
        int result = 0;

        for (int j = 0; j < caselen; j++)
        {
            cin >> casenum;
            result += casenum;
        }
        cout << result << endl;
    }
}