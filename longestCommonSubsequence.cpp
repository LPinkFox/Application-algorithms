#include <bits/stdc++.h>
using namespace std;
int n, m;
int DP[10001][10001];
int X[10001], Y[10001];
int main()
{
    cin >> n >> m;
    int i, j;
    for (i = 1; i <= n; ++i)
    {
        cin >> X[i];
    }
    for (i = 1; i <= m; ++i)
    {
        cin >> Y[i];
    }

    for (i = 0; i <= m; i++)
    {
        DP[0][i] = 0;
    }
    for (i = 0; i <= n; i++)
    {
        DP[i][0] = 0;
    }
    int maxLCS = -9999;

    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= m; j++)
        {
            if (X[i] == Y[j])
            {
                DP[i][j] = DP[i - 1][j - 1] + 1;
            }
            else
            {
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
            maxLCS = max(DP[i][j], maxLCS);
        }
    }
    cout << maxLCS;
}