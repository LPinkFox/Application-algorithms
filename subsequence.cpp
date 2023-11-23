#include <bits/stdc++.h>
using namespace std;
int computeMaxWeight(vector<int> s, int n)
{
    int maxsub = INT_MIN;
    int maxtmp = s[0];
    for (int i = 1; i < n; ++i)
    {
        maxtmp += s[i];
        maxsub = max(maxsub, maxtmp);
        if (maxtmp < 0)
        {
            maxtmp = 0;
        }
    }
    return maxsub;
}
int main()
{
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];
    }
    cout << computeMaxWeight(s, n);
}