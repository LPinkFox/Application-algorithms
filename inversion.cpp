#include <bits/stdc++.h>
using namespace std;
int n, Q;
int A[100001];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[i])
            {
                Q++;
            }
        }
    }
    cout << Q;
}