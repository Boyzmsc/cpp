#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <map>

using namespace std;

int main()
{
    int testcase;
    cin >> testcase;
    for (int i = 0; i < testcase; i++)
    {
        int n, T;
        cin >> n >> T;
        char result;
        multimap<int, char> m;
        multimap<int, char>::iterator rit;
        multimap<int, char>::iterator it;
        vector<int> v;
        string s = "abcdefgfijklmnopqrstuvwxyz";

        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            m.insert(pair<int,char>(k,s[i]));
        }
        cout << "<map>" << endl;
        for(rit = m.begin();rit!=m.end();rit++){
            cout << rit->first << " : " << rit->second << endl;
        }
        cout << "-----" << endl;
        it = m.begin();
        while(T > 0){
            if(T <= it->first){
                result = it->second;
                break;
            }else{
                T -= it->first;
                it ++;
            }
        }
        cout << result << endl;
    }
}

/**


g++ -o test liveTest_#1.cpp  
./test


*/