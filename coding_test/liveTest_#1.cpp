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
        int r,s;
        cin >> r >> s;
        int a[r][s];
        int b[r][s];
        int result[r][s];
        for(int i = 0;i<r;i++){
            for(int j = 0;j<s;j++){
                int k;
                cin >> k;
                a[i][j] = k;
            }
        }
        for(int i = 0;i<r;i++){
            for(int j = 0;j<s;j++){
                int k;
                cin >> k;
                b[i][j] = k;
            }
        }
        for(int i = 0;i<r;i++){
            for(int j = 0;j<s;j++){
                result[i][j] = a[i][j] * b[i][j];
            }
        }
        for(int i = 0;i<r;i++){
            for(int j = 0;j<s;j++){
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
        

    }
}

/**


g++ -o test liveTest_#2.cpp  
./test


*/