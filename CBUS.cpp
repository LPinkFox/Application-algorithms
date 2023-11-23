#include <bits/stdc++.h>
using namespace std;
int n, k;
int minPath = 9999;
int tmpminPath = 0;
int smin = INT_MAX;
bool check(int i, vector<bool> &onBus, int NOB)
{
    if (onBus[i])
        return false;
    if (i <= n)
    {
        if (NOB >= k)
            return false;
    }
    else
    {
        if (!onBus[i - n])
            return false;
    }
    return true;
}
void Try(int k, int prev, vector<vector<int> > &c, vector<bool> &onBus, int NOB)
{ // NOB : number of prople on the Bus

    for (int i = 1; i <= 2 * n; ++i)
    {
        if (check(i, onBus, NOB))
        {
            onBus[i] = true;          // set position i = true
            i <= n ? NOB++ : NOB--;   // checking take or drop off passenger
            tmpminPath += c[prev][i]; // compute length path

            if (k == 2 * n)
            {
                minPath = min(tmpminPath + c[i][0], minPath);
            }
            else
            {
                if (tmpminPath + smin * (2 * n + 1 - k) < minPath)
                    Try(k + 1, i, c, onBus, NOB);
            }
            onBus[i] = false;
            i <= n ? NOB-- : NOB++;
            tmpminPath -= c[prev][i];
        }
    }
}
int main()
{
    cin >> n >> k;
    vector<vector<int> > c(2 * n + 1, vector<int>(2 * n + 1));
    for (int i = 0; i < 2 * n + 1; ++i)
    {
        for (int j = 0; j < 2 * n + 1; ++j)
        {
            cin >> c[i][j];
            smin = min(smin, c[i][j]);
        }
    }
    vector<bool> onBus(2 * n + 1, false);
    Try(1, 0, c, onBus, 0);
    cout << minPath;
}
