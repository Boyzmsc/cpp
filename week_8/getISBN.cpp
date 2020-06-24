#include <iostream>
#include <string.h>

using namespace std;

int isISBN(string s)
{
    int numOfH = 0;
    int numOfCountry = 0;
    int numOfPublisher = 0;
    int numOfBook = 0;
    int numOfCheck;
    int index = 0;
    int sum = 0;
    int sumindex = 0;

    for (int i = 0; i < s.length() - 1; i++)
    {
        if (!((s[i] >= 48 && s[i] <= 57) || s[i] == '-'))
        {
            return 0;
            break;
        }
    }

    if (s.length() - 1 - 3 > 9)
    {
        return 0;
    }

    char a = s[s.length() - 1];

    if (!((a >= 48 && a <= 57) || a == 'X'))
    {
        return 0;
    }

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '-')
        {
            numOfH++;
        }
    }
    if (numOfH != 3)
    {
        return 0;
    }

    for (int i = 0; i < s.length(); i++)
    {
        index++;
        if (s[i] == '-')
        {
            break;
        }
        numOfCountry++;
    }
    if (numOfCountry > 5 || numOfCountry == 0)
    {
        return 0;
    }

    for (int i = index; i < s.length(); i++)
    {
        index++;
        if (s[i] == '-')
        {
            break;
        }
        numOfPublisher++;
    }
    if (numOfPublisher > 7 || numOfPublisher == 0)
    {
        return 0;
    }

    for (int i = index; i < s.length(); i++)
    {
        index++;
        if (s[i] == '-')
        {
            break;
        }
        numOfBook++;
    }
    if (numOfBook > 6 || numOfBook == 0)
    {
        return 0;
    }

    if (s.length() - index != 1)
    {
        return 0;
    }

    if (s[index] == 'X')
    {
        numOfCheck = 10;
    }
    else
    {
        numOfCheck = s[index] - '0';
    }

    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == '-')
        {
            continue;
        }
        if (sumindex == 9)
        {
            break;
        }
        sum += (s[i] - '0') * (10 - sumindex);
        sumindex++;
    }

    int k = sum % 11;
    int comp = 11 - k;
    if (comp == 10)
    {
        if (s[index] != 'X')
        {
            return 0;
        }
    }
    else if (comp == 11)
    {
        if (numOfCheck != 0)
        {
            return 0;
        }
    }
    else
    {
        if (comp != numOfCheck)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int testcase;
    cin >> testcase;
    for (int i = 0; i < testcase; i++)
    {
        string isbn;
        cin >> isbn;
        int result = isISBN(isbn);
        cout << result << endl;
    }
}