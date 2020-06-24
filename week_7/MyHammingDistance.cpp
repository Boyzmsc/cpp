#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
#define XOR(a, b) (!(a) ^ !(b))

int getHammingWeight(int n)
{
    int count = 0;
    while(n > 1){
        if(n%2 == 1){
            count++;
        }
        n /= 2;
    }
    count ++;
    return count;
}
// comptue Hamming Distance
int getHammingDistance(int a, int b)
{
    int result;
    int n = ((a)^(b));
    result = getHammingWeight(n);
    return result;
}


int main()
{
    int numTestCases;
    cin >> numTestCases;
    for (int i = 0; i < numTestCases; i++)
    {
        int num1, num2;
        cin >> num1 >> num2;
        cout << getHammingWeight(num1) << " " << getHammingWeight(num2) << " "
             << getHammingDistance(num1,num2) << endl;
    }
    return 0;
}