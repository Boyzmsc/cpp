// 문제 : 주어진정수의최대최소구하기
// 제출자 : 문성찬(20171620)

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int testcases;
    cin >> testcases;

    for (int i = 0; i < testcases; i++)
    {
        int caselen;
        cin >> caselen;
        int num[caselen];
        int casenum;

        for (int j = 0; j < caselen; j++)
        {
            cin >> casenum;
            num[j] = casenum;
        }
        sort(num, num + caselen);
        cout << num[caselen - 1] << " " << num[0] << endl;
    }
}