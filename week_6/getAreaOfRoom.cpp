#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int datacase;
    cin >> datacase;
    for (int i = 0; i < datacase; i++)
    {
        int width, height;
        cin >> width >> height;

        string line[height];  // 라인 스트링 리스트
        vector<int> countDot; // '.' 갯수 세기
        vector<int> room;

        for (int i = 0; i < height; i++)
        {
            string s;
            cin >> s;
            line[i] = s;
        }

        countDot.push_back(0);
        for (int i = 1; i < height; i++)
        {
            int count = 0;
            for (int j = 1; j < width; j++)
            {
                if (line[i][j] == '.')
                {
                    count++;
                }
            }
            countDot.push_back(count);
        }

        int startline = 1;

        while (startline < height - 1)
        {
            if (countDot[startline] == 0)
            {
                startline++;
            }
            int roomnum = 0;
            for (int i = 1; i < height - 1; i++)
            {
                if (i == startline)
                {
                    for (int k = 1; k < width - 1; k++)
                    {
                        if (line[startline][k] == '.' && line[startline][k + 1] == '+')
                        {
                            for (int j = k; k > 0; k--)
                            {
                                if (line[startline][k] == '+')
                                {
                                    break;
                                }
                                else
                                {
                                    line[startline][k] = '*';
                                    countDot[startline]--;
                                    roomnum++;
                                }
                            }
                            break;
                        }
                    }
                }
                else
                {
                    for (int k = 1; k < width - 1; k++)
                    {
                        if (line[i][k] == '.' && line[i - 1][k] == '*')
                        {
                            for (int q = k; q < width - 1; q++)
                            {
                                if (line[i][q] == '.' && line[i][q + 1] == '+')
                                {
                                    line[i][q] = '*';
                                    countDot[i]--;
                                    roomnum++;
                                    break;
                                }
                                line[i][q] = '*';
                                countDot[i]--;
                                roomnum++;
                            }
                            for (int q = k - 1; q > 0; q--)
                            {
                                if (line[i][q] == '+')
                                {
                                    break;
                                }
                                line[i][q] = '*';
                                countDot[i]--;
                                roomnum++;
                            }
                        }
                    }
                }
            }
            bool roop1 = true;
            bool roop2 = true;
            while (roop1 || roop2)
            {
                roop1 = false;
                roop2 = false;
                for (int i = height - 2; i > 0; i--)
                {
                    for (int k = 1; k < width - 1; k++)
                    {
                        if (line[i][k] == '.' && line[i + 1][k] == '*')
                        {
                            roop1 = true;
                            break;
                        }
                    }
                    if (roop1)
                    {
                        break;
                    }
                }
                for (int i = height - 2; i > 0; i--)
                {
                    for (int k = 1; k < width - 1; k++)
                    {
                        if (line[i][k] == '.' && line[i + 1][k] == '*')
                        {
                            for (int q = k; q < width - 1; q++)
                            {
                                if (line[i][q] == '.' && line[i][q + 1] == '+')
                                {
                                    line[i][q] = '*';
                                    countDot[i]--;
                                    roomnum++;

                                    break;
                                }
                                line[i][q] = '*';
                                countDot[i]--;
                                roomnum++;
                            }
                            for (int q = k - 1; q > 0; q--)
                            {
                                if (line[i][q] == '+')
                                {
                                    break;
                                }
                                line[i][q] = '*';
                                countDot[i]--;
                                roomnum++;
                            }
                        }
                    }
                }
                for (int i = 1; i < height - 1; i++)
                {
                    for (int k = 1; k < width - 1; k++)
                    {
                        if (line[i][k] == '.' && line[i - 1][k] == '*')
                        {
                            roop2 = true;
                            break;
                        }
                    }
                    if (roop2)
                    {
                        break;
                    }
                }
                for (int i = 1; i < height - 1; i++)
                {
                    for (int k = 1; k < width - 1; k++)
                    {
                        if (line[i][k] == '.' && line[i - 1][k] == '*')
                        {
                            for (int q = k; q < width - 1; q++)
                            {
                                if (line[i][q] == '.' && line[i][q + 1] == '+')
                                {
                                    line[i][q] = '*';
                                    countDot[i]--;
                                    roomnum++;
                                    break;
                                }
                                line[i][q] = '*';
                                countDot[i]--;
                                roomnum++;
                            }
                            for (int q = k - 1; q > 0; q--)
                            {
                                if (line[i][q] == '+')
                                {
                                    break;
                                }
                                line[i][q] = '*';
                                countDot[i]--;
                                roomnum++;
                            }
                        }
                    }
                }
            }

            if (roomnum == 0)
            {
                continue;
            }
            else
            {
                room.push_back(roomnum);
            }
        }

        cout << room.size() << endl;
        sort(room.begin(), room.end());
        for (int i = room.size() - 1; i >= 0; i--)
        {
            cout << room[i] << " ";
        }
        cout << endl;
    }
}