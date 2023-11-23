#include <bits/stdc++.h>
using namespace std;
int n;
int cResult = 0;
bool check(int row, int col, vector<int> filled)
{
    for (int i = 0; i < n; i++)
    {
        if (filled[i] != -1)
        {
            if (filled[i] == col || abs(row - i) == abs(filled[i] - col))
            {
                return false;
            }
        }
    }
    return true;
}
void Try(int k, vector<int> &filled)
{
    if (k == n)
    {
        cResult++;
    }
    else if (filled[k] != -1)
    {
        Try(k + 1, filled);
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            if (check(k, i, filled))
            {
                filled[k] = i;
                Try(k + 1, filled);
                filled[k] = -1;
            }
        }
    }
}
int main()
{
    cin >> n;
    vector<int> filled(n, -1);
    int tmp;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> tmp;
            if (tmp == 1)
            {
                filled[i] = j; // da dat hau o row i, col j
            }
        }
    }
    Try(0, filled);
    cout << cResult;
}