#include <bits/stdc++.h>
using namespace std;
int A[10000];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }
    int maxlen = -999;
    int DP[n];
    DP[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        DP[i] = 1;
        for (int j = 0; j <= i; j++)
        {
            DP[i] = A[i] > A[j] ? max(DP[i], DP[j] + 1) : max(1, DP[i]);
        }
        maxlen = max(DP[i], maxlen);
    }
    cout << maxlen;
}