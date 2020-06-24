#include <iostream>
#include <string>
#include <vector>
using namespace std;

int isParenthesis(string n)
{
    int result;
    vector<char> parenthesis;
    for (int i = 0; i < n.length(); i++)
    {
        switch (n[i])
        {
        case '(':

        case '{':

        case '[':
            parenthesis.push_back(n[i]);
            break;
        case ')':
            if (parenthesis.empty())
            {
                return 0;
                break;
            }
            else
            {
                char k = parenthesis.back();
                parenthesis.pop_back();
                if (k != '(')
                {
                    return 0;
                }
                break;
            }

        case '}':
            if (parenthesis.empty())
            {
                return 0;
                break;
            }
            else
            {
                char k = parenthesis.back();
                parenthesis.pop_back();
                if (k != '{')
                {
                    return 0;
                }
                break;
            }
        case ']':
            if (parenthesis.empty())
            {
                return 0;
                break;
            }
            else
            {
                char k = parenthesis.back();
                parenthesis.pop_back();
                if (k != '[')
                {
                    return 0;
                }
                break;
            }
        }
    }
    if (parenthesis.empty())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int datacase;
    cin >> datacase;
    for (int i = 0; i < datacase; i++)
    {
        string n;
        cin >> n;
        int result = isParenthesis(n);
        cout << result << endl;
    }
}