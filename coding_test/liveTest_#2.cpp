#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
// 문자를 숫자로 바꿀때, stoi or s - '0'
using namespace std;
int main()
{
    int testcase;
    cin >> testcase;
    for (int i = 0; i < testcase; i++)
    {
        string n, m;
        cin >> n >> m;
        vector<char> v;
        vector<char> k;
        vector<char> bv;
        vector<char> bk;

        for (int i = 0; i < n.length(); i++)
        {
            v.push_back(n[i]);
            k.push_back(m[i]);
            bv.push_back(n[i]);
            bk.push_back(m[i]);
        }
        int strike = 0;
        int ball = 0;
        bool isClear = true;
        for (int i = 0; i < k.size(); i++)
        {
            for (int j = 0; j < k.size(); j++)
            {
                if (v[i] == k[j] && i == j)
                {
                    strike++;
                    bk[i] = 'x';
                    bv[i] = 'x';
                    break;
                }
            }
        }
        for(int i = 0;i<bk.size();i++){
            if(bk[i] != 'x'){
                isClear = false;
            }
        }
        if (!isClear)
        {
            for (int i = 0; i < bk.size(); i++)
            {
                for (int j = 0; j < bk.size(); j++)
                {
                    if (bv[i] == bk[j] && bv[i] != 'x')
                    {
                        ball++;
                        bk[j] = 'x';
                        break;
                    }
                }
            }
        }
        else
        {
            strike = 4;
            ball = 4;
        }

        cout << strike << " " << ball << endl;
    }
}

/**


g++ -o test liveTest_#3.cpp  
./test


*/