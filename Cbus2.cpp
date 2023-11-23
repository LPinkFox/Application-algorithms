#include <bits/stdc++.h>
using namespace std;

int n, k;
int minPath = 9999;
int tmpminPath = 0;

bool check(int i, const vector<bool> &onBus, int NOB)
{
    if (onBus[i] || (i <= n && NOB >= k) || (i > n && !onBus[i - n]))
        return false;

    return true;
}

void Try(int k, int prev, vector<vector<int>> &c, vector<bool> &onBus, int NOB)
{
    if (tmpminPath > minPath)
        return;
    for (int i = 1; i <= 2 * n; ++i)
    {
        if (check(i, onBus, NOB))
        {
            int distance = tmpminPath + c[prev][i];
            onBus[i] = true;
            i <= n ? NOB++ : NOB--;
            tmpminPath += c[prev][i];

            if (k == 2 * n)
                minPath = min(distance + c[i][0], minPath);
            else
                Try(k + 1, i, c, onBus, NOB);

            onBus[i] = false;
            i <= n ? NOB-- : NOB++;
            tmpminPath -= c[prev][i];
        }
    }
}

int main()
{
    cin >> n >> k;
    int size = 2 * n + 1;
    vector<vector<int>> c(size, vector<int>(size));

    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            cin >> c[i][j];

    vector<bool> onBus(size, false);
    Try(1, 0, c, onBus, 0);
    cout << minPath;
}
