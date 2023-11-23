#include <bits/stdc++.h>
using namespace std;
int n;
long long A[1000000];
long long DP[1000000];
int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }
    long long maxESS = -9999;
    long long zero = 0;
    DP[0] =  max(A[0], zero);
    for (int i = 1; i < n; ++i)
    {
        DP[i] = max(DP[i - 1] + A[i],zero);
        if (DP[i] % 2 == 0)
        {
            maxESS = max(DP[i], maxESS);
        }
    }
    cout << maxESS;
}
