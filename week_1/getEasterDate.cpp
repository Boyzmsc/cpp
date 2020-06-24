// 문제 : 부활절 날짜 계산
// 제출자 : 문성찬(20171620)

#include <iostream>

using namespace std;

int main()
{
    int testcases;
    cin >> testcases;

    for (int x = 0; x < testcases; x++)
    {
        int year;
        cin >> year;
        int c = year / 100;
        int n = year - (year / 19) * 19;
        int t = (c - 17) / 25;
        int c1 = c - (c / 4) - ((c - t) / 3);
        int n1 = n * 19 + 15;
        int i = c1 + n1;
        int j = i - (i / 30) * 30;
        int j9 = j / 28;
        int j10 = 1 - j9;
        int j11 = 29 / (j + 1);
        int j12 = (21 - n) / 11;
        int k = j - (j9 * j10 * j11 * j12);
        int l = year + (year / 4) + j + 2 - c + (c / 4);
        int p = l - (l / 7) * 7;
        int q = k - p;
        int month = ((q + 40) / 44) + 3;
        int day = (q + 28) - ((month / 4) * 31);
        cout << month << " " << day << endl;
    }
}