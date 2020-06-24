#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>
using namespace std;
unsigned long getNumOfIPv4(string s){
    unsigned long sum = 0;
    vector<string> a;
    size_t previous = 0, current;
    current = s.find('.');
    while(current != string::npos){
        string sub = s.substr(previous,current-previous);
        a.push_back(sub);
        previous = current+1;
        current = s.find('.',previous);
    }
    a.push_back(s.substr(previous,current-previous));
    for(int i = 0;i<a.size();i++){
        unsigned long k = stoi(a[i]);
        sum += k * pow(256,a.size()-i-1);
    }
    return sum;
}
string getIPv4OfNum(unsigned long n){
    string result = "0.0.0.0";
    int idx = 6;
    while(n >= 1){
        string k= to_string(n % 256);
        result.replace(idx,1,k);
        idx -= 2;
        n /= 256;
    }
    return result;
}


int main()
{
    int testcase;
    cin >> testcase;
    for (int i = 0; i < testcase; i++)
    {
        int num;
        cin >> num;
        if(num == 1){
            string s;
            cin >> s;
            cout << getNumOfIPv4(s) << endl;
        }else if(num == 2){
            unsigned long n;
            cin >> n;
            cout << getIPv4OfNum(n) << endl;
        }

    }
}