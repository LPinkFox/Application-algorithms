#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> result;
    result.push_back({1});
    if (numRows == 1)
    {
        return result;
    }
    else
    {
        result.push_back({1, 1});
    }
    for (int i = 2; i < numRows; i++)
    {
        vector<int> temp = {};
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                temp.push_back(1);
            }
            else
            {
                temp.push_back(result[i - 1][j - 1] + result[i - 1][j]);
            }
        }
        result.push_back(temp);
    }
    return result;
}
int main()
{
    vector<vector<int>> rs = generate(5);
    for (auto i : rs)
    {
        for (int j : i)
        {
            cout << j;
        }
        cout << endl;
    }
}