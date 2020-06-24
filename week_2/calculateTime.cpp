#include <iostream>

using namespace std;

int main()
{
    int testcase;
    cin >> testcase;
    for (int i = 0; i < testcase; i++)
    {
        int casenum;
        cin >> casenum;
        int day = 0;
        int hour = 0;
        int minute = 0;
        int second = 0;
        int starttime = 0;
        int endtime = 0;
        int difftime = 0;
        for (int j = 0; j < casenum; j++)
        {
            int bh, bm, bs, ah, am, as;
            cin >> bh;
            cin >> bm;
            cin >> bs;
            cin >> ah;
            cin >> am;
            cin >> as;

            starttime = bh * 60 * 60 + bm * 60 + bs;
            endtime = ah * 60 * 60 + am * 60 + as;
            difftime += endtime - starttime;
        }

        day = difftime / (60 * 60 * 24);
        difftime %= (60 * 60 * 24);

        hour = difftime / (60 * 60);
        difftime %= (60 * 60);

        minute = difftime / 60;
        difftime %= 60;

        second = difftime;

        cout << day << " " << hour << " " << minute << " " << second << endl;
    }
}